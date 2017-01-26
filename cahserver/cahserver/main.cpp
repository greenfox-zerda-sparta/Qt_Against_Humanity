//#include "cahserver.h"
//#include <QtWidgets/QApplication>
#include "myserver.h"

#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	MyServer server;
	server.StartServer();
	return a.exec();
}
