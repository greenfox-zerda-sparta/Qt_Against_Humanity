#include "Client.h"

Client::Client(QObject *parent) : QObject(parent) {
  QByteArray data;
  _pSocket = new QTcpSocket(this);
  connect(_pSocket, SIGNAL(readyRead()), SLOT(readTcpData()));

  _pSocket->connectToHost("127.0.0.1", 1234);
  if (_pSocket->waitForConnected()) {
    _pSocket->write("hallo");
  }
}

Client::~Client() {}
