#pragma once
#include "D3DClass.h"
#include "ModelClass.h"
#include "SimpleShader.h"

const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsClass
{
public:
	GraphicsClass();
	~GraphicsClass();
	bool init(int, int, HWND);
	void stop();
	bool render(ID3D11ShaderResourceView *tex = NULL);
	bool swap();

	ID3D11Device* getDevice();
	ID3D11DeviceContext* getDeviceContext();

private:

private:
	D3DClass *m_direct3D;
	ModelClass *m_ModelClass;
	SimpleShader *m_SimpleShader;
};