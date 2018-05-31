#include "Graphics.h"

Graphics::Graphics(WindowInfo wi)
{
	this->thread_num = wi.threadNum;
	this->x = wi.v4.x;
	this->y = wi.v4.y;
	this->width = wi.v4.width;
	this->height = wi.v4.height;
	this->hwnd = wi.hwnd;
	this->isFull = wi.isFull;
	this->isRun = true;
	this->d3d9 = NULL;
	this->d3d9_deivice = NULL;
	this->color = 0;
}

Graphics::~Graphics()
{
}

void Graphics::run()
{
	printf("thread_num = %d\n", thread_num);
	initD3D();
	while (isRun)
	{
		render();
	}
	clean3D();
}

void Graphics::initD3D()
{
	d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = isFull ? FALSE : TRUE; //程序全屏，没有窗口
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; //丢弃旧的帧
	d3dpp.hDeviceWindow = hwnd; //设置Direct3D使用的窗口
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8; //将后台缓冲区格式设置为32位
	d3dpp.BackBufferWidth = width; //设置缓冲区的宽度
	d3dpp.BackBufferHeight = height; //设置缓冲区的高度

	d3d9->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hwnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &d3d9_deivice);
}

void Graphics::render()
{
	color = color ? 0 : 255;
	//d3d9_deivice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 0, 0), 1.0f, 0);
	d3d9_deivice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(color, color, color), 1.0f, 0);
	d3d9_deivice->BeginScene();
	d3d9_deivice->EndScene();
	Sleep(30);
	d3d9_deivice->Present(NULL, NULL, NULL, NULL);
}

void Graphics::clean3D()
{
	d3d9_deivice->Release();
	d3d9->Release();
}