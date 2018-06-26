#pragma once
#include "D3DClass.h"
#include "TextClass.h"
#include "ModelClass.h"
#include "CameraClass.h"
#include "TextureShaderClass.h"

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
	bool renderSystemInfoFont(int, int, float);
	bool renderScene();

private:
	D3DClass *m_direct3D;
	TextClass *m_fpsTextClass;
	TextClass *m_cpuTextClass;
	TextClass *m_frametimeTextClass;
	ModelClass *m_modelClass;
	CameraClass *m_cameraClass;
	TextureShaderClass *m_textureShaderClass;
};