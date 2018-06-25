#include "FpsClass.h"

FpsClass::FpsClass()
{
}

FpsClass::~FpsClass()
{
}

void FpsClass::init()
{
	m_fps = 0;
	m_count = 0;
	m_startTime = timeGetTime();
	printf("m_startTime = %d\n", m_startTime);
}

void FpsClass::frame()
{
	m_count++;

	if (timeGetTime() >= (m_startTime + 1000))
	{
		m_fps = m_count;
		m_count = 0;

		m_startTime = timeGetTime();
	}
}

int FpsClass::getFps()
{
	return m_fps;
}