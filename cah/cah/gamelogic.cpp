#include "gamelogic.h"
#include <QGlobal.h>
#include <QTime>

GameLogic::GameLogic(QObject * parent) : QObject(parent)
{
  _cout = new QTextStream(stdout);
  _cin = new QTextStream(stdin);
  _questions = readFile("Q-cards.txt");
  _answers = readFile("A-cards.txt");
  _activeAnswerCards.resize(6);
  selectQuestionCard();
  initializeAnswerCards();
  
  writeToConsole("The question is: " + _activeQuestionCard + "\n", _cout);
  writeToConsole("The answers you can pick from:", _cout);
  for (unsigned int i = 0; i < _activeAnswerCards.size(); ++i)
  {
    writeToConsole(_activeAnswerCards[i], _cout);
  }
  writeToConsole("\n", _cout);
  run();
}

void GameLogic::selectQuestionCard()
{
  QTime time = QTime::currentTime();
  qsrand((uint)time.msec());
  _activeQuestionCard = _questions[qrand() % (_questions.size() - 1)];
}

void GameLogic::initializeAnswerCards()
{
  QTime time = QTime::currentTime();
  qsrand((uint)time.msec());
  for (unsigned int i = 0; i < _activeAnswerCards.size(); ++i)
  {
    _activeAnswerCards[i] = _answers[qrand() % (_answers.size() - 1)];
  }
}

void GameLogic::run()
{
  writeToConsole("Select your pick: ", _cout);
  QString index;
  *_cin >> index;
  bool ok;
  pickAnswer(index.toInt(&ok, 10));
  writeToConsole("Your picked answer is: " + _theAnswer + "\n", _cout);
  removeCardFromHand(index.toInt(&ok, 10));
  refillHand();
  writeToConsole("Refreshed cards in your hand:\n", _cout);
  for (unsigned int i = 0; i < _activeAnswerCards.size(); ++i)
  {
    writeToConsole(_activeAnswerCards[i], _cout);
  }
  run();
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
  QTime time = QTime::currentTime();
  qsrand((uint)time.msec());
  _activeAnswerCards.push_back(_answers[qrand() % (_answers.size() - 1)]);
}

GameLogic::~GameLogic()
{
	
}
