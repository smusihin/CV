
#include <cv.h>
#include <QWidget>
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CV w;
	w.show();
	return a.exec();
}
