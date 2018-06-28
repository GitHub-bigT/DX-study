#pragma once
#define _XM_NO_INTRINSICS_//must before #include <DirectXMath.h>
#include <DirectXMath.h>
#include <iostream>
using namespace DirectX;

class FrustumClass
{
public:
	FrustumClass();
	~FrustumClass();

	void constructFrustum(float, XMMATRIX, XMMATRIX);

	bool checkPoint(float, float, float);
	bool checkCube(float, float, float, float);
	bool checkSphere(float, float, float, float);
	bool checkRectangle(float, float, float, float, float);

private:
	XMVECTOR m_planes[6];
};