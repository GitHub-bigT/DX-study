#include "GraphicsClass.h"

GraphicsClass::GraphicsClass()
{
	m_direct3D = 0;
	m_fpsTextClass = 0;
	m_cpuTextClass = 0;
	m_frametimeTextClass = 0;
	m_modelClass = 0;
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

	m_fpsTextClass = new TextClass;
	if (!m_fpsTextClass)
	{
		return false;
	}
	result = m_fpsTextClass->init(m_direct3D->getDevice(), m_direct3D->getDeviceContext(), hWnd, screenWidth, screenHeight);
	if (!result)
	{
		MessageBox(hWnd, L"fpsTextClass init error", L"Error", MB_OK);
		return false;
	}

	m_cpuTextClass = new TextClass;
	if (!m_cpuTextClass)
	{
		return false;
	}
	result = m_cpuTextClass->init(m_direct3D->getDevice(), m_direct3D->getDeviceContext(), hWnd, screenWidth, screenHeight);
	if (!result)
	{
		MessageBox(hWnd, L"cpuTextClass init error", L"Error", MB_OK);
		return false;
	}

	m_frametimeTextClass = new TextClass;
	if (!m_frametimeTextClass)
	{
		return false;
	}
	result = m_frametimeTextClass->init(m_direct3D->getDevice(), m_direct3D->getDeviceContext(), hWnd, screenWidth, screenHeight);
	if (!result)
	{
		MessageBox(hWnd, L"frametimeTextClass init error", L"Error", MB_OK);
		return false;
	}

	m_modelClass = new ModelClass;
	if (!m_modelClass)
	{
		return false;
	}
	result = m_modelClass->init(m_direct3D->getDevice(), m_direct3D->getDeviceContext(), 
		L"../../source_image/seafloor.dds", "../../source_model/cube.txt");
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

	if (m_fpsTextClass)
	{
		m_fpsTextClass->stop();
		delete m_fpsTextClass;
		m_fpsTextClass = 0;
	}

	if (m_cpuTextClass)
	{
		m_cpuTextClass->stop();
		delete m_cpuTextClass;
		m_cpuTextClass = 0;
	}

	if (m_frametimeTextClass)
	{
		m_frametimeTextClass->stop();
		delete m_frametimeTextClass;
		m_frametimeTextClass = 0;
	}
}

bool GraphicsClass::frame(int fps, int cpu, float frametime)
{
	bool result;
	result = render(fps, cpu, frametime);
	if (!result)
	{
		return false;
	}
	return true;
}

bool GraphicsClass::render(int fps, int cpu, float frametime)
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, orthoMatrix;
	bool result;
	m_direct3D->beginScene(0.0f, 0.0f, 0.0f, 1.0f);

	m_direct3D->getProjectionMatrix(projectionMatrix);
	m_direct3D->getOrthoMatrix(orthoMatrix);

	////....start render 2d
	m_direct3D->turnZBufferOff();
	m_direct3D->turnOnAlphaBlending();

	char fpsText[20];
	char cpuText[20];
	char frametimeText[30];
	sprintf(fpsText, "Fps = %d", fps);
	sprintf(cpuText, "Cpu = %d%%", cpu);
	if (frametime > 99.998)
		frametime = 100.0f;
	sprintf(frametimeText, "FrameTime = %.1f ms", frametime);

	result = m_fpsTextClass->updateSentence(fpsText, 5, 5, 1.0f, 1.0f, 0.0f, m_direct3D->getDeviceContext());
	if (!result)
		return false;
	result = m_fpsTextClass->render(m_direct3D->getDeviceContext(), orthoMatrix);
	if (!result)
		return false;

	result = m_cpuTextClass->updateSentence(cpuText, 5, 20, 1.0f, 1.0f, 0.0f, m_direct3D->getDeviceContext());
	if (!result)
		return false;
	result = m_cpuTextClass->render(m_direct3D->getDeviceContext(), orthoMatrix);
	if (!result)
		return false;

	result = m_frametimeTextClass->updateSentence(frametimeText, 5, 35, 1.0f, 1.0f, 0.0f, m_direct3D->getDeviceContext());
	if (!result)
		return false;
	result = m_frametimeTextClass->render(m_direct3D->getDeviceContext(), orthoMatrix);
	if (!result)
		return false;

	m_direct3D->turnOffAlphaBlending();
	m_direct3D->turnZBufferOn();
	//....start render 3d

	m_direct3D->endScene();
	return true;
}