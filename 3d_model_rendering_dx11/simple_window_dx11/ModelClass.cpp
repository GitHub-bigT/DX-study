#include "ModelClass.h"

ModelClass::ModelClass()
{
	m_vertexBuffer = 0;
	m_indexBuffer = 0;
	m_textureClass = 0;
}

ModelClass::~ModelClass()
{
}

bool ModelClass::init(ID3D11Device* device, ID3D11DeviceContext *deviceContext, WCHAR *textureFilename, char* filename)
{
	bool result;
	result = initModel(filename);
	if (!result)
	{
		return false;
	}

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

bool ModelClass::initModel(char *filename)
{
	ifstream fin;
	char input;
	fin.open(filename);
	if (fin.fail())
	{
		return false;
	}
	fin.get(input);
	while (input != ':')
	{
		fin.get(input);
	}
	fin >> m_vertexCount;
	m_indexCount = m_vertexCount;
	m_model = new ModelType[m_vertexCount];
	fin.get(input);
	while (input != ':')
	{
		fin.get(input);
	}
	fin.get(input);
	fin.get(input);
	for (int i = 0; i < m_vertexCount; i++)
	{
		fin >> m_model[i].x >> m_model[i].y >> m_model[i].z;
		fin >> m_model[i].u >> m_model[i].v;
		fin >> m_model[i].nx >> m_model[i].ny >> m_model[i].nz;
	}

	fin.close();

	return true;
}

void ModelClass::releaseModel()
{
	if (m_model)
	{
		delete[] m_model;
		m_model = 0;
	}
}

bool ModelClass::loadTexture(ID3D11Device* device, ID3D11DeviceContext *deviceContext, WCHAR *textureFilename)
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
	stopBuffer();

	releaseTexture();

	releaseModel();
}

void ModelClass::render(ID3D11DeviceContext* deviceContext)
{
	renderBuffer(deviceContext);
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
/*
	m_vertexCount = 5;
	m_indexCount = 6;*/

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

/*
	vertices[0].position = XMFLOAT3(-1.0f, -1.0f, 0.0f);  //左下
	vertices[0].color = XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices[0].tex = XMFLOAT2(0.0f, 1.0f);
	vertices[0].normal = XMFLOAT3(0.0f, 0.0f, -1.0f);

	vertices[1].position = XMFLOAT3(-1.0f, 1.0f, 0.0f);  //左上
	vertices[1].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[1].tex = XMFLOAT2(0.0f, 0.0f);
	vertices[1].normal = XMFLOAT3(0.0f, 0.0f, -1.0f);

	vertices[2].position = XMFLOAT3(1.0f, 1.0f, 0.0f);  //右上
	vertices[2].color = XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices[2].tex = XMFLOAT2(1.0f, 0.0f);
	vertices[2].normal = XMFLOAT3(0.0f, 0.0f, -1.0f);

	vertices[3].position = XMFLOAT3(1.0f, -1.0f, 0.0f);  //右下
	vertices[3].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[3].tex = XMFLOAT2(1.0f, 1.0f);
	vertices[3].normal = XMFLOAT3(0.0f, 0.0f, -1.0f);

	vertices[4].position = XMFLOAT3(0.0f, 1.0f, 0.0f);  //中上
	vertices[4].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices[4].tex = XMFLOAT2(0.5f, 0.0f);
	vertices[4].normal = XMFLOAT3(0.0f, 0.0f, -1.0f);

	indices[0] = 0;  // 左下
	indices[1] = 1;  // 左上
	indices[2] = 3;  // 右下
	indices[3] = 1;  // 左上
	indices[4] = 2;  // 右上
	indices[5] = 3;  // 右下*/
/*
	indices[0] = 0;  // 左下
	indices[1] = 4;  // 中上
	indices[2] = 3;  // 右下*/
	for (int i = 0; i < m_vertexCount; i++)
	{
		vertices[i].position = XMFLOAT3(m_model[i].x, m_model[i].y, m_model[i].z);
		vertices[i].color = XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);
		vertices[i].tex = XMFLOAT2(m_model[i].u, m_model[i].v);
		vertices[i].normal = XMFLOAT3(m_model[i].nx, m_model[i].ny, m_model[i].nz);
		indices[i] = i;
	}

	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
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