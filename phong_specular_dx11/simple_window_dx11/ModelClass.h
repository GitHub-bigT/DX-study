#pragma once
#include <d3d11.h>
#include <DirectXMath.h>
#include <fstream>
#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "TextureClass.h"
using namespace DirectX;
using namespace std;

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

	struct ModelType
	{
		float x, y, z;
		float u, v;
		float nx, ny, nz;
	};

public:
	ModelClass();
	~ModelClass();

	bool init(ID3D11Device*, ID3D11DeviceContext*, WCHAR*, char*);
	void stop();
	void render(ID3D11DeviceContext*);
	bool initModel(char*);
	void releaseModel();

	int getIndexCount();
	ID3D11ShaderResourceView* getTexture();

private:
	bool initBuffer(ID3D11Device*);
	bool initModelWidthAssimp(char*);
	void stopBuffer();
	void renderBuffer(ID3D11DeviceContext*);

	bool loadTexture(ID3D11Device*, ID3D11DeviceContext*, WCHAR*);
	void releaseTexture();

private:
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	TextureClass *m_textureClass;
	ModelType *m_model;
	unsigned long* indices;

};