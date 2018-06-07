#pragma once
#include "FontClass.h"
#include "TextureShaderClass.h"

class TextClass
{
private:
	struct SentenceType
	{
		ID3D11Buffer *vertexBuffer, *indexBuffer;
		int vertexCount, indexCount, maxLength;
		float red, green, blue;
	};

	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 tex;
	};
public:
	TextClass();
	~TextClass();
	bool init(ID3D11Device*, ID3D11DeviceContext*, HWND, int, int, XMMATRIX);
	void stop();
	bool render(ID3D11DeviceContext*, XMMATRIX, XMMATRIX);

private:
	bool initSentence(SentenceType**, int, ID3D11Device*);
	bool updateSentence(SentenceType*, char*, int, int, float, float, float, ID3D11DeviceContext*);
	void releaseSentence(SentenceType**);
	bool renderSentence(ID3D11DeviceContext*, SentenceType*, XMMATRIX, XMMATRIX);

private:
	FontClass *m_fontClass;
	TextureShaderClass *m_fontShaderClass;
	int m_screenWidth, m_screenHeight;
	XMMATRIX m_baseViewMatrix;

	SentenceType* m_sentence1;
	SentenceType* m_sentence2;
};

