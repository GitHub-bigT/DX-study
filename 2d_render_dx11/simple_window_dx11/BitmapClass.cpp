#include "BitmapClass.h"

ModelClass::ModelClass()
{
	m_vertexBuffer = 0;
	m_indexBuffer = 0;
	m_textureClass = 0;
}

ModelClass::~ModelClass()
{
}

bool ModelClass::init(ID3D11Device* device, ID3D11DeviceContext *deviceContext, int screenWidth, int screenHeight, char *textureFilename, int bitmapWidth, int bitmapHeight)
{
	bool result;
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;
	m_bitmapWidth = bitmapWidth;
	m_bitmapHeight = bitmapHeight;
	m_previousPosX = -1;
	m_previousPosX = -1;

	result = initBuffer(device);
	if (!result)
	{
		return false;
	}
	result = loadTexture(device, deviceContext, textureFilename);
	if (!result)
	{
		return false;
	}

	return true;
}

bool ModelClass::loadTexture(ID3D11Device* device, ID3D11DeviceContext *deviceContext, char *textureFilename)
{
	bool result;

	m_textureClass = new TextureClass;
	if (!m_textureClass)
	{
		return false;
	}

	result = m_textureClass->init(device, deviceContext, textureFilename);
	if (!result)
	{
		return false;
	}

	return true;
}

void ModelClass::releaseTexture()
{
	if (m_textureClass)
	{
		m_textureClass->stop();
		delete m_textureClass;
		m_textureClass = 0;
	}
}

ID3D11ShaderResourceView* ModelClass::getTexture()
{
	return m_textureClass->getTexture();
}

void ModelClass::stop()
{
	releaseTexture();

	stopBuffer();
}

bool ModelClass::render(ID3D11DeviceContext* deviceContext, int positionX, int positionY)
{
	bool result;
	result = updateBuffer(deviceContext, positionX, positionY);
	if (!result)
	{
		return false;
	}

	renderBuffer(deviceContext);

	return true;
}

int ModelClass::getIndexCount()
{
	return m_indexCount;
}

bool ModelClass::initBuffer(ID3D11Device* device)
{
	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;
	m_vertexCount = 6;
	m_indexCount = m_vertexCount;

	vertices = new VertexType[m_vertexCount];
	if (!vertices)
	{
		return false;
	}
	indices = new unsigned long[m_indexCount];
	if (!indices)
	{
		return false;
	}

	memset(vertices, 0, sizeof(VertexType) * m_vertexCount);

	for (int i = 0; i < m_indexCount; i++)
	{
		indices[i] = i;
	}

	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	delete[] vertices;
	vertices = 0;

	delete[] indices;
	indices = 0;

	return true;
}

void ModelClass::stopBuffer()
{
	if (m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = 0;
	}

	if (m_indexBuffer)
	{
		m_indexBuffer->Release();
		m_indexBuffer = 0;
	}
}

void ModelClass::renderBuffer(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;

	stride = sizeof(VertexType);
	offset = 0;

	//input assembler
	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
	deviceContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}

bool ModelClass::updateBuffer(ID3D11DeviceContext* deviceContext, int positionX, int positionY)
{
	float left, right, top, bottom;
	VertexType *vertices;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	VertexType *verticesPtr;
	HRESULT hr;
	if ((positionX == m_previousPosX) && (positionY == m_previousPosY))
	{
		return true;
	}
	m_previousPosX = positionX;
	m_previousPosY = positionY;

	left = (float)((m_screenWidth / 2) * -1) + (float)positionX;
	right = left + (float)m_bitmapWidth;
	top = (float)(m_screenHeight / 2) - (float)positionY;
	bottom = top - (float)m_bitmapHeight;
	printf("left = %f, right = %f, top = %f, bottom = %f\n", left, right, top, bottom);

	vertices = new VertexType[m_vertexCount];
	if (!vertices)
	{
		return false;
	}

	vertices[0].position = XMFLOAT3(left, top, 0.0f);  // 左上
	vertices[0].color = XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices[0].tex = XMFLOAT2(0.0f, 0.0f);

	vertices[1].position = XMFLOAT3(right, bottom, 0.0f);  // 右下
	vertices[1].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[1].tex = XMFLOAT2(1.0f, 1.0f);

	vertices[2].position = XMFLOAT3(left, bottom, 0.0f);  // 左下
	vertices[2].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices[2].tex = XMFLOAT2(0.0f, 1.0f);

	// Second triangle.
	vertices[3].position = XMFLOAT3(left, top, 0.0f);  // 左上
	vertices[3].color = XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices[3].tex = XMFLOAT2(0.0f, 0.0f);

	vertices[4].position = XMFLOAT3(right, top, 0.0f);  // 右上
	vertices[4].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices[4].tex = XMFLOAT2(1.0f, 0.0f);

	vertices[5].position = XMFLOAT3(right, bottom, 0.0f);  // 右下
	vertices[5].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[5].tex = XMFLOAT2(1.0f, 1.0f);
/*
	vertices[0].position = XMFLOAT3(0.0f, 0.0f, 0.0f);  // Top left.
	vertices[0].color = XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices[0].tex = XMFLOAT2(0.0f, 0.0f);

	vertices[1].position = XMFLOAT3(1.0f, -1.0f, 0.0f);  // Bottom right.
	vertices[1].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[1].tex = XMFLOAT2(1.0f, 1.0f);

	vertices[2].position = XMFLOAT3(0.0f, -1.0f, 0.0f);  // Bottom left.
	vertices[2].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices[2].tex = XMFLOAT2(0.0f, 1.0f);

	// Second triangle.
	vertices[3].position = XMFLOAT3(0.0f, 0.0f, 0.0f);  // Top left.
	vertices[3].color = XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices[3].tex = XMFLOAT2(0.0f, 0.0f);

	vertices[4].position = XMFLOAT3(1.0f, 0.0f, 0.0f);  // Top right.
	vertices[4].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices[4].tex = XMFLOAT2(1.0f, 0.0f);

	vertices[5].position = XMFLOAT3(1.0f, -1.0f, 0.0f);  // Bottom right.
	vertices[5].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[5].tex = XMFLOAT2(1.0f, 1.0f);*/

	hr = deviceContext->Map(m_vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(hr))
	{
		return false;
	}
	verticesPtr = (VertexType*)mappedResource.pData;
	memcpy(verticesPtr, (void*)vertices, sizeof(VertexType) * m_vertexCount);
	deviceContext->Unmap(m_vertexBuffer, 0);

	delete[] vertices;
	vertices = 0;

	return true;
}