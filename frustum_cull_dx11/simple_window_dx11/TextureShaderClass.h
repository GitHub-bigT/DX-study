#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <d3dx11async.h>
#include <iostream>
using namespace DirectX;
using namespace std;

class TextureShaderClass
{
private:
	struct MatrixBufferType
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};

public:
	TextureShaderClass();
	~TextureShaderClass();

	bool init(ID3D11Device*, HWND);
	bool render(ID3D11DeviceContext*, int, XMMATRIX, XMMATRIX, XMMATRIX, XMFLOAT4, ID3D11ShaderResourceView*);
	void stop();

private:
	bool initShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
	void renderShader(ID3D11DeviceContext*, int, ID3D11ShaderResourceView*);
	void outputShaderErrorMsg(ID3D10Blob* errorMessage, HWND hwnd, WCHAR* shaderFilename);
	bool setShaderParameters(ID3D11DeviceContext*, XMMATRIX, XMMATRIX, XMMATRIX, XMFLOAT4);

private:
	ID3D11VertexShader *m_vertexShader;
	ID3D11PixelShader *m_pixelShader;
	ID3D11InputLayout *m_inputLayout;
	ID3D11SamplerState *m_sampleState;
	ID3D11Buffer *m_matrixBuffer;
	ID3D11Buffer *m_colorBuffer;
};