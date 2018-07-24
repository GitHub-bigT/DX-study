#pragma once
#include <QThread>
#include <QVector>
#include <QSemaphore>
#include "RenderThread.h"

class TextureThread : public QThread
{
public:

	TextureThread(int gpu, WindowData &wd, QVector<WindowData> &wdVec);
	~TextureThread();

	void stop();
	void run();

	void setTextureSemaphore(int n = 1);
	void getTextureSemaphore(int n = 1);
	void setTextureDoneSemaphore(int n = 1);
	void getTextureDoneSemaphore(int n = 1);
	void setSwapSemaphore(int n = 1);
	void getSwapSemaphore(int n = 1);
	void setSwapDoneSemaphore(int n = 1);
	void getSwapDoneSemaphore(int n = 1);

private:
	void init();
	void stopRenderThread();
	void releaseResource();

public:

private:
	int m_Gpu;
	bool m_Run;
	WindowData m_WindowData;
	QVector<WindowData> m_WindowVec;
	QVector<RenderThread*> m_RenderThreadVector;
	QSemaphore m_TextureSemaphore, m_TextureDoneSemaphore;
	QSemaphore m_SwapSemaphore, m_SwapDoneSemaphore;
	GraphicsClass *m_Graphics;
};