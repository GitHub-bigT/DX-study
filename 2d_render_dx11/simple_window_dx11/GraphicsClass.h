#pragma once
#include "D3DClass.h"
#include "TextureShaderClass.h"
#include "BitmapClass.h"
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
	TextureShaderClass *m_textureShader;
	ModelClass *m_bitmap;
	CameraClass *m_camera;
};