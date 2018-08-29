#pragma once
#include <d3d11.h>
#include <DirectXMath.h>
#include <iostream>
using namespace DirectX;

class D3D11Class
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT4 color;
		XMFLOAT2 tex;
	};

public:
	D3D11Class();
	~D3D11Class();

	bool init();
	void stop();

	ID3D11Device* getDevice();
	ID3D11DeviceContext* getImmediateDeviceContext();
	void setViewport(ID3D11DeviceContext *deviceContext, float x, float y, int w, int h);

private:
	void printInfo(int, int);
	void outputShaderErrorMsg(ID3D10Blob* errorMessage, const char* shaderFilename);

private:
	ID3D11Device *m_Device;
	ID3D11DeviceContext *m_ImmediateDeviceContext;
};