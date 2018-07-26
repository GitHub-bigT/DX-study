#include "TextureThread.h"

TextureThread::TextureThread(int gpu, QVector<WindowData> &wdv)
{
	m_Graphics = 0;
	m_WindowDataVec = wdv;
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
	m_Graphics = new GraphicsClass;
	m_Graphics->init(m_WindowDataVec);
}

void TextureThread::stop()
{
	m_Run = false;
	this->wait();
}

void TextureThread::releaseResource()
{
	if (m_Graphics)
	{
		m_Graphics->stop();
		delete m_Graphics;
		m_Graphics = 0;
	}
}

void TextureThread::run()
{

	init();

	while (m_Run)
	{
		m_Graphics->render();

		m_Graphics->swap();
	}

}