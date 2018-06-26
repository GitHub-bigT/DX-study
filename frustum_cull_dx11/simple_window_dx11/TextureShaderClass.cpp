#include "TextureShaderClass.h"

TextureShaderClass::TextureShaderClass()
{
	m_vertexShader = 0;
	m_pixelShader = 0;
	m_inputLayout = 0;
	m_matrixBuffer = 0;
}

TextureShaderClass::~TextureShaderClass()
{
}

bool TextureShaderClass::init(ID3D11Device *device, HWND hwnd)
{
	return initShader(device, hwnd, L"simple.vs", L"simple.ps");
}

bool TextureShaderClass::render(ID3D11DeviceContext *deviceContext, int indexCount, XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix)
{
	bool result;
	result = setShaderParameters(deviceContext, worldMatrix, viewMatrix, projectionMatrix);
	if (!result)
	{
		return false;
	}

	renderShader(deviceContext, indexCount);
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
}

bool TextureShaderClass::initShader(ID3D11Device *device, HWND hwnd, WCHAR *vsFilename, WCHAR *psFilename)
{
	HRESULT hr;
	ID3D10Blob *errorMsg;
	ID3D10Blob *vertexShaderBuffer;
	ID3D10Blob *pixelShaderBuffer;
	D3D11_INPUT_ELEMENT_DESC inputLayout[4];
	D3D11_BUFFER_DESC matrixBufferDesc;

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
	inputLayout[0].InputSlot = 1;//标识输入汇编器的整数值（请参阅输入槽）。有效值介于0和15之间
	inputLayout[0].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	inputLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	inputLayout[0].InstanceDataStepRate = 0;

	inputLayout[1].SemanticName = "COLOR";
	inputLayout[1].SemanticIndex = 5;
	inputLayout[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	inputLayout[1].InputSlot = 1;
	inputLayout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	inputLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	inputLayout[1].InstanceDataStepRate = 0;

	inputLayout[2].SemanticName = "TEXCOORD";
	inputLayout[2].SemanticIndex = 0;
	inputLayout[2].Format = DXGI_FORMAT_R32G32_FLOAT;
	inputLayout[2].InputSlot = 1;
	inputLayout[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	inputLayout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	inputLayout[2].InstanceDataStepRate = 0;

	inputLayout[3].SemanticName = "NORMAL";
	inputLayout[3].SemanticIndex = 0;
	inputLayout[3].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	inputLayout[3].InputSlot = 1;
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

	return true;
}

bool TextureShaderClass::setShaderParameters(ID3D11DeviceContext* deviceContext,
	XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix)
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

	return true;
}

void TextureShaderClass::renderShader(ID3D11DeviceContext *deviceContext, int indexCount)
{
	//deviceContext->PSSetShaderResources(0, 1, &texture);
	deviceContext->IASetInputLayout(m_inputLayout);

	deviceContext->VSSetShader(m_vertexShader, NULL, 0);
	deviceContext->PSSetShader(m_pixelShader, NULL, 0);
	//deviceContext->PSSetSamplers(0, 1, &m_sampleState);

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