#pragma once
#include "D3DClass.h"
#include "TextClass.h"

const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = false;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsClass
{
public:
	GraphicsClass();
	~GraphicsClass();
	bool init(int, int, HWND);
	void stop();
	bool frame(int, int, float);

private:
	bool render(int, int, float);

private:
	D3DClass *m_direct3D;
	TextClass *m_fpsTextClass;
	TextClass *m_cpuTextClass;
	TextClass *m_frametimeTextClass;
};