#include "FrustumClass.h"

FrustumClass::FrustumClass()
{
}

FrustumClass::~FrustumClass()
{
}

void FrustumClass::constructFrustum(float screenDepth, XMMATRIX projectionMatrix, XMMATRIX viewMatrix)
{
	float zMinimum, r;
	XMMATRIX matrix;

	//zMinimum = -projectionMatrix.r[3].m128_f32[2] / projectionMatrix.r[2].m128_f32[2];
	zMinimum = -projectionMatrix._43 / projectionMatrix._33;
	//printf("zMinimum = %f\n", zMinimum);
	//D3DXMatrixMultiply()
	
}

bool FrustumClass::checkPoint(float, float, float)
{
	return true;
}

bool FrustumClass::checkCube(float, float, float, float)
{
	return true;
}

bool FrustumClass::checkSphere(float, float, float, float)
{
	return true;
}

bool FrustumClass::checkRectangle(float, float, float, float, float)
{
	return true;
}