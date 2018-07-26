#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <glew.h>
#include <QVector>

struct WindowData
{
	int x;
	int y;
	int width;
	int height;
	int gpu;
	int number;
	HWND hwnd;
	LPCWSTR applicationName;
	HINSTANCE hinstance;
};

class OGLClass
{
public:
	OGLClass();
	~OGLClass();
	bool init(QVector<WindowData> &wdv, bool vsync, bool fullscreen, float screenDepth, float screenNear);
	void stop();
	void beginScene(float, float, float, float);
	void endScene();

private:
	int setupPixelFormat(HDC hDC);
	void initQuad();
	GLuint initShader(const char* shaderSource, GLenum shaderType);
	char* readFile(char* filePath);
	GLuint initProgram(const char* vertexShaderSource, const char* fragShaderSource);

private:
	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR), // 上述格式描述符的大小
		1,        	// 版本号
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,	// 申请 RGBA 格式
		32,
		0, 0, 0, 0, 0, 0,	// 忽略的色彩位
		0,	// 无Alpha缓存
		0,	// 忽略Shift Bit
		0,	// 无累加缓存
		0, 0, 0, 0,	// 忽略聚集位
		0,	// 32位 Z-缓存 (深度缓存)
		0,	// 无蒙板缓存
		0,	// 无辅助缓存
		PFD_MAIN_PLANE,	// 主绘图层
		0,	// Reserved
		0, 0, 0	// 忽略层遮罩
	};
	QVector<WindowData> m_WindowDataVec;
	QVector<HDC> m_WindowDCVec;
	HGLRC m_CommonGLRC;
	GLuint m_CommonVao;
	GLuint m_CommonProgram;
};