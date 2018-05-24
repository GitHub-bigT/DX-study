#pragma once
#include <QThread>
#include <d3d9.h>

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
	void initD3D();
	void render();
	void clean3D();
	void run();

};
