#include "D3DClass.h"

D3DClass::D3DClass()
{
	m_swapChain = 0;
	m_device = 0;
	m_deviceContext = 0;
	m_renderTargetView = 0;
	m_depthStencilBuffer = 0;
	m_depthStencilState = 0;
	m_depthStencilView = 0;
	m_rasterState = 0;
}

D3DClass::~D3DClass()
{
}

void D3DClass::printInfo(int screenWidth, int screenHeight)
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
			printf("display = %d, refresh rate = %d\n",displayIndex, numerator / denominator);

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

bool D3DClass::init(int screenWidth, int screenHeight, bool vsync, HWND hwnd, bool fullscreen, float screenDepth, float screenNear)
{
	printInfo(screenWidth, screenHeight);

	HRESULT hr;
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	D3D_FEATURE_LEVEL featureLevel;
	ID3D11Texture2D *backBufferPtr;
	D3D11_TEXTURE2D_DESC depthBufferDesc;
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
	D3D11_RASTERIZER_DESC rasterDesc;
	D3D11_VIEWPORT viewport;
	float fieldOfView, screenAspect;

	m_vsync_enabled = vsync;
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = screenWidth;
	swapChainDesc.BufferDesc.Height = screenHeight;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	if (m_vsync_enabled)
	{
		//swapChainDesc.BufferDesc.RefreshRate.Numerator = xxx;
		//swapChainDesc.BufferDesc.RefreshRate.Denominator = xxx;
	}
	else
	{
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	}
	//将扫描线排序和缩放设置为未指定。
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = hwnd;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	if (fullscreen)
	{
		swapChainDesc.Windowed = false;
	}
	else
	{
		swapChainDesc.Windowed = true;
	}
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	//不要设置高级标志。
	swapChainDesc.Flags = 0;

	return true;
}

void D3DClass::stop()
{
	if (m_swapChain)
	{
		m_swapChain->SetFullscreenState(false, NULL);
	}

	if (m_rasterState)
	{
		m_rasterState->Release();
		m_rasterState = 0;
	}

	if (m_depthStencilView)
	{
		m_depthStencilView->Release();
		m_depthStencilView = 0;
	}

	if (m_depthStencilState)
	{
		m_depthStencilState->Release();
		m_depthStencilState = 0;
	}

	if (m_depthStencilBuffer)
	{
		m_depthStencilBuffer->Release();
		m_depthStencilBuffer = 0;
	}

	if (m_renderTargetView)
	{
		m_renderTargetView->Release();
		m_renderTargetView = 0;
	}

	if (m_deviceContext)
	{
		m_deviceContext->Release();
		m_deviceContext = 0;
	}

	if (m_device)
	{
		m_device->Release();
		m_device = 0;
	}

	if (m_swapChain)
	{
		m_swapChain->Release();
		m_swapChain = 0;
	}

}

void D3DClass::beginScene(float, float, float, float)
{

}

void D3DClass::endScene()
{

}

ID3D11Device* D3DClass::getDevice()
{
	return m_device;
}

ID3D11DeviceContext* D3DClass::getDeviceContext()
{
	return m_deviceContext;
}

void D3DClass::getProjectionMatrix(XMMATRIX& projectionMatrix)
{
	projectionMatrix = m_projectionMatrix;
}

void D3DClass::getWorldMatrix(XMMATRIX& worldMatrix)
{
	worldMatrix = m_worldMatrix;
}

void D3DClass::getOrthoMatrix(XMMATRIX& orthoMatrix)
{
	orthoMatrix = m_orthoMatrix;
}