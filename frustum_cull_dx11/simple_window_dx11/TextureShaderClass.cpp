#include "TextureShaderClass.h"

TextureShaderClass::TextureShaderClass()
{
	m_vertexShader = 0;
	m_pixelShader = 0;
	m_inputLayout = 0;
	m_matrixBuffer = 0;
	m_sampleState = 0;
	m_colorBuffer = 0;
}

TextureShaderClass::~TextureShaderClass()
{
}

bool TextureShaderClass::init(ID3D11Device *device, HWND hwnd)
{
	return initShader(device, hwnd, L"simple.vs", L"simple.ps");
}

bool TextureShaderClass::render(ID3D11DeviceContext *deviceContext, int indexCount, 
								XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix,
								XMFLOAT4 color,
								ID3D11ShaderResourceView *texture)
{
	bool result;
	result = setShaderParameters(deviceContext, worldMatrix, viewMatrix, projectionMatrix, color);
	if (!result)
	{
		return false;
	}

	renderShader(deviceContext, indexCount, texture);
	return true;
}

void TextureShaderClass::stop()
{
	if (m_vertexShader)
	{
		m_vertexShader->Release();
		m_vertexShader = 0;
	}

	if (m_pixelShader)
	{
		m_pixelShader->Release();
		m_pixelShader = 0;
	}

	if (m_inputLayout)
	{
		m_inputLayout->Release();
		m_inputLayout = 0;
	}

	if (m_matrixBuffer)
	{
		m_matrixBuffer->Release();
		m_matrixBuffer = 0;
	}

	if (m_sampleState)
	{
		m_sampleState->Release();
		m_sampleState = 0;
	}

	if (m_colorBuffer)
	{
		m_colorBuffer->Release();
		m_colorBuffer = 0;
	}
}

bool TextureShaderClass::initShader(ID3D11Device *device, HWND hwnd, WCHAR *vsFilename, WCHAR *psFilename)
{
	HRESULT hr;
	ID3D10Blob *errorMsg;
	ID3D10Blob *vertexShaderBuffer;
	ID3D10Blob *pixelShaderBuffer;
	D3D11_INPUT_ELEMENT_DESC inputLayout[4];
	D3D11_SAMPLER_DESC samplerDesc;
	D3D11_BUFFER_DESC matrixBufferDesc;
	D3D11_BUFFER_DESC colorBufferDesc;

	errorMsg = 0;
	vertexShaderBuffer = 0;
	pixelShaderBuffer = 0;

	hr = D3DX11CompileFromFile(vsFilename, NULL, NULL, "TextureVertexShader", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, NULL,
		&vertexShaderBuffer, &errorMsg, NULL);
	if (FAILED(hr))
	{
		if (errorMsg)
		{
			outputShaderErrorMsg(errorMsg, hwnd, vsFilename);
		}
		else
		{
			MessageBox(hwnd, vsFilename, L"missing shader file", MB_OK);
		}
		return false;
	}

	hr = D3DX11CompileFromFile(psFilename, NULL, NULL, "TexturePixelShader", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, NULL,
		&pixelShaderBuffer, &errorMsg, NULL);
	if (FAILED(hr))
	{
		if (errorMsg)
		{
			outputShaderErrorMsg(errorMsg, hwnd, psFilename);
		}
		else
		{
			MessageBox(hwnd, psFilename, L"missing shader file", MB_OK);
		}
		return false;
	}
	hr = device->CreateVertexShader(vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), NULL, &m_vertexShader);
	if (FAILED(hr))
		return false;
	hr = device->CreatePixelShader(pixelShaderBuffer->GetBufferPointer(), pixelShaderBuffer->GetBufferSize(), NULL, &m_pixelShader);
	if (FAILED(hr))
		return false;

	inputLayout[0].SemanticName = "POSITION";
	inputLayout[0].SemanticIndex = 0;
	inputLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	inputLayout[0].InputSlot = 0;//标识输入汇编器的整数值（请参阅输入槽）。有效值介于0和15之间
	inputLayout[0].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	inputLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	inputLayout[0].InstanceDataStepRate = 0;

	inputLayout[1].SemanticName = "COLOR";
	inputLayout[1].SemanticIndex = 0;
	inputLayout[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	inputLayout[1].InputSlot = 0;
	inputLayout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	inputLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	inputLayout[1].InstanceDataStepRate = 0;

	inputLayout[2].SemanticName = "TEXCOORD";
	inputLayout[2].SemanticIndex = 0;
	inputLayout[2].Format = DXGI_FORMAT_R32G32_FLOAT;
	inputLayout[2].InputSlot = 0;
	inputLayout[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	inputLayout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	inputLayout[2].InstanceDataStepRate = 0;

	inputLayout[3].SemanticName = "NORMAL";
	inputLayout[3].SemanticIndex = 0;
	inputLayout[3].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	inputLayout[3].InputSlot = 0;
	inputLayout[3].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	inputLayout[3].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	inputLayout[3].InstanceDataStepRate = 0;

	hr = device->CreateInputLayout(inputLayout, 4, vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), &m_inputLayout);
	if (FAILED(hr))
		return false;

	vertexShaderBuffer->Release();
	vertexShaderBuffer = 0;
	pixelShaderBuffer->Release();
	pixelShaderBuffer = 0;

	matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.ByteWidth = sizeof(MatrixBufferType);
	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;
	hr = device->CreateBuffer(&matrixBufferDesc, NULL, &m_matrixBuffer);
	if (FAILED(hr))
		return false;

	colorBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	colorBufferDesc.ByteWidth = sizeof(XMFLOAT4);
	colorBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	colorBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	colorBufferDesc.MiscFlags = 0;
	colorBufferDesc.StructureByteStride = 0;
	hr = device->CreateBuffer(&colorBufferDesc, NULL, &m_colorBuffer);
	if (FAILED(hr))
		return false;

	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.MipLODBias = 0.0f;
	samplerDesc.MaxAnisotropy = 1;
	samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	samplerDesc.BorderColor[0] = 0;
	samplerDesc.BorderColor[1] = 0;
	samplerDesc.BorderColor[2] = 0;
	samplerDesc.BorderColor[3] = 0;
	samplerDesc.MinLOD = 0;
	samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;
	hr = device->CreateSamplerState(&samplerDesc, &m_sampleState);
	if (FAILED(hr))
		return false;

	return true;
}

