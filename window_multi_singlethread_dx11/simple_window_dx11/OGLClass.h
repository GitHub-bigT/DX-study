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
		sizeof(PIXELFORMATDESCRIPTOR), // ������ʽ�������Ĵ�С
		1,        	// �汾��
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,	// ���� RGBA ��ʽ
		32,
		0, 0, 0, 0, 0, 0,	// ���Ե�ɫ��λ
		0,	// ��Alpha����
		0,	// ����Shift Bit
		0,	// ���ۼӻ���
		0, 0, 0, 0,	// ���Ծۼ�λ
		0,	// 32λ Z-���� (��Ȼ���)
		0,	// ���ɰ建��
		0,	// �޸�������
		PFD_MAIN_PLANE,	// ����ͼ��
		0,	// Reserved
		0, 0, 0	// ���Բ�����
	};
	QVector<WindowData> m_WindowDataVec;
	QVector<HDC> m_WindowDCVec;
	HGLRC m_CommonGLRC;
	GLuint m_CommonVao;
	GLuint m_CommonProgram;
};