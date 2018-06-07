#include "GraphicsClass.h"

GraphicsClass::GraphicsClass()
{
	m_direct3D = 0;
	m_bitmap = 0;
	m_camera = 0;
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

	m_camera = new CameraClass;
	m_camera->setPosition(0.0f, 0.0f, -10.0f);

	m_bitmap = new ModelClass;
	if (!m_bitmap)
	{
		return false;
	}
	result = m_bitmap->init(m_direct3D->getDevice(), m_direct3D->getDeviceContext(), screenWidth, screenHeight, "../../image_source/wood.png", 256, 256);
	if (!result)
	{
		MessageBox(hWnd, L"model init error", L"Error", MB_OK);
		return false;
	}

	m_textureShader = new TextureShaderClass;
	if (!m_textureShader)
	{
		return false;
	}
	result = m_textureShader->init(m_direct3D->getDevice(), hWnd);
	if (!result)
	{
		MessageBox(hWnd, L"shader init error", L"Error", MB_OK);
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

	if (m_bitmap)
	{
		m_bitmap->stop();
		delete m_bitmap;
		m_bitmap = 0;
	}

	if (m_camera)
	{
		delete m_camera;
		m_camera = 0;
	}

	if (m_textureShader)
	{
		m_textureShader->stop();
		delete m_textureShader;
		m_textureShader = 0;
	}
}

bool GraphicsClass::frame()
{
	bool result;
	result = render();
	if (!result)
	{
		return false;
	}
	return true;
}

float offset = 0;
float speed = 0.5f;
bool GraphicsClass::render()
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, orthoMatrix;
	bool result;
	m_direct3D->beginScene(0.5f, 0.5f, 0.5f, 1.0f);
	m_camera->render();

	m_direct3D->getWorldMatrix(worldMatrix);
	m_camera->getViewMatrix(viewMatrix);
	m_direct3D->getProjectionMatrix(projectionMatrix);
	m_direct3D->getOrthoMatrix(orthoMatrix);

	////....start render 2d
	m_direct3D->turnZBufferOff();
	if (offset > 800.0f - 256.0f || offset < 0)
		speed = -speed;
	offset += speed;
	m_bitmap->render(m_direct3D->getDeviceContext(), offset, 100);
	result = m_textureShader->render(m_direct3D->getDeviceContext(), m_bitmap->getIndexCount(), m_bitmap->getTexture(), worldMatrix, viewMatrix, orthoMatrix);
	if (!result)
	{
		return false;
	}

	m_direct3D->turnZBufferOn();
	//....start render 3d

	m_direct3D->endScene();
	return true;
}