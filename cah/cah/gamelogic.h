#pragma once
#include <QObject>
#include "util.h"

class GameLogic : public QObject {
	Q_OBJECT

public:
	GameLogic(QObject * parent = Q_NULLPTR);
  void selectQuestionCard();
  void initializeAnswerCards();
  void run(int);
  void pickAnswer(int);
  void removeCardFromHand(int);
  void refillHand();
  void initialize();
  QVector<QString> getQuestionDeck();
  QVector<QString> getAnswerDeck();
  QString getQuestionCard();
  QVector<QString> getAnswerCards();
  void setQuestionCard(QString);
  void setAnswerCards(QVector<QString>);

private:
  QVector<QString> _questionDeck;
  QVector<QString> _answerDeck;
  QString _activeQuestionCard;
  QVector<QString> _activeAnswerCards;
  QString _theAnswer;
};
