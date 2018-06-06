#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <iostream>

using namespace DirectX;

class TextureShaderClass
{
public:
	TextureShaderClass();
	~TextureShaderClass();
	bool init(ID3D11Device*, HWND);
	void stop();
	bool render(ID3D11DeviceContext*, int, ID3D11ShaderResourceView*);

private:
	bool initShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
	void stopShader();
	void renderShader(ID3D11DeviceContext*, int, ID3D11ShaderResourceView*);
	void outputShaderErrorMsg(ID3D10Blob* errorMessage, HWND hwnd, WCHAR* shaderFilename);
private:
	ID3D11VertexShader *m_vertexShader;
	ID3D11PixelShader *m_pixelShader;
	ID3D11InputLayout *m_inputLayout;
	ID3D11SamplerState *m_sampleState;
};