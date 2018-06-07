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
	};

public:
	ModelClass();
	~ModelClass();

	bool init(ID3D11Device*, ID3D11DeviceContext*,int, int, char*, int, int);
	void stop();
	bool render(ID3D11DeviceContext*, int, int);

	int getIndexCount();
	ID3D11ShaderResourceView* getTexture();

private:
	bool initBuffer(ID3D11Device*);
	void stopBuffer();
	void renderBuffer(ID3D11DeviceContext*);
	bool updateBuffer(ID3D11DeviceContext*, int, int);

	bool loadTexture(ID3D11Device*, ID3D11DeviceContext*, char*);
	void releaseTexture();

private:
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	TextureClass *m_textureClass;

	int m_screenWidth, m_screenHeight;
	int m_bitmapWidth, m_bitmapHeight;
	int m_previousPosX, m_previousPosY;
};