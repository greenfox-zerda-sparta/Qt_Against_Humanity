#include "ServerConnection.h"



ServerConnection::ServerConnection(QObject *parent, QString host, quint16 port)
{
  socket = new QTcpSocket(this);
  connect(socket, SIGNAL(readyRead()), SLOT(readTcpData()));
  socket->connectToHost(host, port);
  if (socket->waitForConnected()) {
    socket->write("hallo");
  }
}

void ServerConnection::sendSelectedCardIndex(int i)
{
}

void ServerConnection::waitUntilGameIsReadyToStart(){
}

bool ServerConnection::pollIsPlayerInJudgeRole(){
	return false;
}

std::vector<int> ServerConnection::pollSelectedCards(){
	return std::vector<int>();
}

std::vector<int> ServerConnection::getCards(int x) {
	return std::vector<int>();
}

int ServerConnection::pollWinnerCard() {
	return 0;
}

void ServerConnection::sendWinnerCard(int i){
}

int ServerConnection::pollQuestion(){
	return 0;
}


ServerConnection::~ServerConnection(){
}
