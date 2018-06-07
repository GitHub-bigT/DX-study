#include "FontClass.h"

FontClass::FontClass()
{
	m_font = 0;
	m_texture = 0;
}

FontClass::~FontClass()
{
}

bool FontClass::init(ID3D11Device *device, ID3D11DeviceContext *deviceContext, char *fontFilename, char *textureFilename)
{
	bool result;
	result = loadFontData(fontFilename);
	if (!result)
	{
		return false;
	}

	result = loadTexture(device, deviceContext, textureFilename);
	if (!result)
	{
		return false;
	}
	return true;
}

void FontClass::stop()
{
	releaseTexture();

	releaseFontData();
}

ID3D11ShaderResourceView* FontClass::getTexture()
{
	return m_texture->getTexture();
}

void FontClass::buildVertexArray(void *vertices, char *sentence, float drawX, float drawY)
{
	VertexType *vertexPtr;
	int numLetters, index, letter;

	vertexPtr = (VertexType*)vertices;
	numLetters = (int)strlen(sentence);

	index = 0;
	for (int i = 0; i < numLetters; i++)
	{
		letter = ((int)sentence[i]) - 32;
		if (letter == 0)
		{
			drawX = drawX + 3.0f;
		}
		else
		{
			vertexPtr[index].position = XMFLOAT3(drawX, drawY, 0.0f);  // Top left.
			vertexPtr[index].tex = XMFLOAT2(m_font[letter].left, 0.0f);
			index++;

			vertexPtr[index].position = XMFLOAT3((drawX + m_font[letter].size), (drawY - 16), 0.0f);  // Bottom right.
			vertexPtr[index].tex = XMFLOAT2(m_font[letter].right, 1.0f);
			index++;

			vertexPtr[index].position = XMFLOAT3(drawX, (drawY - 16), 0.0f);  // Bottom left.
			vertexPtr[index].tex = XMFLOAT2(m_font[letter].left, 1.0f);
			index++;

			// Second triangle in quad.
			vertexPtr[index].position = XMFLOAT3(drawX, drawY, 0.0f);  // Top left.
			vertexPtr[index].tex = XMFLOAT2(m_font[letter].left, 0.0f);
			index++;

			vertexPtr[index].position = XMFLOAT3(drawX + m_font[letter].size, drawY, 0.0f);  // Top right.
			vertexPtr[index].tex = XMFLOAT2(m_font[letter].right, 0.0f);
			index++;

			vertexPtr[index].position = XMFLOAT3((drawX + m_font[letter].size), (drawY - 16), 0.0f);  // Bottom right.
			vertexPtr[index].tex = XMFLOAT2(m_font[letter].right, 1.0f);
			index++;

			// Update the x location for drawing by the size of the letter and one pixel.
			drawX = drawX + m_font[letter].size + 1.0f;
		}
	}
}


bool FontClass::loadFontData(char *filename)
{
	ifstream fin;
	char temp;

	m_font = new FontType[95];//0~94为fontdata.txt文件中的索引数
	if (!m_font)
	{
		return false;
	}
	fin.open(filename);
	if (fin.fail())
	{
		return false;
	}
	for (int i = 0; i < 95; i++)
	{
		fin.get(temp);
		while (temp != ' ')
		{
			fin.get(temp);
		}
		fin.get(temp);
		while (temp != ' ')
		{
			fin.get(temp);
		}
		fin >> m_font[i].left;
		fin >> m_font[i].right;
		fin >> m_font[i].size;
	}

	fin.close();

	return true;
}

void FontClass::releaseFontData()
{
	if (m_font)
	{
		delete[] m_font;
		m_font = 0;
	}
}

bool FontClass::loadTexture(ID3D11Device *device, ID3D11DeviceContext *deviceContext, char *filename)
{
	bool result;
	m_texture = new TextureClass;
	if (!m_texture)
	{
		return false;
	}

	result = m_texture->init(device, deviceContext, filename);
	if (!result)
	{
		return false;
	}
	return true;
}

void FontClass::releaseTexture()
{
	if (m_texture)
	{
		m_texture->stop();
		delete m_texture;
		m_texture = 0;
	}
}