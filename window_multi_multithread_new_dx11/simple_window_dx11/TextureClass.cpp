#include "TextureClass.h"
#include "utils.cpp"

TextureClass::TextureClass()
{
	m_Texture = 0;
	m_TextureView = 0;
}

TextureClass::~TextureClass()
{
}



bool TextureClass::init(ID3D11Device *device, char *filename)
{
/*
	HRESULT hr;
	wchar_t  w_filename[100];
	swprintf(w_filename, 100, L"%hs", filename);
	D3DX11_IMAGE_LOAD_INFO ili;
	ili.Width = D3DX11_DEFAULT;
	ili.Height = D3DX11_DEFAULT;
	ili.Depth = D3DX11_DEFAULT;
	ili.FirstMipLevel = 0;
	ili.MipLevels = 1;
	ili.Usage = (D3D11_USAGE)D3DX11_DEFAULT;
	ili.BindFlags = D3DX11_DEFAULT;
	ili.CpuAccessFlags = D3DX11_DEFAULT;
	ili.MiscFlags = D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX;
	ili.Format = DXGI_FORMAT_FROM_FILE;
	ili.Filter = D3DX11_DEFAULT;
	ili.MipFilter = 0;
	ili.pSrcInfo = NULL;
	hr = D3DX11CreateShaderResourceViewFromFile(device, w_filename, &ili, NULL, &m_TextureView, NULL);//https://msdn.microsoft.com/en-us/library/windows/desktop/ff476315(v=vs.85).aspx
	if (FAILED(hr))
	{
		return false;
	}*/

	bool result;
	D3D11_TEXTURE2D_DESC textureDesc;
	D3D11_SUBRESOURCE_DATA dataDesc;
	HRESULT hr;
	unsigned int rowPitch;
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	result = loadImage(filename);
	if (!result)
	{
	return false;
	}

	textureDesc.Height = m_height;
	textureDesc.Width = m_width;
	textureDesc.MipLevels = 1;
	textureDesc.ArraySize = 1;
	textureDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	textureDesc.SampleDesc.Count = 1;
	textureDesc.SampleDesc.Quality = 0;
	textureDesc.Usage = D3D11_USAGE_DEFAULT;
	textureDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET;
	textureDesc.CPUAccessFlags = 0;
	textureDesc.MiscFlags = 0;

	dataDesc.pSysMem = (void *)m_ImageData;
	dataDesc.SysMemPitch = m_width * (4 * sizeof(unsigned char));

	FILETIME ft;
	timer_start(&ft);
	hr = device->CreateTexture2D(&textureDesc, &dataDesc, &m_Texture);
	int time = timer_elapsed_msec(&ft);
	printf("%d x %d, coast time = %dms\n", m_width, m_height, time);

	srvDesc.Format = textureDesc.Format;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MostDetailedMip = 0;
	srvDesc.Texture2D.MipLevels = -1;

	hr = device->CreateShaderResourceView(m_Texture, &srvDesc, &m_TextureView);
/*
	FILETIME ft1;
	timer_start(&ft1);
	ID3D11ShaderResourceView *m_TextureView;
	wchar_t  w_filename[100];
	swprintf(w_filename, 100, L"%hs", filename);
	hr = D3DX11CreateShaderResourceViewFromFile(device, w_filename, NULL, NULL, &m_TextureView, NULL);
	int time1 = timer_elapsed_msec(&ft1);
	printf("%d x %d, coast time1 = %dms\n", m_width, m_height, time1);*/
	return true;
}

bool TextureClass::loadImage(char*filename)
{
	m_ImageData = stbi_load(filename, &m_width, &m_height, &m_channels, 0);
	if (!m_ImageData)
	{
		return false;
	}
	return true;
}

ID3D11ShaderResourceView* TextureClass::getSrv()
{
	return m_TextureView;
}

void TextureClass::stop()
{
	if (m_Texture)
	{
		m_Texture->Release();
		m_Texture = 0;
	}

	if (m_TextureView)
	{
		m_TextureView->Release();
		m_TextureView = 0;
	}
}