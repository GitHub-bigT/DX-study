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
	initGraphics();
	while (isRun)
	{
		render();
	}
	clean3D();
}

void Graphics::joinSwapGroup()
{
	NvAPI_Status status = NVAPI_OK;
	NvU32 m_GSyncSwapGroups = 0, m_GSyncBarriers = 0;
	status = NvAPI_D3D9_QueryMaxSwapGroup(d3d9_deivice, &m_GSyncSwapGroups, &m_GSyncBarriers);
	printf("m_GSyncSwapGroups = %d, m_GSyncBarriers = %d\n", m_GSyncSwapGroups, m_GSyncBarriers);

	IDirect3DSwapChain9 *pSwapChain;

	if (SUCCEEDED(d3d9_deivice->GetSwapChain(0, &pSwapChain)))
	{
/*
		NvAPI_Status status = NvAPI_D3D9_JoinSwapGroup(d3d9_deivice, pSwapChain, m_GSyncSwapGroups, (m_GSyncSwapGroups > 0));
		if (status == NVAPI_OK)
		{
			printf("join success\n");
		}*/
		pSwapChain->Release();
	}
}

void Graphics::initGraphics()
{
	HRESULT hr;
	CUSTOMVERTEX vertices[] = { {0.0f, 300.0f, 1.0f, 1.0f, D3DCOLOR_XRGB(0, 0, 255)},
								{400.0f, 600.0f, 1.0f, 1.0f, D3DCOLOR_XRGB(0, 255, 0)},
								{0.0f, 600.0f, 1.0f, 1.0f, D3DCOLOR_XRGB(255, 0, 0)},
								{0.0f, 300.0f, 1.0f, 1.0f, D3DCOLOR_XRGB(0, 0, 255)},
								{400.0f, 300.0f, 1.0f, 1.0f, D3DCOLOR_XRGB(0, 255, 0)},
								{400.0f, 600.0f, 1.0f, 1.0f, D3DCOLOR_XRGB(255, 0, 0)},
							};//逆时针剔除
	hr = d3d9_deivice->CreateVertexBuffer(sizeof(vertices), 0, CUSTOMFVF, D3DPOOL_MANAGED, &v_buffer, NULL);
	VOID *pVoid;
	v_buffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices, sizeof(vertices));//glbufferdata
	v_buffer->Unlock();
/*
	CUSTOMVERTEX vertices[] =
	{
		{0.0f, 0.0f, 1.0f},
		{1.0f, 1.0f, 1.0f},
		{0.0f, 1.0f, 1.0f},
	};
	printf("vertices sizeof = %d\n", sizeof(vertices));
	printf("3 * sizeof(CUSTOMVERTEX)= %d\n", 3 * sizeof(CUSTOMVERTEX));
	d3d9_deivice->CreateVertexBuffer(3 * sizeof(CUSTOMVERTEX),
		0,
		CUSTOMFVF,
		D3DPOOL_MANAGED,
		&v_buffer,
		NULL);

	VOID *pVoid;
	v_buffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices, sizeof(vertices));
	v_buffer->Unlock();*/
}

void Graphics::initD3D()
{
	HRESULT hr;
	d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
/*
	UINT count = d3d9->GetAdapterCount();
	for (int i = 0; i < count; i++)
	{
		//d3d9_deivice->getcrea
		HMONITOR hm = d3d9->GetAdapterMonitor(i);
		D3DDISPLAYMODE d3ddm;
		hr = d3d9->GetAdapterDisplayMode(i, &d3ddm);
		D3DADAPTER_IDENTIFIER9 d3dai;
		hr = d3d9->GetAdapterIdentifier(i, D3DENUM_WHQL_LEVEL, &d3dai);
		int a = 0;
	}
	D3DDISPLAYMODE d3ddm;
	hr = d3d9->GetAdapterDisplayMode(1, &d3ddm);*/
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = isFull ? FALSE : TRUE; //程序全屏，没有窗口
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; //丢弃旧的帧
	d3dpp.hDeviceWindow = hwnd; //设置Direct3D使用的窗口
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8; //将后台缓冲区格式设置为32位
	d3dpp.BackBufferWidth = width; //设置缓冲区的宽度
	d3dpp.BackBufferHeight = height; //设置缓冲区的高度
	d3dpp.FullScreen_RefreshRateInHz = 0;

	d3d9->CreateDevice(thread_num,
		D3DDEVTYPE_HAL,
		hwnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &d3d9_deivice);
/*
	D3DDEVICE_CREATION_PARAMETERS d3dcp;
	if (SUCCEEDED(d3d9_deivice->GetCreationParameters(&d3dcp)))
	{
		printf("adapter ordinal = %d\n", d3dcp.AdapterOrdinal);
	}
	
	joinSwapGroup();*/
}

void Graphics::render()
{
	FILETIME render_timer;
	timer_start(&render_timer);

	//color = color ? 0 : 255;
	d3d9_deivice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 0, 0), 1.0f, 0);
	//d3d9_deivice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(color, color, color), 1.0f, 0);
	d3d9_deivice->BeginScene();
	//render
	d3d9_deivice->SetFVF(CUSTOMFVF);
	d3d9_deivice->SetStreamSource(0, v_buffer, 0, sizeof(CUSTOMVERTEX));
	d3d9_deivice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	d3d9_deivice->EndScene();
	d3d9_deivice->Present(NULL, NULL, NULL, NULL);

	int render_time = timer_elapsed_msec(&render_timer);
	printf("render time = %d\n", render_time);
}

void Graphics::clean3D()
{
	v_buffer->Release();
	d3d9_deivice->Release();
	d3d9->Release();
}

void Graphics::timer_start(FILETIME *start)
{
	GetSystemTimeAsFileTime(start);
}

int64_t Graphics::timer_elapsed_msec(FILETIME *start)
{
	FILETIME now;
	GetSystemTimeAsFileTime(&now);
	int64_t elapsed = ((((int64_t)now.dwHighDateTime) << 32) + (int64_t)now.dwLowDateTime) -
		((((int64_t)start->dwHighDateTime) << 32) + (int64_t)start->dwLowDateTime);
	return elapsed / 10000;
}

int64_t Graphics::timer_elapsed_usec(FILETIME *start)
{
	FILETIME now;
	GetSystemTimeAsFileTime(&now);
	int64_t elapsed = ((((int64_t)now.dwHighDateTime) << 32) + (int64_t)now.dwLowDateTime) -
		((((int64_t)start->dwHighDateTime) << 32) + (int64_t)start->dwLowDateTime);
	return elapsed / 10;
}