#include "LogViewer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LogViewer w;
	w.show();
	return a.exec();
}
