#include "StateManager.h"

StateManager::StateManager()
{
	m_DepthStencilState = 0;
	m_DepthDisabledStencilState = 0;
	m_RasterState = 0;
	m_AlphaEnableBlendState = 0;
	m_AlphaDisableBlendState = 0;
}

StateManager::~StateManager()
{
}

bool StateManager::init(ID3D11Device *device)
{
	HRESULT hr;
	//depth stencil test
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
	ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));
	depthStencilDesc.DepthEnable = true;
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;
	depthStencilDesc.StencilEnable = true;
	depthStencilDesc.StencilReadMask = 0xFF;
	depthStencilDesc.StencilWriteMask = 0xFF;
	depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
	depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
	hr = device->CreateDepthStencilState(&depthStencilDesc, &m_DepthStencilState);
	if (FAILED(hr))
		return false;
	depthStencilDesc.DepthEnable = false;
	hr = device->CreateDepthStencilState(&depthStencilDesc, &m_DepthDisabledStencilState);
	if (FAILED(hr))
		return false;

	//blend test
	D3D11_BLEND_DESC blendStateDescription;
	ZeroMemory(&blendStateDescription, sizeof(D3D11_BLEND_DESC));
	blendStateDescription.RenderTarget[0].BlendEnable = TRUE;
	blendStateDescription.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;//pixel shader's rgb * (a, a, a)
	blendStateDescription.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;//render target's rgb * (1-a, 1-a, 1-a)
	blendStateDescription.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;//+
	blendStateDescription.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ZERO;//pixel shader's a * 0
	blendStateDescription.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ONE;//render target's a * 1
	blendStateDescription.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;//+
	blendStateDescription.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
	hr = device->CreateBlendState(&blendStateDescription, &m_AlphaEnableBlendState);
	if (FAILED(hr))
		return false;
	blendStateDescription.RenderTarget[0].BlendEnable = FALSE;
	hr = device->CreateBlendState(&blendStateDescription, &m_AlphaDisableBlendState);
	if (FAILED(hr))
		return false;

	//raster state : same as default
	D3D11_RASTERIZER_DESC rasterDesc;
	ZeroMemory(&rasterDesc, sizeof(rasterDesc));
	rasterDesc.AntialiasedLineEnable = false;//ָ���Ƿ������з����; �������ڻ���������MultisampleEnableΪFALSE�������
	rasterDesc.MultisampleEnable = false;//ָ���Ƿ��ڶ��������ݣ�MSAA����ȾĿ����ʹ���ı��λ�alpha�߿�����㷨������ΪTRUE��ʹ���ı�������������㷨��������ΪFALSE��ʹ��alpha����������㷨
	rasterDesc.CullMode = D3D11_CULL_BACK;
	rasterDesc.DepthBias = 0;//���ƫ��:��3D�ռ��й���Ķ���ο���ͨ����ÿһ�����zƫ������ƫ�ʹ�俴�������񲻹��档
	rasterDesc.DepthBiasClamp = 0.0f;
	rasterDesc.SlopeScaledDepthBias = 0.0f;
	rasterDesc.DepthClipEnable = true;//Ӳ��ʼ��ִ�й�դ�������x��y���á���DepthClipEnable����ΪĬ��ֵTRUEʱ��Ӳ��������� zֵ
	rasterDesc.FillMode = D3D11_FILL_SOLID;
	rasterDesc.FrontCounterClockwise = false;//false:˳ʱ��Ϊ����ǰ��
	rasterDesc.ScissorEnable = false;//���ü��������޳����������������������ض��ᱻɾ����
	hr = device->CreateRasterizerState(&rasterDesc, &m_RasterState);
	if (FAILED(hr))
		return false;
}

void StateManager::stop()
{
	if (m_DepthStencilState)
	{
		m_DepthStencilState->Release();
		m_DepthStencilState = 0;
	}

	if (m_DepthDisabledStencilState)
	{
		m_DepthDisabledStencilState->Release();
		m_DepthDisabledStencilState = 0;
	}

	if (m_AlphaEnableBlendState)
	{
		m_AlphaEnableBlendState->Release();
		m_AlphaEnableBlendState = 0;
	}

	if (m_AlphaDisableBlendState)
	{
		m_AlphaDisableBlendState->Release();
		m_AlphaDisableBlendState = 0;
	}

	if (m_RasterState)
	{
		m_RasterState->Release();
		m_RasterState = 0;
	}
}

void StateManager::turnZBufferOn(ID3D11DeviceContext *deviceContext)
{
	deviceContext->OMSetDepthStencilState(m_DepthStencilState, 1);
}

void StateManager::turnZBufferOff(ID3D11DeviceContext *deviceContext)
{
	deviceContext->OMSetDepthStencilState(m_DepthDisabledStencilState, 1);
}

void StateManager::turnOnAlphaBlending(ID3D11DeviceContext *deviceContext)
{
	float blendFactor[4];

	// Setup the blend factor.
	blendFactor[0] = 0.0f;
	blendFactor[1] = 0.0f;
	blendFactor[2] = 0.0f;
	blendFactor[3] = 0.0f;

	// Turn on the alpha blending.
	deviceContext->OMSetBlendState(m_AlphaEnableBlendState, blendFactor, 0xffffffff);
}

void StateManager::turnOffAlphaBlending(ID3D11DeviceContext *deviceContext)
{
	float blendFactor[4];

	// Setup the blend factor.
	blendFactor[0] = 0.0f;
	blendFactor[1] = 0.0f;
	blendFactor[2] = 0.0f;
	blendFactor[3] = 0.0f;

	// Turn on the alpha blending.
	deviceContext->OMSetBlendState(m_AlphaDisableBlendState, blendFactor, 0xffffffff);
}