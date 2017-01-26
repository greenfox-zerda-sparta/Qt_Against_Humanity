#pragma once
#include <ServerConnection.h>
#include <UiAdapter.h>
#include <vector>

class Game {
private:
	ServerConnection* serverConnection;
	UiAdapter* uiAdapter;
	bool isOver;
	bool isPlayerInJudgeRole;
	std::vector<int> selectedCards;
	std::vector<int> cardsInHand;
	int winnerCard;
	int question;
	const int HAND_SIZE;
public:
	Game(ServerConnection*, UiAdapter*);
	void start();
	void loop();
	void doRound();
	void fillHandIfNeeded();
	~Game();
};

