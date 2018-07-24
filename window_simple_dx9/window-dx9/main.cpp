#include <windows.h>    // include the basic windows header file
#include <iostream>
#include <vector>
#include "Graphics.h"

#pragma comment (lib, "d3d9.lib")

#define SCREEN_WIDTH 800 
#define SCREEN_HEIGHT 600

std::vector<WindowInfo> winVc;
std::vector<Graphics*> graVc;

// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam);
void createWindow(HINSTANCE hInstance, int nCmdShow);
void closeGraphics();

void createWindow(HINSTANCE hInstance, int nCmdShow)
{
	for (int i = 0; i < 1; i++)
	{
		WindowInfo wi;
		if (i == 0)
		{
			wi.v4.x = 0;
			wi.v4.y = 0;
		}
		if (i == 1)
		{
			wi.v4.x = 900;
			wi.v4.y = 100;
		}
		wi.isFull = false;
		wi.v4.width = SCREEN_WIDTH;
		wi.v4.height = SCREEN_HEIGHT;
		wi.threadNum = i;
		wi.hwnd = CreateWindowEx(NULL,
			L"WindowClass1",    // name of the window class
			L"ÖÐÎÄ",   // title of the window
					 //WS_EX_TOPMOST | WS_POPUP,    // window style
			WS_OVERLAPPEDWINDOW,
			wi.v4.x,    // x-position of the window
			wi.v4.y,    // y-position of the window
			wi.v4.width,    // width of the window
			wi.v4.height,    // height of the window
			NULL,    // we have no parent window, NULL
			NULL,    // we aren't using menus, NULL
			hInstance,    // application handle
			NULL);    // used with multiple windows, NULL
		ShowWindow(wi.hwnd, nCmdShow);
		Graphics *gra = new Graphics(wi);
		gra->start();
		graVc.push_back(gra);
		winVc.push_back(wi);
	}
}

// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	// this struct holds information for the window class
	WNDCLASSEX wc;

	// clear out the window class for use
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	// fill in the struct with the needed information
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = L"WindowClass1";
	// wc.hbrBackground =£¨HBRUSH£©COLOR_WINDOW;

	// register the window class
	RegisterClassEx(&wc);

	createWindow(hInstance, nCmdShow);

	// this struct holds Windows event messages
	MSG msg;

	// Enter the infinite message loop
	while (TRUE)
	{
		// Check to see if any messages are waiting in the queue
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Translate the message and dispatch it to WindowProc()
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// If the message is WM_QUIT, exit the while loop
		if (msg.message == WM_QUIT)
			break;
	}

	closeGraphics();

	// return this part of the WM_QUIT message to Windows
	return msg.wParam;
}

void closeGraphics()
{
	for (int i = 0; i < graVc.size(); i++)
	{
		Graphics *gra = graVc.at(i);
		gra->isRun = false;
		gra->wait();
		delete gra;
	}
}

// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// sort through and find what code to run for the message given
	switch (message)
	{
		// this message is read when the window is closed
	case WM_DESTROY:
	{
		// close the application entirely
		PostQuitMessage(0);
		return 0;
	} break;
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
			case VK_ESCAPE: DestroyWindow(hWnd); return 0;
				break;
			default:
				break;
		}
	}
	default:
		break;
	}

	// Handle any messages the switch statement didn't
	return DefWindowProc(hWnd, message, wParam, lParam);
}