#include "GraphicsClass.h"

GraphicsClass::GraphicsClass()
{
	m_direct3D = 0;
	m_Ogl = 0;
}

GraphicsClass::~GraphicsClass()
{
}

bool GraphicsClass::init(QVector<WindowData> &wdv)
{
	bool result;

	m_WindowDataVec = wdv;

	m_direct3D = new D3DClass;
	if (!m_direct3D)
	{
		return false;
	}
/*
	result = m_direct3D->init(screenWidth, screenHeight, VSYNC_ENABLED, hWnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hWnd, L"d3d11 init error", L"Error", MB_OK);
		return false;
	}*/
	m_Ogl = new OGLClass;
	m_Ogl->init(wdv, VSYNC_ENABLED, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);

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
}

bool GraphicsClass::render()
{
	m_Ogl->beginScene(1.0f, 1.0f, 0.0f, 1.0f);
	return true;
}

bool GraphicsClass::swap()
{
	m_Ogl->endScene();
	return true;
}