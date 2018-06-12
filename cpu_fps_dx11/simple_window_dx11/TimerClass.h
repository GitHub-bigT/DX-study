#pragma once
#include <windows.h>

class TimerClass
{
public:
	TimerClass();
	~TimerClass();

	bool init();
	void frame();
	float getFrame();

private:
	INT64 m_frequency;
	float m_ticksPerMs;
	INT64 m_startTime;
	float m_frameTime;
};