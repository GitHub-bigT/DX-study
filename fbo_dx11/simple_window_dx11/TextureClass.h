#pragma once
#include <d3d11.h>
#include <dxgi.h>
#include <d3dx11tex.h>
#include <stdio.h>
#include <stb_image.h>

class TextureClass
{
public:
	TextureClass();
	~TextureClass();
	bool init(ID3D11Device*, ID3D11DeviceContext*, char*);
	void stop();

	HANDLE getShareHandle();

private:
	bool makeShareResource();
	bool loadImage(char*);

private:
	int m_width, m_height, m_channels;
	unsigned char* m_ImageData;
	ID3D11Texture2D *m_texture;
	HANDLE m_shareHandle;
};

