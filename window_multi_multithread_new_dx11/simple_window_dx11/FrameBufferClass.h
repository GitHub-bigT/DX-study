#pragma once
#include <d3d11.h>
#include <iostream>

class FrameBufferClass
{
public:
	FrameBufferClass();
	~FrameBufferClass();
	bool init(ID3D11Device *device, int screenWidth, int screenHeight, bool vsync, bool msaa, HWND hwnd);
	void stop();
	void beginScene(ID3D11DeviceContext *deviceContext, float red, float green, float blue, float alpha);
	void endScene();

	void setRenderTarget(ID3D11DeviceContext *deviceContext);
	ID3D11DepthStencilView* getDepthStencilView();

private:
	bool initSwapChain();
	bool initRenderTarget();
	bool initDepthStencil();

private:
	bool m_VsyncEnabled;
	HWND m_Hwnd;
	bool m_x4Msaa;
	UINT m_x4MsaaQuality;
	unsigned int m_SampleCount;
	int m_ScreenWidth, m_ScreenHeight;

	ID3D11Device *m_Device;
	IDXGISwapChain *m_SwapChain;
	ID3D11RenderTargetView *m_RenderTargetView;
	ID3D11DepthStencilView *m_DepthStencilView;
	ID3D11Texture2D *m_DepthStencilBuffer;
};