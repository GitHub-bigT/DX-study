#pragma once
#include <d3d11.h>
#include <DirectXMath.h>

#include "TextureClass.h"
using namespace DirectX;

class ModelClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT4 color;
		XMFLOAT2 tex;
		XMFLOAT3 normal;
	};

public:
	ModelClass();
	~ModelClass();

	bool init(ID3D11Device*, ID3D11DeviceContext*, char*);
	void stop();
	void render(ID3D11DeviceContext*);

	int getIndexCount();
	ID3D11ShaderResourceView* getTexture();

private:
	bool initBuffer(ID3D11Device*);
	void stopBuffer();
	void renderBuffer(ID3D11DeviceContext*);

	bool loadTexture(ID3D11Device*, ID3D11DeviceContext*, char*);
	void releaseTexture();

private:
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	TextureClass *m_textureClass;
};