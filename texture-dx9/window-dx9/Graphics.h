#pragma once
#include <QThread>
#include <d3d9.h>
#include <d3dx9.h>
//#include <winerror.h>
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

class Graphics : public QThread
{
public:
	bool isRun;
	Graphics(WindowInfo wi);
	~Graphics();
protected:

private:
	HWND hwnd;
	int thread_num;
	int color;
	bool isFull;
	int x, y, width, height;
	LPDIRECT3D9 d3d9;
	LPDIRECT3DDEVICE9 d3d9_deivice;
	LPDIRECT3DVERTEXBUFFER9 v_buffer;
	LPDIRECT3DTEXTURE9 tex;
	void initD3D();
	void initGraphics();
	void render();
	void clean3D();
	void run();
	void joinSwapGroup();
	void timer_start(FILETIME *start);
	int64_t timer_elapsed_msec(FILETIME *start);
	int64_t timer_elapsed_usec(FILETIME *start);
};
