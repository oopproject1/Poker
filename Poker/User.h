#pragma once
#include "Player.h"
#include "Card.h"
class User : public Player {
private:
	Card card[5];
	int money;
	bool lose;
	int cardLength;
	int bettingMoney;
	string bettingStart;
	bool death;
public:

	User();
	void playerDrow();
	int getMoney();
	bool getLose();
	int getCardLength();
	void setMoney(int newMoney);
	void setLose(bool newLose);
	void setCardLength(int newCardLength);
	Card* getCard();
	void doBet(int n, int mon, int* raise, int* round, int* player_round);
	void doCall(int n, int mon, int* round);
};