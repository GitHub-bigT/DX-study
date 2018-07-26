#include "RenderThread.h"
#include "TextureThread.h"

RenderThread::RenderThread(TextureThread *t, WindowData &wd)
{
	m_Graphics = 0;
	m_TextureView = 0;
	m_ShareHandle = 0;
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

	m_Graphics = new GraphicsClass;
	result = m_Graphics->init(m_WindowData.width, m_WindowData.height, m_WindowData.hwnd);
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
	if (m_Graphics)
	{
		m_Graphics->stop();
		delete m_Graphics;
		m_Graphics = 0;
	}
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

		HRESULT hr;

		ID3D11Texture2D *m_texture = NULL;
		m_ShareHandle = m_TextureThread->getShareHandle();
		m_Graphics->getDevice()->OpenSharedResource(m_ShareHandle, __uuidof(ID3D11Texture2D), (void**)&m_texture);

		D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
		srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
		srvDesc.Texture2D.MostDetailedMip = 0;
		srvDesc.Texture2D.MipLevels = 1;
		hr = m_Graphics->getDevice()->CreateShaderResourceView(m_texture, &srvDesc, &m_TextureView);

		m_Graphics->render(m_TextureView);

		m_TextureThread->setTextureDoneSemaphore();

		m_TextureThread->getSwapSemaphore();

		m_Graphics->swap();

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