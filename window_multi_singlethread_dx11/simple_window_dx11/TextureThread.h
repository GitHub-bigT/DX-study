#pragma once
#include <windows.h>
#include <QThread>
#include <QVector>
#include <QSemaphore>

#include "GraphicsClass.h"

class TextureThread : public QThread
{
public:

	TextureThread(int gpu, QVector<WindowData> &wdv);
	~TextureThread();

	void stop();
	void run();

private:
	void init();
	void releaseResource();

public:

private:
	int m_Gpu;
	bool m_Run;
	QVector<WindowData> m_WindowDataVec;
	GraphicsClass *m_Graphics;
};