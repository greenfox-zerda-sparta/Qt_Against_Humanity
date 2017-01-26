#include "myserver.h"

MyServer::MyServer(QObject *parent)
	: QTcpServer(parent)
{

}

void MyServer::StartServer()
{
	if (!this->listen(QHostAddress::Any,1234))
	{
		qDebug() << "could not start server";
	}
	else
	{
		qDebug() << "listening...";
	}
}
void MyServer::incomingConnection(qintptr socketDescriptor)
{
	qDebug() << socketDescriptor << " Connecting..";
	MyThread *thread = new MyThread(socketDescriptor, this);
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater())); // flags the thread for deletion
	thread->start();

}
