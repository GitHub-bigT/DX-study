#include "PositionClass.h"

PositionClass::PositionClass()
{
	m_frameTime = 0;
	m_rotationY = 0;
	m_leftTurnSpeed = 0;
	m_rightTurnSpeed = 0;
}

PositionClass::~PositionClass()
{
}

void PositionClass::setFrameTime(float frameTime)
{
	m_frameTime = frameTime;
}

void PositionClass::getRotation(float &rotation)
{
	rotation = m_rotationY;
}

void PositionClass::turnLeft(bool keydown)
{
	//目前我们的移动速度是个常量。理论上没什么问题，
	//但是实际情况下根据处理器的能力不同，有些人可能会比其他人每秒绘制更多帧，
	//也就是以更高的频率调用processInput函数。结果就是，根据配置的不同，
	//有些人可能移动很快，而有些人会移动很慢。当你发布你的程序的时候，你必须确保它在所有硬件上移动速度都一样。

	//图形程序和游戏通常会跟踪一个时间差(Deltatime)变量，它储存了渲染上一帧所用的时间。
	//我们把所有速度都去乘以deltaTime值。结果就是，如果我们的deltaTime很大，就意味着上一帧的渲染花费了更多时间，
	//所以这一帧的速度需要变得更高来平衡渲染所花去的时间。
	//使用这种方法时，无论你的电脑快还是慢，摄像机的速度都会相应平衡，这样每个用户的体验就都一样了。
	if (keydown)
	{
		m_rightTurnSpeed = 0;//防止左键按下时， 右键的speed还没衰减到0
		m_leftTurnSpeed += m_frameTime * 0.0001f;
		if (m_leftTurnSpeed > (m_frameTime * 0.15f))
		{
			m_leftTurnSpeed = m_frameTime * 0.15f;
		}
	}
	else
	{
		m_leftTurnSpeed -= m_frameTime * 0.00005f;//减速
		if (m_leftTurnSpeed < 0.0f)
		{
			m_leftTurnSpeed = 0.0f;
		}
	}

	m_rotationY -= m_leftTurnSpeed;
	if (m_rotationY < 0.0f)
	{
		m_rotationY += 360.0f;
	}
}

void PositionClass::turnRight(bool keydown)
{
	if (keydown)
	{
		m_leftTurnSpeed = 0;
		m_rightTurnSpeed += m_frameTime * 0.0001f;
		if (m_rightTurnSpeed > (m_frameTime * 0.15f))
		{
			m_rightTurnSpeed = m_frameTime * 0.15f;
		}
	}
	else
	{
		m_rightTurnSpeed -= m_frameTime * 0.00005f;
		if (m_rightTurnSpeed < 0.0f)
		{
			m_rightTurnSpeed = 0.0f;
		}
	}

	m_rotationY += m_rightTurnSpeed;

	if (m_rotationY > 360.0f)
	{
		m_rotationY -= 360.0f;
	}
}