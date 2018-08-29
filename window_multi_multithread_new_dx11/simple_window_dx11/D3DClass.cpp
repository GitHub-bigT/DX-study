#include "D3DClass.h"

D3D11Class::D3D11Class()
{
	m_Device = 0;
	m_ImmediateDeviceContext = 0;
}

D3D11Class::~D3D11Class()
{
}

void D3D11Class::printInfo(int screenWidth, int screenHeight)
{
	HRESULT hr;
	IDXGIFactory *factory;

	hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);
	if (FAILED(hr))
		return;

	IDXGIAdapter *adapter;
	int adapterIndex = 0;
	while (factory->EnumAdapters(adapterIndex, &adapter) != DXGI_ERROR_NOT_FOUND)
	{
		DXGI_ADAPTER_DESC adapterDesc;
		unsigned long long stringLength;
		hr = adapter->GetDesc(&adapterDesc);
		if (FAILED(hr))
			return;

		char m_videoCardDescription[128];
		int error = wcstombs_s(&stringLength, m_videoCardDescription, adapterDesc.Description, 128);
		if (error)
			return;
		printf("adapter = %d, --    %s   -- \n", adapterIndex, m_videoCardDescription);
		int m_videoCardMemory = (int)(adapterDesc.DedicatedVideoMemory / 1024 / 1024);
		printf("adapter = %d, video card memory = %d\n", adapterIndex, m_videoCardMemory);

		int displayIndex = 0;
		IDXGIOutput *adapterOutput;
		while (adapter->EnumOutputs(displayIndex, &adapterOutput) != DXGI_ERROR_NOT_FOUND)
		{
			DXGI_MODE_DESC *displayModeList;
			unsigned int numModes, numerator, denominator;

			hr = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL);//有符号归一化整数格式、交错模式

			displayModeList = new DXGI_MODE_DESC[numModes];
			hr = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList);

			for (int i = 0; i < numModes; i++)
			{
				if (displayModeList[i].Width == screenWidth)
				{
					if (displayModeList[i].Height == screenHeight)
					{
						numerator = displayModeList[i].RefreshRate.Numerator;
						denominator = displayModeList[i].RefreshRate.Denominator;
					}
				}
			}
			printf("display = %d, refresh rate = %d\n", displayIndex, numerator / denominator);

			delete[] displayModeList;
			displayModeList = 0;

			adapterOutput->Release();
			adapterOutput = 0;

			displayIndex++;
		}

		adapter->Release();
		adapter = 0;

		adapterIndex++;
	}

	factory->Release();
	factory = 0;
}

void D3D11Class::outputShaderErrorMsg(ID3D10Blob* errorMessage, const char* shaderFilename)
{
	char* compileErrors;
	unsigned long long bufferSize, i;
	compileErrors = (char*)errorMessage->GetBufferPointer();
	bufferSize = errorMessage->GetBufferSize();
	printf("shader:%s, compile shader error:%s\n", shaderFilename, compileErrors);

	errorMessage->Release();
	errorMessage = 0;
}

bool D3D11Class::init()
{
	//printInfo(screenWidth, screenHeight);
	HRESULT hr;
	bool result = false;

	//device
	D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;
	hr = D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, &featureLevel, 1, D3D11_SDK_VERSION, &m_Device, NULL, &m_ImmediateDeviceContext);
	if (FAILED(hr))
		return false;

	return true;
}

void D3D11Class::stop()
{
	if (m_ImmediateDeviceContext)
	{
		m_ImmediateDeviceContext->Release();
		m_ImmediateDeviceContext = 0;
	}

	if (m_Device)
	{
		m_Device->Release();
		m_Device = 0;
	}
}

ID3D11Device* D3D11Class::getDevice()
{
	return m_Device;
}

ID3D11DeviceContext* D3D11Class::getImmediateDeviceContext()
{
	return m_ImmediateDeviceContext;
}

void D3D11Class::setViewport(ID3D11DeviceContext *deviceContext, float x, float y, int w, int h)
{
	//view port
	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));
	viewport.Width = w;
	viewport.Height = h;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	viewport.TopLeftX = x;
	viewport.TopLeftY = y;
	deviceContext->RSSetViewports(1, &viewport);
}