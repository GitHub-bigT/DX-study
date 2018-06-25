#include "InputClass.h"

InputClass::InputClass()
{
	m_directInput = 0;
	m_keyboard = 0;
	m_mouse = 0;
}

InputClass::~InputClass()
{
}

bool InputClass::init(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight)
{
	HRESULT hr;
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	m_mouseX = 0;
	m_mouseY = 0;

	hr = DirectInput8Create(hinstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_directInput, NULL);
	if (FAILED(hr))
		return false;
	//keyboard
	hr = m_directInput->CreateDevice(GUID_SysKeyboard, &m_keyboard, NULL);
	if (FAILED(hr))
		return false;
	hr = m_keyboard->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr))
		return false;
	hr = m_keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE);
	if (FAILED(hr))
		return false;
	hr = m_keyboard->Acquire();
	if (FAILED(hr))
		return false;
	//mouse
	hr = m_directInput->CreateDevice(GUID_SysMouse, &m_mouse, NULL);
	if (FAILED(hr))
		return false;
	hr = m_mouse->SetDataFormat(&c_dfDIMouse);
	if (FAILED(hr))
		return false;
	hr = m_mouse->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(hr))
		return false;
	hr = m_mouse->Acquire();
	if (FAILED(hr))
		return false;

	return true;
}

void InputClass::stop()
{
	if (m_keyboard)
	{
		m_keyboard->Unacquire();
		m_keyboard->Release();
		m_keyboard = 0;
	}

	if (m_mouse)
	{
		m_mouse->Unacquire();
		m_mouse->Release();
		m_mouse = 0;
	}

	if (m_directInput)
	{
		m_directInput->Release();
		m_directInput = 0;
	}
}

bool InputClass::frame()
{
	bool result;

	result = readKeyboard();
	if (!result)
	{
		return false;
	}

	result = readMouse();
	if (!result)
	{
		return false;
	}

	processInput();

	return true;
}

bool InputClass::isEscapePressed()
{
	if (m_keyboardState[DIK_ESCAPE] & 0x80)
	{
		return true;
	}
	return false;
}

void InputClass::getMouseLocation(int &mouseX, int &mouseY)
{
	mouseX = m_mouseX;
	mouseY = m_mouseY;
}

bool InputClass::readKeyboard()
{
	HRESULT hr;
	hr = m_keyboard->GetDeviceState(sizeof(m_keyboardState), (LPVOID)&m_keyboardState);
	if (FAILED(hr))
	{
		if ((hr == DIERR_INPUTLOST) || (hr == DIERR_NOTACQUIRED))
		{
			m_keyboard->Acquire();
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool InputClass::readMouse()
{
	HRESULT result;

	result = m_mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&m_mouseState);
	if (FAILED(result))
	{
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
		{
			m_mouse->Acquire();
		}
		else
		{
			return false;
		}
	}

	return true;
}

void InputClass::processInput()
{
	// Update the location of the mouse cursor based on the change of the mouse location during the frame.
	m_mouseX += m_mouseState.lX;
	m_mouseY += m_mouseState.lY;

	// Ensure the mouse location doesn't exceed the screen width or height.
	if (m_mouseX < 0) { m_mouseX = 0; }
	if (m_mouseY < 0) { m_mouseY = 0; }

	if (m_mouseX > m_screenWidth) { m_mouseX = m_screenWidth; }
	if (m_mouseY > m_screenHeight) { m_mouseY = m_screenHeight; }
	//if (m_mouseState.lX != 0 || m_mouseState.lY != 0)
		//printf("m_mouseX = %d, m_mouseY = %d, m_mouseState.lX = %d, m_mouseState.lY=%d\n", m_mouseX, m_mouseY, m_mouseState.lX, m_mouseState.lY);
}