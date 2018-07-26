#include "SimpleShader.h"

SimpleShader::SimpleShader()
{
	m_vertexShader = 0;
	m_pixelShader = 0;
	m_layout = 0;
}

SimpleShader::~SimpleShader()
{
}

bool SimpleShader::init(ID3D11Device* device)
{
	bool result;
	result = initShader(device, L"dx_shader/simple.vs", L"dx_shader/simple.ps");
	if (!result)
	{
		return false;
	}
	return true;
}

void SimpleShader::stop()
{
	stopShader();
}

void SimpleShader::render(ID3D11DeviceContext *deviceContext)
{
	renderShader(deviceContext);
}

bool SimpleShader::initShader(ID3D11Device* device, WCHAR* vsFilename, WCHAR* psFilename)
{
	HRESULT hr;
	ID3D10Blob *errorMsg;
	ID3D10Blob *vertexShaderBuffer;
	ID3D10Blob *pixelShaderBuffer;
	D3D11_INPUT_ELEMENT_DESC polygonLayout[2];
	unsigned int numElements;

	errorMsg = 0;
	vertexShaderBuffer = 0;
	pixelShaderBuffer = 0;

	hr = D3DX11CompileFromFile(vsFilename, NULL, NULL, "ColorVertexShader", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, NULL, &vertexShaderBuffer, &errorMsg, NULL);
	if (FAILED(hr))
	{
		if (errorMsg)
		{
			//outputShaderErrorMsg(errorMsg, hwnd, vsFilename);
		}
		else
		{
			//MessageBox(hwnd, vsFilename, L"missing shader file", MB_OK);
		}
		return false;
	}
	hr = D3DX11CompileFromFile(psFilename, NULL, NULL, "ColorPixelShader", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, NULL, &pixelShaderBuffer, &errorMsg, NULL);
	if (FAILED(hr))
	{
		if (errorMsg)
		{
			//outputShaderErrorMsg(errorMsg, hwnd, psFilename);
		}
		else
		{
			//MessageBox(hwnd, psFilename, L"missing shader file", MB_OK);
		}
		return false;
	}
	hr = device->CreateVertexShader(vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), NULL, &m_vertexShader);
	if (FAILED(hr))
		return false;
	hr = device->CreatePixelShader(pixelShaderBuffer->GetBufferPointer(), pixelShaderBuffer->GetBufferSize(), NULL, &m_pixelShader);
	if (FAILED(hr))
		return false;

	polygonLayout[0].SemanticName = "POSITION";
	polygonLayout[0].SemanticIndex = 0;
	polygonLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	polygonLayout[0].InputSlot = 0;//标识输入汇编器的整数值（请参阅输入槽）。有效值介于0和15之间
	polygonLayout[0].AlignedByteOffset = 0;
	polygonLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[0].InstanceDataStepRate = 0;

	polygonLayout[1].SemanticName = "COLOR";
	polygonLayout[1].SemanticIndex = 0;
	polygonLayout[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	polygonLayout[1].InputSlot = 0;
	polygonLayout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	polygonLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[1].InstanceDataStepRate = 0;

	numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);

	hr = device->CreateInputLayout(polygonLayout, numElements, vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), &m_layout);
	if (FAILED(hr))
		return false;

	vertexShaderBuffer->Release();
	vertexShaderBuffer = 0;
	pixelShaderBuffer->Release();
	pixelShaderBuffer = 0;

	return true;
}

void SimpleShader::stopShader()
{
	if (m_layout)
	{
		m_layout->Release();
		m_layout = 0;
	}

	if (m_pixelShader)
	{
		m_pixelShader->Release();
		m_pixelShader = 0;
	}

	if (m_vertexShader)
	{
		m_vertexShader->Release();
		m_vertexShader = 0;
	}
}

void SimpleShader::renderShader(ID3D11DeviceContext *deviceContext)
{
	deviceContext->IASetInputLayout(m_layout);

	deviceContext->VSSetShader(m_vertexShader, NULL, 0);
	deviceContext->PSSetShader(m_pixelShader, NULL, 0);
}
