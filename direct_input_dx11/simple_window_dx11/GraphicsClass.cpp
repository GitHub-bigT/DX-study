#include "GraphicsClass.h"

GraphicsClass::GraphicsClass()
{
	m_direct3D = 0;
	m_textClass = 0;
	m_textClass2 = 0;
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
		MessageBox(hWnd, L"d3d11 init error", L"Error", MB_OK);
		return false;
	}

	m_textClass = new TextClass;
	if (!m_textClass)
	{
		return false;
	}
	result = m_textClass->init(m_direct3D->getDevice(), m_direct3D->getDeviceContext(), hWnd, screenWidth, screenHeight);
	if (!result)
	{
		MessageBox(hWnd, L"model init error", L"Error", MB_OK);
		return false;
	}

	m_textClass2 = new TextClass;
	if (!m_textClass2)
	{
		return false;
	}
	result = m_textClass2->init(m_direct3D->getDevice(), m_direct3D->getDeviceContext(), hWnd, screenWidth, screenHeight);
	if (!result)
	{
		MessageBox(hWnd, L"model init error", L"Error", MB_OK);
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

	if (m_textClass)
	{
		m_textClass->stop();
		delete m_textClass;
		m_textClass = 0;
	}

	if (m_textClass2)
	{
		m_textClass2->stop();
		delete m_textClass2;
		m_textClass2 = 0;
	}
}

bool GraphicsClass::frame(int mouseX, int mouseY)
{
	bool result;
	result = render(mouseX, mouseY);
	if (!result)
	{
		return false;
	}
	return true;
}

bool GraphicsClass::render(int mouseX, int mouseY)
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, orthoMatrix;
	bool result;
	m_direct3D->beginScene(0.0f, 0.0f, 0.0f, 1.0f);

	m_direct3D->getProjectionMatrix(projectionMatrix);
	m_direct3D->getOrthoMatrix(orthoMatrix);

	////....start render 2d
	m_direct3D->turnZBufferOff();
	m_direct3D->turnOnAlphaBlending();

	char cMouseX[20];
	char cMouseY[20];
	sprintf(cMouseX, "xPos = %d", mouseX);
	sprintf(cMouseY, "yPos = %d", mouseY);
	result = m_textClass->updateSentence(cMouseX, 100, 100, 1.0f, 1.0f, 0.0f, m_direct3D->getDeviceContext());
	if (!result)
		return false;
	result = m_textClass->render(m_direct3D->getDeviceContext(), orthoMatrix);
	if (!result)
		return false;

	result = m_textClass2->updateSentence(cMouseY, 100, 120, 1.0f, 0.0f, 0.0f, m_direct3D->getDeviceContext());
	if (!result)
		return false;
	result = m_textClass2->render(m_direct3D->getDeviceContext(), orthoMatrix);
	if (!result)
		return false;

	m_direct3D->turnOffAlphaBlending();
	m_direct3D->turnZBufferOn();
	//....start render 3d

	m_direct3D->endScene();
	return true;
}