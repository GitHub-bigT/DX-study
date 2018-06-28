#include "GraphicsClass.h"

GraphicsClass::GraphicsClass()
{
	m_direct3D = 0;
	m_fpsTextClass = 0;
	m_cpuTextClass = 0;
	m_frametimeTextClass = 0;
	m_modelClass = 0;
	m_cameraClass = 0;
	m_textureShaderClass = 0;
	m_renderModelListClass = 0;
	m_renderModelCountTextClass = 0;
	m_modelCount = 0;
	m_frustumClass = 0;
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
	result = m_direct3D->init(screenWidth, screenHeight, VSYNC_ENABLED, MSAA_ENABLED, hWnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
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

	m_renderModelCountTextClass = new TextClass;
	if (!m_renderModelCountTextClass)
	{
		return false;
	}
	result = m_renderModelCountTextClass->init(m_direct3D->getDevice(), m_direct3D->getDeviceContext(), hWnd, screenWidth, screenHeight);
	if (!result)
	{
		return false;
	}

	m_cameraClass = new CameraClass;
	if (!m_cameraClass)
	{
		return false;
	}
	m_cameraClass->setPosition(0.0f, 0.0f, -10.0f);

	m_modelClass = new ModelClass;
	if (!m_modelClass)
	{
		return false;
	}
	//../../source_model/Sphere_32.obj
	//../../source_model/cube.obj
	result = m_modelClass->init(m_direct3D->getDevice(), m_direct3D->getDeviceContext(), 
		L"../../source_image/seafloor.dds", "../../source_model/sphere_32.obj");
	if (!result)
	{
		MessageBox(hWnd, L"model init error", L"Error", MB_OK);
		return false;
	}

	m_textureShaderClass = new TextureShaderClass;
	if (!m_textureShaderClass)
	{
		return false;
	}
	result = m_textureShaderClass->init(m_direct3D->getDevice(), hWnd);
	if (!result)
	{
		MessageBox(hWnd, L"textureShaderClass init error", L"Error", MB_OK);
		return false;
	}

	m_renderModelListClass = new ModelListClass;
	if (!m_renderModelListClass)
	{
		return false;
	}
	result = m_renderModelListClass->init(25);
	if (!result)
	{
		return false;
	}

	m_frustumClass = new FrustumClass;
	if (!m_frustumClass)
	{
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

	if (m_renderModelCountTextClass)
	{
		m_renderModelCountTextClass->stop();
		delete m_renderModelCountTextClass;
		m_renderModelCountTextClass = 0;
	}

	if (m_textureShaderClass)
	{
		m_textureShaderClass->stop();
		delete m_textureShaderClass;
		m_textureShaderClass = 0;
	}

	if (m_cameraClass)
	{
		delete m_cameraClass;
		m_cameraClass = 0;
	}

	if (m_renderModelListClass)
	{
		m_renderModelListClass->stop();
		delete m_renderModelListClass;
		m_renderModelListClass = 0;
	}

	if (m_frustumClass)
	{
		delete m_frustumClass;
		m_frustumClass = 0;
	}
}

bool GraphicsClass::frame(int fps, int cpu, float frametime, float rotationY)
{
	bool result;

	m_cameraClass->setRotation(0.0f, rotationY, 0.0f);

	result = render(fps, cpu, frametime);
	if (!result)
	{
		return false;
	}
	return true;
}

bool GraphicsClass::renderSystemInfoFont(int fps, int cpu, float frametime)
{
	bool result;

	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, orthoMatrix;
	m_direct3D->getProjectionMatrix(projectionMatrix);
	m_direct3D->getOrthoMatrix(orthoMatrix);

	m_direct3D->turnZBufferOff();
	m_direct3D->turnOnAlphaBlending();

	char fpsText[20];
	char cpuText[20];
	char frametimeText[30];
	char modelCountText[30];
	sprintf(fpsText, "Fps = %d", fps);
	sprintf(cpuText, "Cpu = %d%%", cpu);
	if (frametime > 99.998)
		frametime = 100.0f;
	sprintf(frametimeText, "FrameTime = %.1f ms", frametime);
	sprintf(modelCountText, "modelCountText = %d", m_modelCount);

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

	result = m_renderModelCountTextClass->updateSentence(modelCountText, 5, 50, 1.0f, 1.0f, 1.0f, m_direct3D->getDeviceContext());
	if (!result)
		return false;
	result = m_renderModelCountTextClass->render(m_direct3D->getDeviceContext(), orthoMatrix);
	if (!result)
		return false;

	return true;
}

bool GraphicsClass::renderScene()
{
	bool result;
	m_cameraClass->render();
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
	m_direct3D->getWorldMatrix(worldMatrix);
	m_cameraClass->getViewMatrix(viewMatrix);
	m_direct3D->getProjectionMatrix(projectionMatrix);
	//构建frustum，准备进行furstum cull
	m_frustumClass->constructFrustum(SCREEN_DEPTH, projectionMatrix, viewMatrix);

	static float rotation = 0.0f;

	rotation += XM_PI * 0.001f;
	if (rotation > 360.0f)
		rotation = 0.0f;
	XMMATRIX rotationMatrix = XMMatrixRotationY(rotation);

	m_direct3D->turnZBufferOn();
	m_direct3D->turnOffAlphaBlending();
	//....start render 3d
	m_modelCount = 0;
	for (int modelIndex = 0; modelIndex < m_renderModelListClass->getModelCount(); modelIndex++)
	{
		
		m_modelCount++;
		float offset_x, offset_y, offset_z;
		XMFLOAT4 color;
		m_renderModelListClass->getData(modelIndex, offset_x, offset_y, offset_z, color);

		XMMATRIX translateMatrix = XMMatrixTranslation(offset_x, offset_y, offset_z);

		for (int i = 0; i < m_modelClass->getMeshCount(); i++)
		{
			m_modelClass->render(m_direct3D->getDeviceContext(), i);
			result = m_textureShaderClass->render(m_direct3D->getDeviceContext(), m_modelClass->getIndexCount(i),
				translateMatrix, viewMatrix, projectionMatrix, color, m_modelClass->getTexture());
			if (!result)
			{
				return false;
			}
		}
	}

	return true;
}

bool GraphicsClass::render(int fps, int cpu, float frametime)
{
	m_direct3D->beginScene(0.0f, 0.0f, 0.0f, 1.0f);

	//start render 3d
	if (!renderScene())
		return false;

	//start render 2d font
	if (!renderSystemInfoFont(fps, cpu, frametime))
		return false;

	m_direct3D->endScene();
	return true;
}