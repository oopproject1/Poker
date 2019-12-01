#pragma once
#include<iostream>
#include <string>
#include "Card.h"
using namespace std;

class Player {
private:
	Card card[5];
	int money;
	bool lose;
	int cardLength;
	int bettingMoney;
	string bettingStart;
	bool death;
public:
	
	Player();
	void playerDrow();
	int getMoney();
	bool getLose();
	int getCardLength();
	void setMoney(int newMoney);
	void setLose(bool newLose);
	void setCardLength(int newCardLength);
	Card* getCard();
};
