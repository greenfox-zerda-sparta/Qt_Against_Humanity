#include <QtCore/QCoreApplication>
#include "chatserver.h"

int main(int argc, char **argv) {
	QCoreApplication app(argc, argv);

	ChatServer server;
	server.StartServer();

	return app.exec();
}
