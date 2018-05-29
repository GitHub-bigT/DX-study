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
	this->ogl_dc = NULL;
	this->ogl_rc = NULL;
	this->ogl_handleD3D = NULL;
	this->ogl_handleD3DTex = NULL;
	this->im_width = 1920;
	this->im_height = 1080;
}

Graphics::~Graphics()
{
}

void Graphics::run()
{
	initD3D();
	initDxTex();
	initGL();
	initGLTex();
	initInterOp();

	while (isRun)
	{
		FILETIME render_timer;
		timer_start(&render_timer);

		wglDXLockObjectsNV(ogl_handleD3D, 1, &ogl_handleD3DTex);
		renderGL();
		wglDXUnlockObjectsNV(ogl_handleD3D, 1, &ogl_handleD3DTex);

		renderDX();
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

void Graphics::initDxTex()
{
	HRESULT hr;
	CUSTOMVERTEX vertices[] = { {0.0f, 0.0f, 1.0f, 1.0f, 0, 0},
								{800.0f, 600.0f, 1.0f, 1.0f, 1, 1},
								{0.0f, 600.0f, 1.0f, 1.0f, 0, 1},
								{0.0f, 0.0f, 1.0f, 1.0f, 0, 0},
								{800.0f, 0.0f, 1.0f, 1.0f, 1, 0},
								{800.0f, 600.0f, 1.0f, 1.0f, 1, 1},
								};//逆时针剔除
	hr = d3d9_deivice->CreateVertexBuffer(sizeof(vertices), 0, CUSTOMFVF, D3DPOOL_DEFAULT, &v_buffer, NULL);
	VOID *pVoid;
	hr = v_buffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices, sizeof(vertices));//glbufferdata
	hr = v_buffer->Unlock();
	hr = d3d9_deivice->CreateTexture(im_width, im_height, 0, D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &dx_tex1, NULL);
	
	d3d9_deivice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	d3d9_deivice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	//d3d9_deivice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);//error
}

void Graphics::dump_texture(GLuint texture_id)
{
	int d_width, d_height;
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &d_width);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &d_height);

	uint8_t *pix = (uint8_t*)malloc(d_width * d_height * 4);
	char buff[128];
	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, pix);
	checkError();

	sprintf(buff, "D:/Code/practise/dx-study/dx9_gl_interop/dump_%dx%d.rgba", d_width, d_height);
	FILE *fp = fopen(buff, "wb");
	fwrite(pix, 1, d_width * d_height * 4, fp);
	fclose(fp);
	free(pix);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Graphics::initD3D()
{
	HRESULT hr;
	Direct3DCreate9Ex(D3D_SDK_VERSION, &d3d9);
	UINT count = d3d9->GetAdapterCount();
	for (int i = 0; i < count; i++)
	{
		//d3d9_deivice->getcrea
		HMONITOR hm = d3d9->GetAdapterMonitor(i);
		MONITORINFO mInfo;
		GetMonitorInfo(hm, &mInfo);

		D3DDISPLAYMODE d3dda;
		hr = d3d9->GetAdapterDisplayMode(i, &d3dda);
		d3d9->GetAdapterModeCount(i, d3dda.Format);

		D3DDISPLAYMODE d3ddm;
		hr = d3d9->GetAdapterDisplayMode(i, &d3ddm);
		D3DADAPTER_IDENTIFIER9 d3dai;
		hr = d3d9->GetAdapterIdentifier(i, D3DENUM_WHQL_LEVEL, &d3dai);
	}
	D3DDISPLAYMODE d3ddm;
	hr = d3d9->GetAdapterDisplayMode(1, &d3ddm);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = isFull ? FALSE : TRUE; //程序全屏，没有窗口
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; //丢弃旧的帧
	d3dpp.hDeviceWindow = hwnd; //设置Direct3D使用的窗口
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8; //将后台缓冲区格式设置为32位
	d3dpp.BackBufferWidth = width; //设置缓冲区的宽度
	d3dpp.BackBufferHeight = height; //设置缓冲区的高度
	d3dpp.FullScreen_RefreshRateInHz = 0;

	hr = d3d9->CreateDeviceEx(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hwnd,
		//D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		D3DCREATE_HARDWARE_VERTEXPROCESSING |
		D3DCREATE_PUREDEVICE |
		D3DCREATE_MULTITHREADED,
		&d3dpp, 
		NULL,
		&d3d9_deivice);
	if (hr == S_OK)
		printf("d3d9 device ex SUCCESS\n");
	else
		printf("d3d9 device ex ERROR\n");
/*
	D3DDEVICE_CREATION_PARAMETERS d3dcp;
	if (SUCCEEDED(d3d9_deivice->GetCreationParameters(&d3dcp)))
	{
		printf("adapter ordinal = %d\n", d3dcp.AdapterOrdinal);
	}*/
	//joinSwapGroup();
}

