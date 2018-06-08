#include "TextClass.h"

TextClass::TextClass()
{
	m_fontClass = 0;
	m_fontShaderClass = 0;
	m_sentence = 0;
}

TextClass::~TextClass()
{
}

bool TextClass::init(ID3D11Device* device, ID3D11DeviceContext* deviceContext, HWND hwnd, char* sentence, int screenWidth, int screenHeight,int posX, int posY, float red, float green, float blue)
{
	bool result;
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

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

	m_fontShaderClass = new FontShaderClass;
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

	result = initSentence(strlen(sentence), device);
	if (!result)
	{
		return false;
	}
	result = updateSentence(sentence, posX, posY, red, green, blue, deviceContext);
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

	releaseSentence();
}

bool TextClass::render(ID3D11DeviceContext* deviceContext, XMMATRIX orthoMatrix)
{
	bool result;

	result = renderSentence(deviceContext, orthoMatrix);
	if (!result)
	{
		return false;
	}

	return true;
}

bool TextClass::initSentence(int maxLength, ID3D11Device* device)
{
	VertexType *vertices;
	unsigned long *indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT hr;
	
	m_sentence = new SentenceType;
	if (!m_sentence)
	{
		return false;
	}
	//ZeroMemory(sentence, sizeof(SentenceType));
	m_sentence->vertexBuffer = 0;
	m_sentence->indexBuffer = 0;

	m_sentence->maxLength = maxLength;
	m_sentence->vertexCount = 6 * maxLength;
	m_sentence->indexCount = m_sentence->vertexCount;
	vertices = new VertexType[m_sentence->vertexCount];
	if (!vertices)
	{
		return false;
	}

	indices = new unsigned long[m_sentence->indexCount];
	if (!indices)
	{
		return false;
	}
	memset(vertices, 0, (sizeof(VertexType) * m_sentence->vertexCount));

	for (int i = 0; i < m_sentence->indexCount; i++)
	{
		indices[i] = i;
	}

	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_sentence->vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;
	hr = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_sentence->vertexBuffer);
	if (FAILED(hr))
	{
		return false;
	}

	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_sentence->indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;
	hr = device->CreateBuffer(&indexBufferDesc, &indexData, &m_sentence->indexBuffer);
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

bool TextClass::updateSentence(char* text, int positionX, int positionY, float red, float green, float blue, ID3D11DeviceContext* deviceContext)
{
	int numLetters;
	VertexType *vertices;
	float drawX, drawY;
	HRESULT hr;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	VertexType *verticesPtr;

	m_sentence->red = red;
	m_sentence->green = green;
	m_sentence->blue = blue;

	numLetters = (int)strlen(text);
	if (numLetters > m_sentence->maxLength)
	{
		return false;
	}

	vertices = new VertexType[m_sentence->vertexCount];
	if (!vertices)
	{
		return false;
	}

	memset(vertices, 0, sizeof(VertexType) * m_sentence->vertexCount);
	drawX = (float)(((m_screenWidth / 2) * -1) + positionX);
	drawY = (float)((m_screenHeight / 2) - positionY);
	m_fontClass->buildVertexArray((void*)vertices, text, drawX, drawY);
	hr = deviceContext->Map(m_sentence->vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(hr))
	{
		return false;
	}
	verticesPtr = (VertexType*)mappedResource.pData;
	memcpy(verticesPtr, (void*)vertices, (sizeof(VertexType) * m_sentence->vertexCount));
	deviceContext->Unmap(m_sentence->vertexBuffer, 0);

	delete[] vertices;
	vertices = 0;

	return true;
}

void TextClass::releaseSentence()
{
	if (m_sentence)
	{
		if (m_sentence->vertexBuffer)
		{
			m_sentence->vertexBuffer->Release();
			m_sentence->vertexBuffer = 0;
		}

		if (m_sentence->indexBuffer)
		{
			m_sentence->indexBuffer->Release();
			m_sentence->indexBuffer = 0;
		}

		delete m_sentence;
		m_sentence = 0;
	}
}

bool TextClass::renderSentence(ID3D11DeviceContext* deviceContext, XMMATRIX orthoMatrix)
{
	unsigned int stride, offset;
	XMFLOAT4 pixelColor;
	bool result;

	stride = sizeof(VertexType);
	offset = 0;

	deviceContext->IASetVertexBuffers(0, 1, &m_sentence->vertexBuffer, &stride, &offset);
	deviceContext->IASetIndexBuffer(m_sentence->indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	pixelColor = XMFLOAT4(m_sentence->red, m_sentence->green, m_sentence->blue, 1.0f);

	// Render the text using the font shader.
	result = m_fontShaderClass->render(deviceContext, m_sentence->indexCount, m_fontClass->getTexture(), orthoMatrix, pixelColor);
	if (!result)
	{
		false;
	}

	return true;
}