#pragma once
#include <windows.h>
#include <mmsystem.h>
#include <iostream>

class FpsClass
{
public:
	FpsClass();
	~FpsClass();

	void init();
	void frame();
	int getFps();

private:
	int m_fps, m_count;
	unsigned long m_startTime;
};

