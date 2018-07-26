#pragma once
#define  WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <QThread>

#include "GraphicsClass.h"
#include "TextureClass.h"

struct WindowData
{
	int x;
	int y;
	int width;
	int height;
	int gpu;
	int number;
	HWND hwnd;
	LPCWSTR applicationName;
	HINSTANCE hinstance;
};

class TextureThread;
class RenderThread : public QThread
{
public:

public:
	RenderThread(TextureThread *t, WindowData &wd);
	~RenderThread();

	void stop();
	void run();

private:
	bool init();
	void releaseResource();

private:
	bool m_Run;
	WindowData m_WindowData;
	GraphicsClass *m_Graphics;
	TextureThread *m_TextureThread;
	HANDLE m_ShareHandle;
	ID3D11ShaderResourceView *m_TextureView;
};