#include "TextureThread.h"

TextureThread::TextureThread(int gpu, WindowData &wd, QVector<WindowData> &wdVec)
{
	m_D3D11 = 0;
	m_TextureClass = 0;
	m_WindowData = wd;
	m_WindowVec = wdVec;
	m_Gpu = gpu;
	printf("texture thread gpu = %d\n", m_Gpu);
	this->start();
}

TextureThread::~TextureThread()
{
}

void TextureThread::init()
{
	m_Run = true;
	for (int i = 0; i < m_WindowVec.size(); i++)
	{
		WindowData wd = m_WindowVec.at(i);
		if (wd.gpu == m_Gpu)
		{
			RenderThread *rt = new RenderThread(this, wd);
			m_RenderThreadVector.push_back(rt);
		}
	}

	m_D3D11 = new D3DClass;
	m_D3D11->init(m_WindowData.width, m_WindowData.height, m_WindowData.vsync, m_WindowData.hwnd);

	m_TextureClass = new TextureClass;
	m_TextureClass->init(m_D3D11->getDevice(), m_D3D11->getDeviceContext(), "../../source_image/container2.png");
}

void TextureThread::stop()
{
	m_Run = false;
	this->wait();
}

void TextureThread::stopRenderThread()
{
	
	for (int i = 0; i < m_RenderThreadVector.size(); i++)
	{
		RenderThread *rt = m_RenderThreadVector.at(i);
		rt->stop();
	}

	setTextureSemaphore(m_RenderThreadVector.size());

	for (int i = 0; i < m_RenderThreadVector.size(); i++)
	{
		RenderThread *rt = m_RenderThreadVector.at(i);
		rt->wait();
		delete rt;
	}
	m_RenderThreadVector.clear();
}

void TextureThread::releaseResource()
{
	if (m_D3D11)
	{
		m_D3D11->stop();
		delete m_D3D11;
		m_D3D11 = 0;
	}

	if (m_TextureClass)
	{
		m_TextureClass->stop();
		delete m_TextureClass;
		m_TextureClass = 0;
	}
}

void TextureThread::run()
{

	init();

	while (m_Run)
	{
		//get texture


		setTextureSemaphore(m_RenderThreadVector.size());

		getTextureDoneSemaphore(m_RenderThreadVector.size());

		//Sleep(15);

		setSwapSemaphore(m_RenderThreadVector.size());

		getSwapDoneSemaphore(m_RenderThreadVector.size());
	}

	stopRenderThread();

}

void TextureThread::setTextureDoneSemaphore(int n)
{
	m_TextureDoneSemaphore.release(n);
}

void TextureThread::getTextureDoneSemaphore(int n)
{
	m_TextureDoneSemaphore.acquire(n);
}

void TextureThread::setTextureSemaphore(int n)
{
	m_TextureSemaphore.release(n);
}

void TextureThread::getTextureSemaphore(int n)
{
	m_TextureSemaphore.acquire(n);
}

void TextureThread::setSwapSemaphore(int n)
{
	m_SwapSemaphore.release(n);
}

void TextureThread::getSwapSemaphore(int n)
{
	m_SwapSemaphore.acquire(n);
}

void TextureThread::setSwapDoneSemaphore(int n)
{
	m_SwapDoneSemaphore.release(n);
}

void TextureThread::getSwapDoneSemaphore(int n)
{
	m_SwapDoneSemaphore.acquire(n);
}

HANDLE TextureThread::getShareHandle()
{
	return m_TextureClass->getShareHandle();
}