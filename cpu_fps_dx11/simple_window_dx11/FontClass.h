#pragma once
#include <d3d11.h>
#include <DirectXMath.h>
#include <fstream>
using namespace DirectX;
using namespace std;

#include "TextureClass.h"

class FontClass
{
private:
	struct FontType
	{
		float left, right;
		int size;
	};

	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 tex;
	};
public:
	FontClass();
	~FontClass();

	bool init(ID3D11Device*, ID3D11DeviceContext*, char*, char*);
	void stop();

	ID3D11ShaderResourceView* getTexture();
	void buildVertexArray(void*, char*, float, float);

private:
	bool loadFontData(char*);
	void releaseFontData();
	bool loadTexture(ID3D11Device*, ID3D11DeviceContext*, char*);
	void releaseTexture();

private:
	FontType *m_font;
	TextureClass *m_texture;
};