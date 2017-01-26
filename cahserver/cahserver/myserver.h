#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QDebug>
#include "mythread.h"

class MyServer : public QTcpServer
{
	Q_OBJECT

public:
	explicit MyServer(QObject *parent = 0);
	void StartServer();


private:
protected:
	void incommingConnection(int socketDescriptor);
};

#endif // MYSERVER_H
