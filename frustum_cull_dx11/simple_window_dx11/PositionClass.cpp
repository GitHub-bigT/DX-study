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
	//Ŀǰ���ǵ��ƶ��ٶ��Ǹ�������������ûʲô���⣬
	//����ʵ������¸��ݴ�������������ͬ����Щ�˿��ܻ��������ÿ����Ƹ���֡��
	//Ҳ�����Ը��ߵ�Ƶ�ʵ���processInput������������ǣ��������õĲ�ͬ��
	//��Щ�˿����ƶ��ܿ죬����Щ�˻��ƶ����������㷢����ĳ����ʱ�������ȷ����������Ӳ�����ƶ��ٶȶ�һ����

	//ͼ�γ������Ϸͨ�������һ��ʱ���(Deltatime)����������������Ⱦ��һ֡���õ�ʱ�䡣
	//���ǰ������ٶȶ�ȥ����deltaTimeֵ��������ǣ�������ǵ�deltaTime�ܴ󣬾���ζ����һ֡����Ⱦ�����˸���ʱ�䣬
	//������һ֡���ٶ���Ҫ��ø�����ƽ����Ⱦ����ȥ��ʱ�䡣
	//ʹ�����ַ���ʱ��������ĵ��Կ컹��������������ٶȶ�����Ӧƽ�⣬����ÿ���û�������Ͷ�һ���ˡ�
	if (keydown)
	{
		m_rightTurnSpeed = 0;//��ֹ�������ʱ�� �Ҽ���speed��û˥����0
		m_leftTurnSpeed += m_frameTime * 0.0001f;
		if (m_leftTurnSpeed > (m_frameTime * 0.15f))
		{
			m_leftTurnSpeed = m_frameTime * 0.15f;
		}
	}
	else
	{
		m_leftTurnSpeed -= m_frameTime * 0.00005f;//����
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