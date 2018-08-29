#pragma once
#include <QThread>
#include <QVector>
#include <QSemaphore>
#include <QMutex>
#include "RenderThread.h"
#include "TextureClass.h"

class TextureThread : public QThread
{
public:

	TextureThread(int gpu, WindowData &wd, QVector<WindowData> &wdVec);
	~TextureThread();

	void stop();
	void run();

	void setTextureSemaphore(int n = 1);
	void getTextureSemaphore(int n = 1);
	void setTextureDoneSemaphore(int n = 1);
	void getTextureDoneSemaphore(int n = 1);
	void setSwapSemaphore(int n = 1);
	void getSwapSemaphore(int n = 1);
	void setSwapDoneSemaphore(int n = 1);
	void getSwapDoneSemaphore(int n = 1);

	D3D11Class* getD3D11Class();
	ID3D11ShaderResourceView *getSrv();
	void addCommandList(ID3D11CommandList *l);

private:
	void init();
	void stopRenderThread();
	void releaseResource();

public:

private:
	int m_Gpu;
	bool m_Run;
	WindowData m_WindowData;
	QVector<WindowData> m_WindowVec;
	QVector<RenderThread*> m_RenderThreadVector;
	QVector<ID3D11CommandList*> m_CommandLists;
	QSemaphore m_TextureSemaphore, m_TextureDoneSemaphore;
	QSemaphore m_SwapSemaphore, m_SwapDoneSemaphore;
	D3D11Class *m_D3D11Class;
	TextureClass *m_TextureClass;
	QMutex mtx;
};