int Graphics::setupPixelFormat(HDC hDC)
{
	int pixelIdx;
	// get the appropriate pixel format 
	pixelIdx = ChoosePixelFormat(hDC, &pfd);
	if (pixelIdx == 0) {
		printf("ChoosePixelFormat() failed:  Cannot find format specified.");
		return 0;
	}

	/* set the pixel format */
	if (SetPixelFormat(hDC, pixelIdx, &pfd) == FALSE) {
		printf("SetPixelFormat() failed:  Cannot set format specified.");
		return 0;
	}

	return pixelIdx;
}

void Graphics::checkError()
{
	int err = glGetError();
	if (err != GL_NO_ERROR)
	{
		printf("GL error 0x%x at %s:%d\n", err, __FILE__, __LINE__);
	}
}

void Graphics::initInterOp()
{
	ogl_handleD3D = wglDXOpenDeviceNV(d3d9_deivice);
	if (ogl_handleD3D)
		printf("wglDXOpenDeviceNV SUCCESS\n");
	else
		printf("wglDXOpenDeviceNV ERROR\n");

	ogl_handleD3DTex = wglDXRegisterObjectNV(ogl_handleD3D, dx_tex1, ogl_tex1, GL_TEXTURE_2D, WGL_ACCESS_READ_WRITE_NV);
	if (ogl_handleD3DTex)
		printf("wglDXRegisterObjectNV SUCCESS\n");
	else
		printf("wglDXRegisterObjectNV ERROR\n");
}

void Graphics::initGLTex()
{
	//data = stbi_load("container.png", &im_width, &im_height, &im_Components, 0);
	glGenTextures(1, &ogl_tex1);
	glBindTexture(GL_TEXTURE_2D, ogl_tex1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, im_width, im_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	glGenFramebuffers(1, &ogl_fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, ogl_fbo);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, ogl_tex1, 0);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		printf("ERROR::FRAMEBUFFER:: Framebuffer is not complete!\n");
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Graphics::initGL()
{
	ogl_dc = GetDC(hwnd);
	setupPixelFormat(ogl_dc);
	ogl_rc = wglCreateContext(ogl_dc);
	bool isSucc = wglMakeCurrent(ogl_dc, ogl_rc);
	if (ogl_rc != NULL && isSucc)
		printf("gl make current success\n");
	else
		printf("gl make error success\n");
	glewExperimental = true;
	GLenum err = glewInit();
	if (GLEW_OK != err)
		printf("GLEW Error: %s\n", glewGetErrorString(err));
}

void Graphics::renderDX()
{
	d3d9_deivice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 0, 0), 1.0f, 0);
	d3d9_deivice->BeginScene();
	d3d9_deivice->SetTexture(0, dx_tex1);
	//D3DXSaveTextureToFile(L"dx.png", D3DXIFF_PNG, dx_tex1, NULL);
	d3d9_deivice->SetFVF(CUSTOMFVF);
	d3d9_deivice->SetStreamSource(0, v_buffer, 0, sizeof(CUSTOMVERTEX));
	d3d9_deivice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	d3d9_deivice->EndScene();
	d3d9_deivice->Present(NULL, NULL, NULL, NULL);
}

void Graphics::renderGL()
{
	glBindFramebuffer(GL_FRAMEBUFFER, ogl_fbo);
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glFinish();
}

void Graphics::clean3D()
{
	v_buffer->Release();
	d3d9_deivice->Release();
	d3d9->Release();
}

GLuint Graphics::loadTexture(char const * path)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
	if (data)
	{
		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT); // for this tutorial: use GL_CLAMP_TO_EDGE to prevent semi-transparent borders. Due to interpolation it takes texels from next repeat 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}
	else
	{
		printf("stb load texture failed\n");
		stbi_image_free(data);
	}

	return textureID;
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