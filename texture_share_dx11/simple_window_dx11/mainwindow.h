#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "TextureThread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
	struct TextureThreadData
	{
		TextureThread *texThread;
		WindowData wd;
	};

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
	void startEngine();
	void stopEngine();
	void createWindow();
	void createWindowWithWin32(WindowData &wd);
	void stopWindow();
	void stopWindowWithWin32(WindowData &wd);

private:
    Ui::MainWindow *ui;
	bool m_IsWindowStart;
	int m_GpuCount;
	int m_WindowCount;
	QVector<WindowData> m_WindowVec;
	QVector<TextureThreadData> m_TextureThreadDataVec;

public slots:
	void on_startButton_clicked();
};

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

#endif // MAINWINDOW_H
