#pragma once
#include <iostream>

class PositionClass
{
public:
	PositionClass();
	~PositionClass();

	void setFrameTime(float);
	void getRotation(float&);

	void turnLeft(bool);
	void turnRight(bool);

private:
	float m_frameTime;
	float m_rotationY;
	float m_leftTurnSpeed, m_rightTurnSpeed;
};