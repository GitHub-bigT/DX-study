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
	d3dpp.Windowed = isFull ? FALSE : TRUE; //����ȫ����û�д���
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; //�����ɵ�֡
	d3dpp.hDeviceWindow = hwnd; //����Direct3Dʹ�õĴ���
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8; //����̨��������ʽ����Ϊ32λ
	d3dpp.BackBufferWidth = width; //���û������Ŀ��
	d3dpp.BackBufferHeight = height; //���û������ĸ߶�
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

	color = color ? 0 : 255;
	//d3d9_deivice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 0, 0), 1.0f, 0);
	d3d9_deivice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(color, color, color), 1.0f, 0);
	d3d9_deivice->BeginScene();
	d3d9_deivice->EndScene();
	//Sleep(33);
	d3d9_deivice->Present(NULL, NULL, NULL, NULL);

	int render_time = timer_elapsed_msec(&render_timer);
	printf("render time = %d\n", render_time);
}

void Graphics::clean3D()
{
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