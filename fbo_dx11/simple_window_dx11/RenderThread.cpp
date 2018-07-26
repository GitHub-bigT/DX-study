#include "RenderThread.h"
#include "TextureThread.h"

RenderThread::RenderThread(TextureThread *t, WindowData &wd)
{
	m_D3D11 = 0;
	m_Quad = 0;
	m_TextureShader = 0;
	m_SimpleShader = 0;
	m_TextureView = 0;
	m_FboTextureView = 0;
	nullSRV[0] = NULL;
	m_ShareHandle = 0;
	m_RenderTextureClass = 0;
	m_TextureThread = t;
	m_WindowData = wd;
	printf("window number = %d\n", m_WindowData.number);
	this->start();
}

RenderThread::~RenderThread()
{
}

bool RenderThread::init()
{
	bool result;
	m_Run = true;

	m_D3D11 = new D3DClass;
	if (!m_D3D11)
	{
		return false;
	}
	result = m_D3D11->init(m_WindowData.width, m_WindowData.height, m_WindowData.vsync, m_WindowData.hwnd);
	if (!result)
	{
		return false;
	}

	m_RenderTextureClass = new RenderTextureClass;
	result = m_RenderTextureClass->init(m_D3D11->getDevice(), m_WindowData.width, m_WindowData.height);
	if (!result)
	{
		return false;
	}

	m_Quad = new QuadClass;
	result = m_Quad->init(m_D3D11->getDevice());
	if (!result)
	{
		return false;
	}

	m_TextureShader = new TextureShader;
	result = m_TextureShader->init(m_D3D11->getDevice());
	if (!result)
	{
		return false;
	}

	m_SimpleShader = new SimpleShader;
	result = m_SimpleShader->init(m_D3D11->getDevice());
	if (!result)
	{
		return false;
	}

	return true;
}

void RenderThread::stop()
{
	m_Run = false;
}

void RenderThread::releaseResource()
{
	if (m_D3D11)
	{
		m_D3D11->stop();
		delete m_D3D11;
		m_D3D11 = 0;
	}

	if (m_Quad)
	{
		m_Quad->stop();
		delete m_Quad;
		m_Quad = 0;
	}

	if (m_TextureShader)
	{
		m_TextureShader->stop();
		delete m_TextureShader;
		m_TextureShader = 0;
	}

	if (m_SimpleShader)
	{
		m_SimpleShader->stop();
		delete m_SimpleShader;
		m_SimpleShader = 0;
	}

	if (m_RenderTextureClass)
	{
		m_RenderTextureClass->stop();
		delete m_RenderTextureClass;
		m_RenderTextureClass = 0;
	}
}

void RenderThread::getShareTexture()
{
	HRESULT hr;

	ID3D11Texture2D *m_texture = NULL;
	m_ShareHandle = m_TextureThread->getShareHandle();
	m_D3D11->getDevice()->OpenSharedResource(m_ShareHandle, __uuidof(ID3D11Texture2D), (void**)&m_texture);

	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MostDetailedMip = 0;
	srvDesc.Texture2D.MipLevels = 1;

	if (m_TextureView)
	{
		m_TextureView->Release();
		m_TextureView = 0;
	}

	hr = m_D3D11->getDevice()->CreateShaderResourceView(m_texture, &srvDesc, &m_TextureView);
}

void RenderThread::run()
{
	init();

	while (m_Run)
	{
		m_TextureThread->getTextureSemaphore();

		if (!m_Run)
		{
			break;
		}

		getShareTexture();

		render();
		//renderWithFbo();

		m_TextureThread->setTextureDoneSemaphore();

		m_TextureThread->getSwapSemaphore();

		swap();

		m_TextureThread->setSwapDoneSemaphore();
	}

	releaseResource();
	printf("stop render thread num = %d\n", m_WindowData.number);
	/*MSG msg;
	bool done, result;

	// Initialize the message structure.
	ZeroMemory(&msg, sizeof(MSG));

	// Loop until there is a quit message from the window or the user.
	done = false;
	while (!done)
	{
		// Handle the windows messages.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// If windows signals to end the application then exit out.
		if (msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			// Otherwise do the frame processing.
			result = frame();
			if (!result)
			{
				done = true;
			}
		}
	}*/
}

void RenderThread::render()
{
	//pass 1
	m_D3D11->setBackBufferRenderTarget();

	m_D3D11->beginScene(1.0f, 1.0f, 0.0f, 1.0f);

	m_D3D11->setViewPort(0, 0, m_WindowData.width / 2, m_WindowData.height / 2);

	m_D3D11->getDeviceContext()->PSSetShaderResources(0, 1, &m_TextureView);

	m_TextureShader->render(m_D3D11->getDeviceContext());

	m_Quad->render(m_D3D11->getDeviceContext());

	//pass 2
	m_D3D11->setViewPort(200, 200, m_WindowData.width / 2, m_WindowData.height / 2);

	m_D3D11->getDeviceContext()->PSSetShaderResources(0, 1, nullSRV);

	m_Quad->render(m_D3D11->getDeviceContext());
}

void RenderThread::renderWithFbo()
{
	//pass 1
	m_RenderTextureClass->SetRenderTarget(m_D3D11->getDeviceContext(), m_D3D11->getDepthStencilView());

	m_D3D11->setViewPort(0, 0, m_WindowData.width / 2, m_WindowData.height / 2);

	m_RenderTextureClass->ClearRenderTarget(m_D3D11->getDeviceContext(), m_D3D11->getDepthStencilView(), 1.0f, 0.0f, 0.0f, 1.0f);

	m_D3D11->getDeviceContext()->PSSetShaderResources(0, 1, &m_TextureView);

	m_TextureShader->render(m_D3D11->getDeviceContext());

	m_Quad->render(m_D3D11->getDeviceContext());

	//pass 2

	m_D3D11->setBackBufferRenderTarget();

	m_D3D11->setViewPort(200, 200, m_WindowData.width / 2, m_WindowData.height / 2);

	m_D3D11->beginScene(1.0f, 1.0f, 0.0f, 1.0f);

	m_FboTextureView = m_RenderTextureClass->GetShaderResourceView();
	m_D3D11->getDeviceContext()->PSSetShaderResources(0, 1, &m_FboTextureView);

	m_D3D11->getDeviceContext()->PSSetShaderResources(0, 0, NULL);

	m_Quad->render(m_D3D11->getDeviceContext());
}

void RenderThread::swap()
{
	m_D3D11->endScene();
}