#pragma once
#include <DirectXMath.h>
using namespace DirectX;

class LightClass
{
public:
	LightClass();
	~LightClass();
	void setDiffuseColor(float, float, float, float);
	void setLightDirection(float, float, float);

	XMFLOAT3 getLightDirection();
	XMFLOAT4 getDiffuseColor();
private:
	XMFLOAT4 m_diffuseColor;
	XMFLOAT3 m_lightDirection;
};