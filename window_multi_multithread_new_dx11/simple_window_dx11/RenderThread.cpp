#include "RenderThread.h"
#include "TextureThread.h"

RenderThread::RenderThread(TextureThread *t, WindowData &wd)
{
	m_DeferredContext = 0;
	m_Device = 0;
	m_FrameBufferClass = 0;
	m_StateManager = 0;
	m_CommandList = 0;
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

	m_Device = m_TextureThread->getD3D11Class()->getDevice();
	m_Device->CreateDeferredContext(0, &m_DeferredContext);

	m_FrameBufferClass = new FrameBufferClass;
	m_FrameBufferClass->init(m_Device, m_WindowData.width, m_WindowData.height, false, false, m_WindowData.hwnd);

	m_StateManager = new StateManager;
	m_StateManager->init(m_Device);

	m_ModelClass = new ModelClass;
	result = m_ModelClass->init(m_Device);
	if (!result)
	{
		return false;
	}

	m_SimpleShader = new SimpleShader;
	result = m_SimpleShader->init(m_Device);
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
	if (m_DeferredContext)
	{
		m_DeferredContext->Release();
		m_DeferredContext = 0;
	}
}


void RenderThread::run()
{
	init();

	while (m_Run)
	{
		//m_TextureThread->getTextureSemaphore();

		if (!m_Run)
		{
			break;
		}

		HRESULT hr;

		m_FrameBufferClass->setRenderTarget(m_DeferredContext);

		m_FrameBufferClass->beginScene(m_DeferredContext, 0.0, 1.0, 0.0, 1.0);

		m_TextureThread->getD3D11Class()->setViewport(m_DeferredContext, 0, 0, m_WindowData.width / 2, m_WindowData.height / 2);

		m_StateManager->turnOnAlphaBlending(m_DeferredContext);

		m_StateManager->turnZBufferOff(m_DeferredContext);

		ID3D11ShaderResourceView *tex = m_TextureThread->getSrv();
		m_DeferredContext->PSSetShaderResources(0, 1, &tex);

		m_SimpleShader->render(m_DeferredContext);

		m_ModelClass->render(m_DeferredContext);

		m_DeferredContext->FinishCommandList(0, &m_CommandList);

		if (m_CommandList)
			m_TextureThread->addCommandList(m_CommandList);

		m_TextureThread->setTextureDoneSemaphore();

		m_TextureThread->getSwapSemaphore();

		m_FrameBufferClass->endScene();

		m_TextureThread->setSwapDoneSemaphore();
	}

	releaseResource();
	printf("stop render thread num = %d\n", m_WindowData.number);
}