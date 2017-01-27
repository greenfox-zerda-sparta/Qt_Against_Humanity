#include "Game.h"

Game::Game(ServerConnection* serverConnection, UiAdapter* uiAdapter): HAND_SIZE(6) {
	this->serverConnection = serverConnection;
	this->uiAdapter = uiAdapter;
	this->isOver = false;
	this->isPlayerInJudgeRole = false;
}

void Game::start() {
	serverConnection->waitUntilGameIsReadyToStart();
	loop();
}

void Game::loop(){
	while (!isOver) {
		doRound();
	}
}

void Game::doRound() {
	question = serverConnection->pollQuestion();
	uiAdapter->showQuestion(this->question);
	isPlayerInJudgeRole = serverConnection->pollIsPlayerInJudgeRole();
	uiAdapter->showRole(isPlayerInJudgeRole);
	fillHandIfNeeded();
	uiAdapter->showHand(cardsInHand);
	if (isPlayerInJudgeRole) {
		this->selectedCards = serverConnection->pollSelectedCards();
		uiAdapter->showSelectedCards(this->selectedCards);
		//this->winnerCard = uiAdapter->pollWinnerCard();
		serverConnection->sendWinnerCard(this->winnerCard);
	} else {
		int selectedCardIndex = uiAdapter->pollSelectedCardIndex();
		serverConnection->sendSelectedCardIndex(selectedCardIndex);
		this->selectedCards = serverConnection->pollSelectedCards();
		uiAdapter->showSelectedCards(this->selectedCards);
		winnerCard = serverConnection->pollWinnerCard();
	}
	uiAdapter->showWinnerCard(this->winnerCard);
}

void Game::fillHandIfNeeded(){
	int missingCount = HAND_SIZE - cardsInHand.size();
	if (missingCount > 0) {
		std::vector<int> newCards = serverConnection->getCards(missingCount);
		cardsInHand.insert(cardsInHand.end(), newCards.begin(), newCards.end());
	}
}


Game::~Game() {
}
