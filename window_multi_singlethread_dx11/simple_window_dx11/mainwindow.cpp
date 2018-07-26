#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_startButton_clicked);

	m_IsWindowStart = false;
	m_GpuCount = 1;
	m_WindowCount = 4;
}

MainWindow::~MainWindow()
{
	disconnect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_startButton_clicked);
    delete ui;
}

void MainWindow::createWindowWithWin32(WindowData &wd)
{
	WNDCLASSEX wc;
	wd.hinstance = GetModuleHandle(NULL);
	wd.applicationName = L"Engine";
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = wd.hinstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = wd.applicationName;
	wc.cbSize = sizeof(WNDCLASSEX);
	RegisterClassEx(&wc);

	wd.hwnd = CreateWindowEx(WS_EX_APPWINDOW, wd.applicationName, wd.applicationName,
		//WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
		WS_OVERLAPPEDWINDOW,
		wd.x, wd.y, wd.width, wd.height, NULL, NULL, wd.hinstance, NULL);
}

void MainWindow::createWindow()
{
/*
	w = GetSystemMetrics(SM_CXSCREEN);
	h = GetSystemMetrics(SM_CYSCREEN);
	posX = (GetSystemMetrics(SM_CXSCREEN) - w) / 2;
	posY = (GetSystemMetrics(SM_CYSCREEN) - h) / 2;
	if (FULL_SCREEN)
	{
		DEVMODE dmScreenSettings;
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)w;
		dmScreenSettings.dmPelsHeight = (unsigned long)h;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);
		posX = posY = 0;
	}
	SetForegroundWindow(m_hWnd);
	SetFocus(m_hWnd);
	ShowCursor(true);// Hide the mouse cursor.
	*/
	for (int i = 0; i < m_WindowCount; i++)
	{
		WindowData wd;
		memset(&wd, 0, sizeof(wd));
		if (i == 0) { wd.x = 0; wd.y = 0; wd.width = 960; wd.height = 540; }
		if (i == 1) { wd.x = 960; wd.y = 0; wd.width = 960; wd.height = 540; }
		if (i == 2) { wd.x = 0; wd.y = 540; wd.width = 960; wd.height = 540; }
		if (i == 3) { wd.x = 960; wd.y = 540; wd.width = 960; wd.height = 540; }
		wd.gpu = 0;
		wd.number = i;
		createWindowWithWin32(wd);
		ShowWindow(wd.hwnd, SW_SHOW);
		m_WindowVec.push_back(wd);
	}
}

void MainWindow::stopWindowWithWin32(WindowData &wd)
{
	// Show the mouse cursor.
	//ShowCursor(true);

	// Fix the display settings if leaving full screen mode.
	/*
	if (FULL_SCREEN)
	{
	ChangeDisplaySettings(NULL, 0);
	}*/

	// Remove the window.
	DestroyWindow(wd.hwnd);

	// Remove the application instance.
	UnregisterClass(wd.applicationName, wd.hinstance);
}

void MainWindow::stopWindow()
{
	for (int i = 0; i < m_WindowVec.size(); i++)
	{
		WindowData wd = m_WindowVec.at(i);
		stopWindowWithWin32(wd);
	}
	m_WindowVec.clear();
}

void MainWindow::on_startButton_clicked()
{
	m_IsWindowStart = (m_IsWindowStart == false) ? true : false;
	if (m_IsWindowStart)
	{
		ui->pushButton->setText(QString("stop"));
		createWindow();
		startEngine();
	}
	else
	{
		ui->pushButton->setText(QString("start"));
		stopEngine();
		stopWindow();
	}
}

void MainWindow::startEngine()
{
	for (int i = 0; i < m_GpuCount; i++)
	{
		TextureThreadData ttd;
		memset(&ttd, 0, sizeof(TextureThreadData));
		//ttd.wd.x = 0; ttd.wd.y = 0; ttd.wd.width = 20; ttd.wd.height = 20; ttd.wd.gpu = 0; ttd.wd.number = -1;
		//createWindowWithWin32(ttd.wd);
		//ShowWindow(ttd.wd.hwnd, SW_SHOW);
		ttd.texThread = new TextureThread(i, m_WindowVec);
		m_TextureThreadDataVec.push_back(ttd);
	}
}

void MainWindow::stopEngine()
{
	for (int i = 0; i < m_GpuCount; i++)
	{
		TextureThreadData ttd = m_TextureThreadDataVec.at(i);
		ttd.texThread->stop();
		delete ttd.texThread;
		stopWindowWithWin32(ttd.wd);
	}
	m_TextureThreadDataVec.clear();
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch (umessage)
	{
	case WM_DESTROY:
	{
		//PostQuitMessage(0);
		//return 0;
	}

	case WM_CLOSE:
	{
		//PostQuitMessage(0);
		//return 0;
	}

	default:
	{
		//return ApplicationHandle->MessageHandler(hwnd, umessage, wparam, lparam);
		return DefWindowProc(hwnd, umessage, wparam, lparam);
	}
	}
}