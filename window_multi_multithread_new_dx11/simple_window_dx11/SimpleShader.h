#pragma once
#include <d3d11.h>
#include <d3dx11async.h>
#include <fstream>

class SimpleShader
{
public:
	SimpleShader();
	~SimpleShader();
	bool init(ID3D11Device* device);
	void stop();
	void render(ID3D11DeviceContext *deviceContext);

private:
	bool initShader(ID3D11Device* device, WCHAR* vsFilename, WCHAR* psFilename);
	void stopShader();
	void renderShader(ID3D11DeviceContext *deviceContext);

private:
	ID3D11VertexShader *m_vertexShader;
	ID3D11PixelShader *m_pixelShader;
	ID3D11InputLayout *m_layout;
};