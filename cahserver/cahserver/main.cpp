#include "cahserver.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	cahserver w;
	w.show();
	return a.exec();
}
