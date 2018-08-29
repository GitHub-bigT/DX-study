#pragma once
#define  WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <QThread>

#include "FrameBufferClass.h"
#include "StateManager.h"
#include "ModelClass.h"
#include "SimpleShader.h"
#include "TextureClass.h"
#include "D3DClass.h"

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
	ID3D11Device *m_Device;
	ID3D11DeviceContext *m_DeferredContext;
	TextureThread *m_TextureThread;
	ModelClass *m_ModelClass;
	SimpleShader *m_SimpleShader;
	FrameBufferClass *m_FrameBufferClass;
	StateManager *m_StateManager;
	ID3D11CommandList *m_CommandList;
	//HANDLE m_ShareHandle;
	//ID3D11ShaderResourceView *m_TextureView;
};