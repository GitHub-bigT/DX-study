#include "GraphicsClass.h"

GraphicsClass::GraphicsClass()
{
	m_direct3D = 0;
	m_ModelClass = 0;
	m_SimpleShader = 0;
}

GraphicsClass::~GraphicsClass()
{
}

bool GraphicsClass::init(int screenWidth, int screenHeight, HWND hWnd)
{
	bool result;

	m_direct3D = new D3DClass;
	if (!m_direct3D)
	{
		return false;
	}
	result = m_direct3D->init(screenWidth, screenHeight, VSYNC_ENABLED, hWnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hWnd, L"m_direct3D init error", L"Error", MB_OK);
		return false;
	}

	m_ModelClass = new ModelClass;
	result = m_ModelClass->init(m_direct3D->getDevice());
	if (!result)
	{
		MessageBox(hWnd, L"m_ModelClass init error", L"Error", MB_OK);
		return false;
	}

	m_SimpleShader = new SimpleShader;
	result = m_SimpleShader->init(m_direct3D->getDevice());
	if (!result)
	{
		MessageBox(hWnd, L"m_SimpleShader init error", L"Error", MB_OK);
		return false;
	}

	return true;
}

void GraphicsClass::stop()
{
	if (m_direct3D)
	{
		m_direct3D->stop();
		delete m_direct3D;
		m_direct3D = 0;
	}

	if (m_ModelClass)
	{
		m_ModelClass->stop();
		delete m_ModelClass;
		m_ModelClass = 0;
	}

	if (m_SimpleShader)
	{
		m_SimpleShader->stop();
		delete m_SimpleShader;
		m_SimpleShader = 0;
	}
}

bool GraphicsClass::render(ID3D11ShaderResourceView *tex)
{
	m_direct3D->beginScene(1.0f, 1.0f, 0.0f, 1.0f);

	if (tex != NULL)
	{
		m_direct3D->getDeviceContext()->PSSetShaderResources(0, 1, &tex);
	}

	m_SimpleShader->render(m_direct3D->getDeviceContext());

	m_ModelClass->render(m_direct3D->getDeviceContext());

	return true;
}

bool GraphicsClass::swap()
{
	m_direct3D->endScene();
	return true;
}

ID3D11Device* GraphicsClass::getDevice()
{
	return m_direct3D->getDevice();
}

ID3D11DeviceContext* GraphicsClass::getDeviceContext()
{
	return m_direct3D->getDeviceContext();
}