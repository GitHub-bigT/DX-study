#include "ModelListClass.h"

ModelListClass::ModelListClass()
{
	m_modelInfoList = 0;
}

ModelListClass::~ModelListClass()
{
}

bool ModelListClass::init(int numModels)
{
	float red = 0.0f, green = 0.0f, blue = 0.0f;

	m_modelCount = numModels;
	m_modelInfoList = new ModelInfoType[m_modelCount];
	if (!m_modelInfoList)
	{
		return false;
	}

	//int 32767, unsigned int 65535(双字节)
	srand((unsigned int)time(NULL));
	for (int i = 0; i < m_modelCount; i++)
	{
		red = (float)rand() / RAND_MAX;
		green = (float)rand() / RAND_MAX;
		blue = (float)rand() / RAND_MAX;

		m_modelInfoList[i].color = XMFLOAT4(red, green, blue, 1.0f);

		//((float)rand() - (float)rand())为了有正有负
		//RAND_MAX为0~int 32767, unsigned int 65535(双字节)

		m_modelInfoList[i].x = (((float)rand() - (float)rand()) / RAND_MAX) * 10.0f;
		m_modelInfoList[i].y = (((float)rand() - (float)rand()) / RAND_MAX) * 10.0f;
		m_modelInfoList[i].z = (((float)rand() - (float)rand()) / RAND_MAX) * 10.0f + 20.0f;
	}

	return true;
}

void ModelListClass::stop()
{
	if (m_modelInfoList)
	{
		delete[] m_modelInfoList;
		m_modelInfoList = 0;
	}
}

int ModelListClass::getModelCount()
{
	return m_modelCount;
}

void ModelListClass::getData(int index, float &x, float &y, float &z, XMFLOAT4 &color)
{
	x = m_modelInfoList[index].x;
	y = m_modelInfoList[index].y;
	z = m_modelInfoList[index].z;
	color = m_modelInfoList[index].color;
}