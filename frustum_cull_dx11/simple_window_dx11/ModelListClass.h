#pragma once
#include <DirectXMath.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace DirectX;

class ModelListClass
{
private:
	struct ModelInfoType
	{
		XMFLOAT4 color;
		float x, y, z;
	};
public:
	ModelListClass();
	~ModelListClass();

	bool init(int);
	void stop();

	int getModelCount();
	void getData(int, float&, float&, float&, XMFLOAT4&);

private:
	int m_modelCount;
	ModelInfoType *m_modelInfoList;
};