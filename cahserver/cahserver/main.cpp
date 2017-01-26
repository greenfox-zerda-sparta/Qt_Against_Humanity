#include "cahserver.h"
//#include <QtWidgets/QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
  cahserver myServer;
	return a.exec();
}
