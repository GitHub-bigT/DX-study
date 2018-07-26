#pragma once
#include <d3d11.h>
#include <DirectXMath.h>

using namespace DirectX;

class ModelClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT4 color;
		XMFLOAT2 tex;
	};
public:
	ModelClass();
	~ModelClass();
	bool init(ID3D11Device *device);
	void stop();
	void render(ID3D11DeviceContext *deviceContext);

private:
	bool initQuadBuffer(ID3D11Device *device);
	void stopBuffer();
	void renderQuadBuffer(ID3D11DeviceContext *deviceContext);
	

private:
	ID3D11Buffer *m_QuadVertexBuffer, *m_QuadIndexBuffer;
	int m_QuadVertexCount, m_QuadIndexCount;
};