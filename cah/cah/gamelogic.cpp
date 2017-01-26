#include "gamelogic.h"


GameLogic::GameLogic(QObject * parent) : QObject(parent)
{
  _questions = readFile("Q-cards.txt");
  _answers = readFile("A-cards.txt");
  _activeAnswerCards.resize(6);
  
  selectQuestionCard();
  initializeAnswerCards();
}

void GameLogic::selectQuestionCard()
{
  int index = generateRandomNumber(_questions);
  _activeQuestionCard = _questions[index];
  _questions.remove(index);
}

void GameLogic::initializeAnswerCards()
{
  for (unsigned int i = 0; i < _activeAnswerCards.size(); ++i)
  {
    int index = generateRandomNumber(_answers);
    _activeAnswerCards[i] = _answers[index];
    _answers.remove(index);
  }
}

void GameLogic::run(int index)
{
  pickAnswer(index);
  removeCardFromHand(index);
  refillHand();
  selectQuestionCard();
}

void GameLogic::pickAnswer(int index)
{
  _theAnswer = _activeAnswerCards[index];
}

void GameLogic::removeCardFromHand(int index)
{
  _activeAnswerCards.remove(index);
}

void GameLogic::refillHand()
{
  int index = generateRandomNumber(_answers);
  _activeAnswerCards.push_back(_answers[index]);
  _answers.remove(index);
}

QString GameLogic::getQuestionCard()
{
  return _activeQuestionCard;
}

QVector<QString> GameLogic::getAnswerCards()
{
  return _activeAnswerCards;
}