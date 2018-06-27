#pragma once
#include <dinput.h>
#include <iostream>

class InputClass
{
public:
	InputClass();
	~InputClass();

	bool init(HINSTANCE, HWND, int, int);
	void stop();
	bool frame();
	bool isEscapePressed();
	bool isLeftArrowPressed();
	bool isRightArrowPressed();
	void getMouseLocation(int&, int&);

private:
	bool readKeyboard();
	bool readMouse();
	void processInput();

private:
	IDirectInput8 *m_directInput;
	IDirectInputDevice8 *m_keyboard;
	IDirectInputDevice8 *m_mouse;

	unsigned char m_keyboardState[256];
	DIMOUSESTATE m_mouseState;

	int m_screenWidth, m_screenHeight;
	int m_mouseX, m_mouseY;
};