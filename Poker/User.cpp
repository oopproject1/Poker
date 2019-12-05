#include "Player.h"
#include "User.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Player.h"
#include "Card.h"
using namespace std;


User::User() {
	money = 100000;
	lose = false;
	bettingMoney = 0;
	bettingStart = "Y";
	death = false;
}



void User::playerDrow() {
	for (int i = 0; i < 5; i++) {
		card[i].cardDrow();
	}
}
int User::getMoney() { return this->money; }
bool User::getLose() { return this->lose; }
int User::getCardLength() { return this->cardLength; }
void User::setMoney(int newMoney) { this->money = newMoney; }
void User::setLose(bool newLose) { this->lose = newLose; }
void User::setCardLength(int newCardLength) { this->cardLength = newCardLength; }
Card* User::getCard() {
	return card;
}
void User::doBet(int n, int mon, int* raise, int* round, int* player_round) {
	*round += *raise;
	*player_round += *raise;
	cout << n << "원을 베팅하였습니다. 현재보유금액은 " << mon << ", 판돈은 " << *round << " 입니다." << endl;
}
void User::doCall(int n, int mon, int* round) {
	*round += n;
	cout << "현재보유금액은 " << mon << ", 판돈은 " << *round << " 입니다." << endl;
}