#pragma once
#include <vector>
#include <QObject>
#include <QTcpSocket>

class ServerConnection: public QObject
{
  Q_OBJECT
private:
  QTcpSocket* socket;
public:
	ServerConnection(QObject *parent, QString host, quint16 port);
	void sendSelectedCardIndex(int i);
	void waitUntilGameIsReadyToStart();
	bool pollIsPlayerInJudgeRole();
	std::vector<int> pollSelectedCards();
	std::vector<int> getCards(int x);
	int pollWinnerCard();
	void sendWinnerCard(int i);
	int pollQuestion();
	~ServerConnection();
};

