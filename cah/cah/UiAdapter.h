#pragma once
#include <vector>
class UiAdapter
{
public:
	UiAdapter();
	int pollSelectedCardIndex();
	int pollWinnerCard();
	void showWinnerCard(int i);
	void showSelectedCards(std::vector<int>);
	void showHand(std::vector<int>);
	void showRole(bool isPlayerInJudgeRole);
	void showQuestion(int question);
	~UiAdapter();
};

