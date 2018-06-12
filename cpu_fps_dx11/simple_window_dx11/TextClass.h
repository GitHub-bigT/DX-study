#pragma once
#include "FontClass.h"
#include "FontShaderClass.h"

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
	bool init(ID3D11Device*, ID3D11DeviceContext*, HWND, int, int);
	bool updateSentence(char*, int, int, float, float, float, ID3D11DeviceContext*);
	void stop();
	bool render(ID3D11DeviceContext*, XMMATRIX);

private:
	bool initSentence(int, ID3D11Device*);
	void releaseSentence();
	bool renderSentence(ID3D11DeviceContext*, XMMATRIX);

private:
	FontClass *m_fontClass;
	FontShaderClass *m_fontShaderClass;
	int m_screenWidth, m_screenHeight;

	SentenceType* m_sentence;
};

