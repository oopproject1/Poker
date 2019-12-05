#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Player.h"
#include "Card.h"
using namespace std;


Player::Player() {
	money = 100000;
	lose = false;
	bettingMoney = 0;
	bettingStart = "Y";
	death = false;
}



void Player::playerDrow() {
	for (int i = 0; i < 5; i++) {
		card[i].cardDrow();
	}
}
int Player::getMoney() { return this->money; }
bool Player::getLose() { return this->lose; }
int Player::getCardLength() { return this->cardLength; }
void Player::setMoney(int newMoney) { this->money = newMoney; }
void Player::setLose(bool newLose) { this->lose = newLose; }
void Player::setCardLength(int newCardLength) { this->cardLength = newCardLength; }
Card* Player::getCard() {
	return card;
}
void Player::doBet(int n, int mon, int* raise, int* round, int* player_round) {
	return;
}
void Player::doCall(int n, int mon, int* round) {
	return;
}