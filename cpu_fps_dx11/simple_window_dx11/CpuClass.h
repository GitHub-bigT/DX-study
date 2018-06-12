#pragma once
#include <Pdh.h>

//ÿ�뷢������CPUʹ�ðٷֱ�
class CpuClass
{
public:
	CpuClass();
	~CpuClass();
	void init();
	void stop();
	void frame();
	int getCpuPercentage();

private:
	bool m_canReadCpu;
	HQUERY m_queryHandle;
	HCOUNTER m_counterHandle;
	unsigned long m_lastSampleTime;
	long m_cpuUsage;
};