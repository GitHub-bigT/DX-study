#pragma once
#define  WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <QThread>

#include "D3DClass.h"
#include "TextureShader.h"
#include "SimpleShader.h"
#include "QuadClass.h"
#include "TextureClass.h"
#include "RenderTextureClass.h"

struct WindowData
{
	int x;
	int y;
	int width;
	int height;
	int gpu;
	int number;
	HWND hwnd;
	bool vsync;
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
	void render();
	void renderWithFbo();
	void swap();
	void getShareTexture();
	void releaseResource();

private:
	bool m_Run;
	WindowData m_WindowData;
	D3DClass *m_D3D11;
	QuadClass *m_Quad;
	TextureShader *m_TextureShader;
	SimpleShader *m_SimpleShader;
	TextureThread *m_TextureThread;
	HANDLE m_ShareHandle;
	ID3D11ShaderResourceView* nullSRV[1];
	ID3D11ShaderResourceView *m_TextureView;
	ID3D11ShaderResourceView *m_FboTextureView;
	RenderTextureClass *m_RenderTextureClass;
};