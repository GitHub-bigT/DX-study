#include <iostream>
#include <windows.h>
#include <QApplication>
#include "mainwindow.h"

void timer_start(FILETIME *start)
{
	GetSystemTimeAsFileTime(start);
}

int64_t timer_elapsed_msec(FILETIME *start)
{
	FILETIME now;
	GetSystemTimeAsFileTime(&now);
	int64_t elapsed = ((((int64_t)now.dwHighDateTime) << 32) + (int64_t)now.dwLowDateTime) -
		((((int64_t)start->dwHighDateTime) << 32) + (int64_t)start->dwLowDateTime);
	return elapsed / 10000;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow mainwindow;
	mainwindow.show();
	return a.exec();
}