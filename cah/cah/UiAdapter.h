#pragma once
#include <vector>
#include <QDebug>
#include "gamelogic.h"
#include "gamegui.h"

class UiAdapter
{
public:
	UiAdapter();
	int pollSelectedCardIndex();
	int pollQuestionCard();
  std::vector<int> pollAnswerCards();
	void showWinnerCard(int i);
	void showSelectedCards(std::vector<int>);
	void showHand(std::vector<int>);
	void showRole(bool isPlayerInJudgeRole);
	void showQuestion(int);
	~UiAdapter();
private:
  GameLogic _logic;
  GameGui _gui;
  QVector<QString> _questionDeck;
  QVector<QString> _answerDeck;
  QString _activeQuestionCard;
  QVector<QString> _activeAnswerCards;
  
};

