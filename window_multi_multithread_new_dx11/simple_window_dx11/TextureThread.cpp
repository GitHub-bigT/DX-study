#include "TextureThread.h"

TextureThread::TextureThread(int gpu, WindowData &wd, QVector<WindowData> &wdVec)
{
	m_D3D11Class = 0;
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

	m_D3D11Class = new D3D11Class;
	m_D3D11Class->init();

	m_TextureClass = new TextureClass;
	m_TextureClass->init(m_D3D11Class->getDevice(), "../../source_image/3840x2160.png");

	for (int i = 0; i < m_WindowVec.size(); i++)
	{
		WindowData wd = m_WindowVec.at(i);
		if (wd.gpu == m_Gpu)
		{
			RenderThread *rt = new RenderThread(this, wd);
			m_RenderThreadVector.push_back(rt);
		}
	}
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
	if (m_D3D11Class)
	{
		m_D3D11Class->stop();
		delete m_D3D11Class;
		m_D3D11Class = 0;
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

		for (int i = 0; i < m_CommandLists.size(); i++)
		{
			ID3D11CommandList *l = m_CommandLists.at(i);
			m_D3D11Class->getImmediateDeviceContext()->ExecuteCommandList(l, 0);
			l->Release();
		}
		m_CommandLists.clear();

		//Sleep(15);

		setSwapSemaphore(m_RenderThreadVector.size());

		getSwapDoneSemaphore(m_RenderThreadVector.size());
	}

	stopRenderThread();

}

D3D11Class* TextureThread::getD3D11Class()
{
	return m_D3D11Class;
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

void TextureThread::addCommandList(ID3D11CommandList *l)
{
	mtx.lock();
	m_CommandLists.push_back(l);
	mtx.unlock();
}

ID3D11ShaderResourceView* TextureThread::getSrv()
{
	return m_TextureClass->getSrv();
}