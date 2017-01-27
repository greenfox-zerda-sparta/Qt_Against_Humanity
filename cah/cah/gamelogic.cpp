#include "gamelogic.h"


GameLogic::GameLogic(QObject * parent) : QObject(parent)
{
  initialize();
}

void GameLogic::selectQuestionCard()
{
  int index = generateRandomNumber(_questionDeck);
  _activeQuestionCard = _questionDeck[index];
  _questionDeck.remove(index);
}

void GameLogic::initializeAnswerCards()
{
  for (unsigned int i = 0; i < _activeAnswerCards.size(); ++i)
  {
    int index = generateRandomNumber(_answerDeck);
    _activeAnswerCards[i] = _answerDeck[index];
    _answerDeck.remove(index);
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
  int index = generateRandomNumber(_answerDeck);
  _activeAnswerCards.push_back(_answerDeck[index]);
  _answerDeck.remove(index);
}

QString GameLogic::getQuestionCard()
{
  return _activeQuestionCard;
}

QVector<QString> GameLogic::getAnswerCards()
{
  return _activeAnswerCards;
}

QVector<QString> GameLogic::getQuestionDeck()
{
  return _questionDeck;
}

QVector<QString> GameLogic::getAnswerDeck()
{
  return _answerDeck;
}

void GameLogic::initialize()
{
  _questionDeck = readFile("Q-cards.txt");
  _answerDeck = readFile("A-cards.txt");
  _activeAnswerCards.resize(6);
  //selectQuestionCard();
  //initializeAnswerCards();
}

void GameLogic::setQuestionCard(QString question)
{
  _activeQuestionCard = question;
}

void GameLogic::setAnswerCards(QVector<QString> answers)
{
  _activeAnswerCards = answers;
}