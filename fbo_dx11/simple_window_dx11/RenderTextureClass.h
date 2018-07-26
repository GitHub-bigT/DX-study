#pragma once
#include <d3d11.h>

class RenderTextureClass
{
public:
	RenderTextureClass();
	~RenderTextureClass();

	bool init(ID3D11Device *device, int w, int h);
	void stop();

	void SetRenderTarget(ID3D11DeviceContext *device, ID3D11DepthStencilView *depthStencilView);
	void ClearRenderTarget(ID3D11DeviceContext *deviceContext, ID3D11DepthStencilView *depthStencilView, float red, float green, float blue, float alpha);
	ID3D11ShaderResourceView* GetShaderResourceView();

private:
	ID3D11Texture2D* m_RenderTargetTexture;
	ID3D11RenderTargetView* m_RenderTargetView;
	ID3D11ShaderResourceView* m_ShaderResourceView;
};