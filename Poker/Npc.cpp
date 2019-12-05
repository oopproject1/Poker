#include "Npc.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Player.h"
#include "Card.h"
using namespace std;


Npc::Npc() {
	money = 100000;
	lose = false;
	bettingMoney = 0;
	bettingStart = "Y";
	death = false;
}



void Npc::playerDrow() {
	for (int i = 0; i < 5; i++) {
		card[i].cardDrow();
	}
}
int Npc::getMoney() { return this->money; }
bool Npc::getLose() { return this->lose; }
int Npc::getCardLength() { return this->cardLength; }
void Npc::setMoney(int newMoney) { this->money = newMoney; }
void Npc::setLose(bool newLose) { this->lose = newLose; }
void Npc::setCardLength(int newCardLength) { this->cardLength = newCardLength; }
Card* Npc::getCard() {return card;}
void Npc::doBet(int n, int mon, int* raise, int* round, int* player_round) {
	*raise += n;
	*round += *raise;
	*player_round += *raise;
	cout << " 은" << n << "원을 레이즈하여서 " << *raise << " 를 지불하였습니다. 보유금: " << mon << endl;
	cout << "판돈은 " << *round << " 입니다." << endl;
}
void Npc::doCall(int n, int mon, int* round) {
	*round += n;
	cout << "플레이어3 은 콜을 해서" << n << " 원을 지불하였습니다. 보유금: " << mon << endl;
	cout << "판돈은 " << *round << " 입니다." << endl;
}
