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
	rasterDesc.AntialiasedLineEnable = false;//指定是否启用行反锯齿; 仅适用于绘制线条和MultisampleEnable为FALSE的情况。
	rasterDesc.MultisampleEnable = false;//指定是否在多采样抗锯齿（MSAA）渲染目标上使用四边形或alpha线抗锯齿算法。设置为TRUE以使用四边形线消除锯齿算法，并设置为FALSE以使用alpha线消除锯齿算法
	rasterDesc.CullMode = D3D11_CULL_BACK;
	rasterDesc.DepthBias = 0;//深度偏差:在3D空间中共面的多边形可以通过向每一个添加z偏差（或深度偏差）使其看起来好像不共面。
	rasterDesc.DepthBiasClamp = 0.0f;
	rasterDesc.SlopeScaledDepthBias = 0.0f;
	rasterDesc.DepthClipEnable = true;//硬件始终执行光栅化坐标的x和y剪裁。当DepthClipEnable设置为默认值TRUE时，硬件还会剪切 z值
	rasterDesc.FillMode = D3D11_FILL_SOLID;
	rasterDesc.FrontCounterClockwise = false;//false:顺时针为面向前方
	rasterDesc.ScissorEnable = false;//启用剪刀矩形剔除。活动剪刀矩形外的所有像素都会被删除。
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