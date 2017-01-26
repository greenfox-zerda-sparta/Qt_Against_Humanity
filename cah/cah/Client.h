#pragma once
#include <QTcpSocket>
#include <QObject>
#include <QDebug>

class Client : public QObject {
  Q_OBJECT
private:
  QTcpSocket* _pSocket;
public:
  Client(QObject *parent = 0);
  ~Client();
};

