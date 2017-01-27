#pragma once
#include <vector>
class ServerConnection
{
public:
	ServerConnection();
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

