#include "gamelogic.h"


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
  int index = generateRandomNumber(_answers);
  _activeAnswerCards.push_back(_answers[index]);
  _answers.remove(index);
}

GameLogic::~GameLogic()
{
  delete _cout;
  delete _cin;
}
