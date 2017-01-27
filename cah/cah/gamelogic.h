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
  QString getQuestionCard();
  QVector<QString> getAnswerCards();

private:
  QVector<QString> _questions;
  QVector<QString> _answers;
  QString _activeQuestionCard;
  QVector<QString> _activeAnswerCards;
  QString _theAnswer;
};
