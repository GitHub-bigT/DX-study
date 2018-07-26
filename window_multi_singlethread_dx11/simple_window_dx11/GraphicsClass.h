#pragma once
#include <QVector>
#include "D3DClass.h"
#include "OGLClass.h"

const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsClass
{
public:
	GraphicsClass();
	~GraphicsClass();
	bool init(QVector<WindowData> &wdv);
	void stop();
	bool render();
	bool swap();

private:

private:
	D3DClass *m_direct3D;
	OGLClass *m_Ogl;
	QVector<WindowData> m_WindowDataVec;
};