#pragma once
#include <d3d11.h>
#include <iostream>

class StateManager
{
public:
	StateManager();
	~StateManager();
	bool init(ID3D11Device *device);
	void stop();

	void turnZBufferOn(ID3D11DeviceContext *deviceContext);
	void turnZBufferOff(ID3D11DeviceContext *deviceContext);

	void turnOnAlphaBlending(ID3D11DeviceContext *deviceContext);
	void turnOffAlphaBlending(ID3D11DeviceContext *deviceContext);

private:
	ID3D11DepthStencilState *m_DepthStencilState;
	ID3D11DepthStencilState *m_DepthDisabledStencilState;
	ID3D11BlendState *m_AlphaEnableBlendState;
	ID3D11BlendState *m_AlphaDisableBlendState;
	ID3D11RasterizerState *m_RasterState;
};