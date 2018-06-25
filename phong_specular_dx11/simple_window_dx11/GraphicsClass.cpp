#include "GraphicsClass.h"

GraphicsClass::GraphicsClass()
{
	m_direct3DClass = 0;
	m_modelClass = 0;
	m_cameraClass = 0;
	m_textureShaderClass = 0;
	m_lightClass = 0;
}

GraphicsClass::~GraphicsClass()
{
}

bool GraphicsClass::init(int screenWidth, int screenHeight, HWND hWnd)
{
	bool result;

	m_direct3DClass = new D3DClass;
	if (!m_direct3DClass)
	{
		return false;
	}
	result = m_direct3DClass->init(screenWidth, screenHeight, VSYNC_ENABLED, hWnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hWnd, L"d3d11 init error", L"Error", MB_OK);
		return false;
	}

	m_cameraClass = new CameraClass;
	m_cameraClass->setPosition(0.0f, 0.0f, -7.0f);

	m_modelClass = new ModelClass;
	if (!m_modelClass)
	{
		return false;
	}
	result = m_modelClass->init(m_direct3DClass->getDevice(), m_direct3DClass->getDeviceContext(),
								L"../../source_image/metal/metal_2.jfif", "../../source_model/Sphere.obj");
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
	result = m_textureShaderClass->init(m_direct3DClass->getDevice(), hWnd);
	if (!result)
	{
		MessageBox(hWnd, L"shader init error", L"Error", MB_OK);
		return false;
	}

	m_lightClass = new LightClass;
	if (!m_lightClass)
	{
		return false;
	}
	m_lightClass->setDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_lightClass->setSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_lightClass->setAmbientColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_lightClass->setLightPosition(-0.3f, 1.3f, -2.0f);

	return true;
}

void GraphicsClass::stop()
{
	if (m_direct3DClass)
	{
		m_direct3DClass->stop();
		delete m_direct3DClass;
		m_direct3DClass = 0;
	}

	if (m_modelClass)
	{
		m_modelClass->stop();
		delete m_modelClass;
		m_modelClass = 0;
	}

	if (m_cameraClass)
	{
		delete m_cameraClass;
		m_cameraClass = 0;
	}

	if (m_textureShaderClass)
	{
		m_textureShaderClass->stop();
		delete m_textureShaderClass;
		m_textureShaderClass = 0;
	}

	if (m_lightClass)
	{
		delete m_lightClass;
		m_lightClass = 0;
	}
}

bool GraphicsClass::frame()
{
	bool result;
	static float rotation = 0.0f;

	rotation += XM_PI * 0.0001f;
	if (rotation > 360.0f)
		rotation = 0.0f;
	
	result = render(rotation);
	if (!result)
	{
		return false;
	}
	return true;
}

bool GraphicsClass::render(float rotation)
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
	bool result;
	m_direct3DClass->beginScene(0.5f, 0.5f, 0.5f, 1.0f);
	m_cameraClass->render();

	m_direct3DClass->getWorldMatrix(worldMatrix);
	m_cameraClass->getViewMatrix(viewMatrix);
	m_direct3DClass->getProjectionMatrix(projectionMatrix);
	//m_direct3D->getOrthoMatrix(projectionMatrix);

	//XMConvertToRadians(0.0f)
	XMMATRIX rotationMatrix = XMMatrixRotationY(rotation);

	for (int i = 0; i < m_modelClass->getMeshCount(); i++)
	{
		m_modelClass->render(m_direct3DClass->getDeviceContext(), i);

		result = m_textureShaderClass->render(m_direct3DClass->getDeviceContext(), m_modelClass->getIndexCount(i), m_modelClass->getTexture(),
			rotationMatrix, viewMatrix, projectionMatrix,
			m_lightClass->getLightPosition(), m_lightClass->getDiffuseColor(), m_lightClass->getAmbientColor(), m_lightClass->getSpecularColor(),
			m_cameraClass->getPosition());
		if (!result)
		{
			return false;
		}
	}

	m_direct3DClass->endScene();
	return true;
}