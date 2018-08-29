#include "FrameBufferClass.h"


FrameBufferClass::FrameBufferClass()
{
	m_VsyncEnabled = false;
	m_x4Msaa = false;
	m_x4MsaaQuality = 0;
	m_SampleCount = 0;
	m_ScreenWidth = 0;
	m_ScreenHeight = 0;
	m_Hwnd = 0;

	m_Device = 0;
	m_SwapChain = 0;
	m_RenderTargetView = 0;
	m_DepthStencilBuffer = 0;
	m_DepthStencilView = 0;
}

FrameBufferClass::~FrameBufferClass()
{
}

bool FrameBufferClass::init(ID3D11Device *device, int screenWidth, int screenHeight, bool vsync, bool msaa, HWND hwnd)
{
	m_Device = device;
	m_VsyncEnabled = vsync;
	m_Hwnd = hwnd;
	m_ScreenWidth = screenWidth;
	m_ScreenHeight = screenHeight;
	m_x4Msaa = msaa;
	if (msaa)
		m_SampleCount = 4;
	else
		m_SampleCount = 1;

	bool result = false;
	//swap chain
	result = initSwapChain();
	if (!result)
		return false;
	//render target
	result = initRenderTarget();
	if (!result)
		return false;
	//depth stencil
	result = initDepthStencil();
	if (!result)
		return false;
}

void FrameBufferClass::stop()
{
	if (m_SwapChain)
	{
		m_SwapChain->SetFullscreenState(false, NULL);
	}

	if (m_RenderTargetView)
	{
		m_RenderTargetView->Release();
		m_RenderTargetView = 0;
	}

	if (m_DepthStencilView)
	{
		m_DepthStencilView->Release();
		m_DepthStencilView = 0;
	}

	if (m_DepthStencilBuffer)
	{
		m_DepthStencilBuffer->Release();
		m_DepthStencilBuffer = 0;
	}
}

bool FrameBufferClass::initSwapChain()
{
	HRESULT hr;
	//swap chain
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = m_ScreenWidth;
	swapChainDesc.BufferDesc.Height = m_ScreenHeight;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	if (m_VsyncEnabled)
	{
		//swapChainDesc.BufferDesc.RefreshRate.Numerator = xxx;
		//swapChainDesc.BufferDesc.RefreshRate.Denominator = xxx;
	}
	else
	{
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	}
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;//将扫描线排序和缩放设置为未指定。
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = m_Hwnd;
	m_x4MsaaQuality = 0;
	m_Device->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, m_SampleCount, &m_x4MsaaQuality);
	swapChainDesc.SampleDesc.Count = m_SampleCount;
	swapChainDesc.SampleDesc.Quality = m_x4MsaaQuality - 1;
	swapChainDesc.Windowed = true;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Flags = 0;
	IDXGIDevice *pDxgiDevice(NULL);
	m_Device->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&pDxgiDevice));
	IDXGIAdapter *pDxgiAdapter(NULL);
	pDxgiDevice->GetParent(__uuidof(IDXGIAdapter), reinterpret_cast<void**>(&pDxgiAdapter));
	IDXGIFactory *pDxgiFactory(NULL);
	pDxgiAdapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&pDxgiFactory));
	hr = pDxgiFactory->CreateSwapChain(m_Device, &swapChainDesc, &m_SwapChain);
	if (FAILED(hr))
		return false;
	pDxgiFactory->Release();
	pDxgiAdapter->Release();
	pDxgiDevice->Release();

	return true;
}

bool FrameBufferClass::initRenderTarget()
{
	HRESULT hr;
	//render target view
	ID3D11Texture2D *backBufferPtr;
	hr = m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBufferPtr);
	if (FAILED(hr))
		return false;
	hr = m_Device->CreateRenderTargetView(backBufferPtr, NULL, &m_RenderTargetView);
	if (FAILED(hr))
		return false;
	backBufferPtr->Release();
	backBufferPtr = NULL;
	return true;
}

bool FrameBufferClass::initDepthStencil()
{
	HRESULT hr;
	//depth stencil buffer&view
	D3D11_TEXTURE2D_DESC depthBufferDesc;
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
	ZeroMemory(&depthBufferDesc, sizeof(depthBufferDesc));
	depthBufferDesc.Width = m_ScreenWidth;
	depthBufferDesc.Height = m_ScreenHeight;
	depthBufferDesc.MipLevels = 1;
	depthBufferDesc.ArraySize = 1;
	depthBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthBufferDesc.SampleDesc.Count = m_SampleCount;
	depthBufferDesc.SampleDesc.Quality = m_x4MsaaQuality - 1;
	depthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	depthBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthBufferDesc.CPUAccessFlags = 0;
	depthBufferDesc.MiscFlags = 0;
	hr = m_Device->CreateTexture2D(&depthBufferDesc, NULL, &m_DepthStencilBuffer);
	if (FAILED(hr))
		return false;
	ZeroMemory(&depthStencilViewDesc, sizeof(depthStencilViewDesc));
	depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	if (m_x4Msaa)
		depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2DMS;
	else
		depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	depthStencilViewDesc.Texture2D.MipSlice = 0;//0->depth stencil not read only
	hr = m_Device->CreateDepthStencilView(m_DepthStencilBuffer, &depthStencilViewDesc, &m_DepthStencilView);
	if (FAILED(hr))
		return false;
	return true;
}


void FrameBufferClass::beginScene(ID3D11DeviceContext *dc, float red, float green, float blue, float alpha)
{
	float color[4];
	color[0] = red;
	color[1] = green;
	color[2] = blue;
	color[3] = alpha;

	dc->ClearRenderTargetView(m_RenderTargetView, color);
	dc->ClearDepthStencilView(m_DepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void FrameBufferClass::endScene()
{
	if (true)
	{
		m_SwapChain->Present(1, 0);
	}
	else
	{
		m_SwapChain->Present(0, 0);
	}
}

void FrameBufferClass::setRenderTarget(ID3D11DeviceContext *deviceContext)
{
	deviceContext->OMSetRenderTargets(1, &m_RenderTargetView, m_DepthStencilView);//output merger
}

ID3D11DepthStencilView* FrameBufferClass::getDepthStencilView()
{
	return m_DepthStencilView;
}