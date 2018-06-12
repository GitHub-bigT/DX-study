#pragma once
#include <Pdh.h>

//每秒发生的总CPU使用百分比
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