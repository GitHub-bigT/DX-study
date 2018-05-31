#pragma once
#define GLEW_STATIC
#include <QThread>
#include <d3d9.h>
#include <d3dx9.h>
//#include <winerror.h>
#include <stb_image.h>
#include <glew.h>
#include <wglew.h>
#include "nvapi.h"

#define CUSTOMFVF D3DFVF_XYZRHW | D3DFVF_TEX1

struct Vec4
{
	int x;
	int y;
	int width;
	int height;
};

struct WindowInfo
{
	int threadNum;
	Vec4 v4;
	HWND hwnd;
	bool isFull;
};

struct CUSTOMVERTEX
{
	FLOAT x, y, z, rhw;
	FLOAT u, v;
};

static PIXELFORMATDESCRIPTOR pfd =
{
	sizeof(PIXELFORMATDESCRIPTOR), // ������ʽ�������Ĵ�С
	1,        				// �汾��
	PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
	PFD_TYPE_RGBA,			// ���� RGBA ��ʽ
	32,
	0, 0, 0, 0, 0, 0,		// ���Ե�ɫ��λ
	0,						// ��Alpha����
	0,						// ����Shift Bit
	0,						// ���ۼӻ���
	0, 0, 0, 0,				// ���Ծۼ�λ
	0,						// 32λ Z-���� (��Ȼ���)
	0,						// ���ɰ建��
	0,						// �޸�������
	PFD_MAIN_PLANE,			// ����ͼ��
	0,						// Reserved
	0, 0, 0					// ���Բ�����
};

class Graphics : public QThread
{
public:
	bool isRun;
	Graphics(WindowInfo wi);
	~Graphics();
protected:

private:
	HWND hwnd;
	HDC ogl_dc;
	HGLRC ogl_rc;
	int thread_num;
	int color;
	bool isFull;
	int x, y, width, height;
	HANDLE ogl_handleD3D;
	HANDLE ogl_handleD3DTex;
	int im_width, im_height;
	unsigned char *data;
	
	//dx
	LPDIRECT3D9EX d3d9;
	LPDIRECT3DDEVICE9EX d3d9_deivice;
	LPDIRECT3DVERTEXBUFFER9 v_buffer;
	LPDIRECT3DTEXTURE9 dx_tex1;
	LPDIRECT3DTEXTURE9 dx_tex2;
	void initD3D();
	void initDxTex();
	void renderDX();
	void clean3D();
	void run();
	void joinSwapGroup();
	//gl
	GLuint ogl_tex1;
	GLuint ogl_fbo;
	int setupPixelFormat(HDC hDC);
	void initGL();
	void initGLTex();
	void renderGL();
	GLuint loadTexture(char const * path);

	void initInterOp();
	void checkError();
	void timer_start(FILETIME *start);
	void dump_texture(GLuint texture_id);
	int64_t timer_elapsed_msec(FILETIME *start);
	int64_t timer_elapsed_usec(FILETIME *start);
};
