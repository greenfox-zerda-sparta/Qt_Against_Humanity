/*
#ifndef CAHSERVER_H
#define CAHSERVER_H

//#include <QtWidgets/QMainWindow>
//#include "ui_cahserver.h"
#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class cahserver : public QObject {
	Q_OBJECT

public:
	explicit cahserver(QObject *parent = 0);
  public slots :
    void newConnection();
  private:
    QTcpServer* server;
};

#endif // CAHSERVER_H
*/