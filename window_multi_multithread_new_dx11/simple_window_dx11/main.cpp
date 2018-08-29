#include <QApplication>
#define STB_IMAGE_IMPLEMENTATION
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow mainwindow;
	mainwindow.show();
	return a.exec();
}