#include "LightClass.h"

LightClass::LightClass()
{
}

LightClass::~LightClass()
{
}

void LightClass::setDiffuseColor(float r, float g, float b, float a)
{
	m_diffuseColor = XMFLOAT4(r, g, b, a);
}

void LightClass::setLightDirection(float x, float y, float z)
{
	m_lightDirection = XMFLOAT3(x, y, z);
}

void LightClass::setAmbientColor(float r, float g, float b, float a)
{
	m_ambientColor = XMFLOAT4(r, g, b, a);
}

void LightClass::setSpecularColor(float r, float g, float b, float a)
{
	m_specularColor = XMFLOAT4(r, g, b, a);
}

XMFLOAT4 LightClass::getSpecularColor()
{
	return m_specularColor;
}

XMFLOAT4 LightClass::getAmbientColor()
{
	return m_ambientColor;
}

XMFLOAT3 LightClass::getLightDirection()
{
	return m_lightDirection;
}

XMFLOAT4 LightClass::getDiffuseColor()
{
	return m_diffuseColor;
}