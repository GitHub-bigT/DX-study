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
	};

public:
	ModelClass();
	~ModelClass();

	bool init(ID3D11Device*);
	void stop();
	void render(ID3D11DeviceContext*);

	int getIndexCount();

private:
	bool initBuffer(ID3D11Device*);
	void stopBuffer();
	void renderBuffer(ID3D11DeviceContext*);

private:
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
};