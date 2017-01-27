#include "UiAdapter.h"

UiAdapter::UiAdapter() 
{
  _questionDeck = _logic.getQuestionDeck();
  _answerDeck = _logic.getAnswerDeck();  
  _activeQuestionCard = _questionDeck[pollQuestionCard()];
  
  _logic.setQuestionCard(_activeQuestionCard);
  std::vector<int> v = pollAnswerCards();
  _activeAnswerCards.resize(6);
  for (unsigned int i = 0; i < 6; ++i)
  {
    _activeAnswerCards[i] = _answerDeck[v[i]];
  }
  _logic.setAnswerCards(_activeAnswerCards);
  _gui.render(_logic);
  _gui.show();
}

int UiAdapter::pollSelectedCardIndex(){
	return 0;
}

int UiAdapter::pollQuestionCard(){
	return 12;
}

std::vector<int> UiAdapter::pollAnswerCards() {
  std::vector<int> vector(6);
  for (unsigned int i = 0; i < 6; ++i)
  {
    vector[i] = i;
  }
  return vector;
}

void UiAdapter::showWinnerCard(int i){
}

void UiAdapter::showSelectedCards(std::vector<int>){
}

void UiAdapter::showHand(std::vector<int>){
}

void UiAdapter::showRole(bool isPlayerInJudgeRole){
}

void UiAdapter::showQuestion(int index)
{
  _activeQuestionCard = _questionDeck[index];
}


UiAdapter::~UiAdapter(){
}