bool TextureShaderClass::setShaderParameters(ID3D11DeviceContext* deviceContext,
	XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix, XMFLOAT4 color)
{
	HRESULT hr;
	unsigned int bufferNumber;
	D3D11_MAPPED_SUBRESOURCE mappedResource;

	MatrixBufferType *dataPtr;
	worldMatrix = XMMatrixTranspose(worldMatrix);
	viewMatrix = XMMatrixTranspose(viewMatrix);
	projectionMatrix = XMMatrixTranspose(projectionMatrix);
	hr = deviceContext->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(hr))
		return false;
	dataPtr = (MatrixBufferType*)mappedResource.pData;
	dataPtr->world = worldMatrix;
	dataPtr->view = viewMatrix;
	dataPtr->projection = projectionMatrix;
	deviceContext->Unmap(m_matrixBuffer, 0);
	bufferNumber = 0;
	deviceContext->VSSetConstantBuffers(bufferNumber, 1, &m_matrixBuffer);

	XMFLOAT4 *dataPtr2;
	hr = deviceContext->Map(m_colorBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(hr))
		return false;
	dataPtr2 = (XMFLOAT4*)mappedResource.pData;
	*dataPtr2 = color;
	deviceContext->Unmap(m_colorBuffer, 0);
	bufferNumber = 1;
	deviceContext->PSSetConstantBuffers(bufferNumber, 1, &m_colorBuffer);

	return true;
}

void TextureShaderClass::renderShader(ID3D11DeviceContext *deviceContext, int indexCount, ID3D11ShaderResourceView *texture)
{
	deviceContext->PSSetShaderResources(0, 1, &texture);
	deviceContext->IASetInputLayout(m_inputLayout);

	deviceContext->VSSetShader(m_vertexShader, NULL, 0);
	deviceContext->PSSetShader(m_pixelShader, NULL, 0);
	deviceContext->PSSetSamplers(0, 1, &m_sampleState);

	deviceContext->DrawIndexed(indexCount, 0, 0);
}

void TextureShaderClass::outputShaderErrorMsg(ID3D10Blob* errorMessage, HWND hwnd, WCHAR* shaderFilename)
{
	char* compileErrors;
	unsigned long long bufferSize, i;
	compileErrors = (char*)errorMessage->GetBufferPointer();
	bufferSize = errorMessage->GetBufferSize();
	printf("compile shader error:%s\n", compileErrors);

	errorMessage->Release();
	errorMessage = 0;
	MessageBox(hwnd, L"Error compiling shader.  Check shader-error.txt for message.", shaderFilename, MB_OK);
}