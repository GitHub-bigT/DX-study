#include "TextClass.h"

TextClass::TextClass()
{
	m_fontClass = 0;
	m_fontShaderClass = 0;
	m_sentence1 = 0;
	m_sentence2 = 0;
}

TextClass::~TextClass()
{
}

bool TextClass::init(ID3D11Device* device, ID3D11DeviceContext* deviceContext, HWND hwnd, int screenWidth, int screenHeight, XMMATRIX baseViewMatrix)
{
	bool result;
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	m_baseViewMatrix = baseViewMatrix;
	m_fontClass = new FontClass;
	if (!m_fontClass)
	{
		return false;
	}
	result = m_fontClass->init(device, deviceContext, "../../image_source/fontdata.txt", "../../image_source/font.dds");
	if (!result)
	{
		MessageBox(hwnd, L"init FontClass error", L"Error", MB_OK);
		return false;
	}

	m_fontShaderClass = new TextureShaderClass;
	if (!m_fontShaderClass)
	{
		return false;
	}

	result = m_fontShaderClass->init(device, hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"init FontShaderClass error", L"Error", MB_OK);
		return false;
	}

	result = initSentence(&m_sentence1, 100, device);
	if (!result)
	{
		return false;
	}
	result = updateSentence(m_sentence1, "a b c d e f g h i j k l m n o p q r s t u v w x y z", 100, 100, 0.0f, 0.0f, 1.0f, deviceContext);
	if (!result)
	{
		return false;
	}

	result = initSentence(&m_sentence2, 100, device);
	if (!result)
	{
		return false;
	}
	result = updateSentence(m_sentence2, "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z", 100, 200, 1.0f, 1.0f, 0.0f, deviceContext);
	if (!result)
	{
		return false;
	}

	return true;
}

void TextClass::stop()
{
	if (m_fontClass)
	{
		m_fontClass->stop();
		delete m_fontClass;
		m_fontClass = 0;
	}

	if (m_fontShaderClass)
	{
		m_fontShaderClass->stop();
		delete m_fontShaderClass;
		m_fontShaderClass = 0;
	}

	releaseSentence(&m_sentence1);
	releaseSentence(&m_sentence1);
}

bool TextClass::render(ID3D11DeviceContext* deviceContext, XMMATRIX worldMatrix, XMMATRIX orthoMatrix)
{
	bool result;

	result = renderSentence(deviceContext, m_sentence1, worldMatrix, orthoMatrix);
	if (!result)
	{
		return false;
	}

	result = renderSentence(deviceContext, m_sentence2, worldMatrix, orthoMatrix);
	if (!result)
	{
		return false;
	}

	return true;
}

bool TextClass::initSentence(SentenceType** sentence, int maxLength, ID3D11Device* device)
{
	VertexType *vertices;
	unsigned long *indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT hr;
	
	*sentence = new SentenceType;
	if (!*sentence)
	{
		return false;
	}
	//ZeroMemory(sentence, sizeof(SentenceType));
	(*sentence)->vertexBuffer = 0;
	(*sentence)->indexBuffer = 0;

	(*sentence)->maxLength = maxLength;
	(*sentence)->vertexCount = 6 * maxLength;
	(*sentence)->indexCount = (*sentence)->vertexCount;
	vertices = new VertexType[(*sentence)->vertexCount];
	if (!vertices)
	{
		return false;
	}

	indices = new unsigned long[(*sentence)->indexCount];
	if (!indices)
	{
		return false;
	}
	memset(vertices, 0, (sizeof(VertexType) * (*sentence)->vertexCount));

	for (int i = 0; i < (*sentence)->indexCount; i++)
	{
		indices[i] = i;
	}

	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * (*sentence)->vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;
	hr = device->CreateBuffer(&vertexBufferDesc, &vertexData, &(*sentence)->vertexBuffer);
	if (FAILED(hr))
	{
		return false;
	}

	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * (*sentence)->indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;
	hr = device->CreateBuffer(&indexBufferDesc, &indexData, &(*sentence)->indexBuffer);
	if (FAILED(hr))
	{
		return false;
	}

	// Release the vertex array as it is no longer needed.
	delete[] vertices;
	vertices = 0;

	// Release the index array as it is no longer needed.
	delete[] indices;
	indices = 0;

	return true;
}

bool TextClass::updateSentence(SentenceType* sentence, char* text, int positionX, int positionY, float red, float green, float blue, ID3D11DeviceContext* deviceContext)
{
	int numLetters;
	VertexType *vertices;
	float drawX, drawY;
	HRESULT hr;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	VertexType *verticesPtr;

	sentence->red = red;
	sentence->green = green;
	sentence->blue = blue;

	numLetters = (int)strlen(text);
	if (numLetters > sentence->maxLength)
	{
		return false;
	}

	vertices = new VertexType[sentence->vertexCount];
	if (!vertices)
	{
		return false;
	}

	memset(vertices, 0, sizeof(VertexType) * sentence->vertexCount);
	drawX = (float)(((m_screenWidth / 2) * -1) + positionX);
	drawY = (float)((m_screenHeight / 2) - positionY);
	m_fontClass->buildVertexArray((void*)vertices, text, drawX, drawY);
	hr = deviceContext->Map(sentence->vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(hr))
	{
		return false;
	}
	verticesPtr = (VertexType*)mappedResource.pData;
	memcpy(verticesPtr, (void*)vertices, (sizeof(VertexType) * sentence->vertexCount));
	deviceContext->Unmap(sentence->vertexBuffer, 0);

	delete[] vertices;
	vertices = 0;

	return true;
}

void TextClass::releaseSentence(SentenceType** sentence)
{
	if (*sentence)
	{
		if ((*sentence)->vertexBuffer)
		{
			(*sentence)->vertexBuffer->Release();
			(*sentence)->vertexBuffer = 0;
		}

		if ((*sentence)->indexBuffer)
		{
			(*sentence)->indexBuffer->Release();
			(*sentence)->indexBuffer = 0;
		}

		delete *sentence;
		*sentence = 0;
	}
}

bool TextClass::renderSentence(ID3D11DeviceContext* deviceContext, SentenceType* sentence, XMMATRIX worldMatrix, XMMATRIX orthoMatrix)
{
	unsigned int stride, offset;
	XMFLOAT4 pixelColor;
	bool result;

	stride = sizeof(VertexType);
	offset = 0;

	deviceContext->IASetVertexBuffers(0, 1, &sentence->vertexBuffer, &stride, &offset);
	deviceContext->IASetIndexBuffer(sentence->indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	pixelColor = XMFLOAT4(sentence->red, sentence->green, sentence->blue, 1.0f);

	// Render the text using the font shader.
	result = m_fontShaderClass->render(deviceContext, sentence->indexCount, m_fontClass->getTexture(), worldMatrix, m_baseViewMatrix, orthoMatrix, pixelColor);
	if (!result)
	{
		false;
	}

	return true;
}