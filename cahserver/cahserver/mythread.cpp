#include "mythread.h"

MyThread::MyThread(int ID, QObject *parent)
	: QThread(parent)
{
	this->socketDescriptor = ID;
}
void MyThread::run() 
{
	//thread starts here
	qDebug() << socketDescriptor << " starting thread";
	socket = new QTcpSocket();
	if (!socket->setSocketDescriptor(this->socketDescriptor))
	{
		emit error(socket->error());
		return;
	}
	connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()),Qt::DirectConnection);
	connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);

	qDebug() << socketDescriptor << "client conected";
	exec();   //ensures that this process doesnt close
}
void MyThread::readyRead() 
{
	QByteArray Data = socket->readAll();
	qDebug() << socketDescriptor << " Data in: " << Data;

	socket->write(Data); //echo the data back to the client
}
void MyThread::disconnected()
{
	qDebug() << socketDescriptor << " Disconnected: " ;

	socket->deleteLater();
	exit(0);
}
