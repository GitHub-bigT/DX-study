#pragma once
#include "D3DClass.h"
#include "ColorShaderClass.h"
#include "ModelClass.h"
#include "CameraClass.h"

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
	bool frame();

private:
	bool render();

private:
	D3DClass *m_direct3D;
	ColorShaderClass *m_colorShader;
	ModelClass *m_model;
	CameraClass *m_camera;
};