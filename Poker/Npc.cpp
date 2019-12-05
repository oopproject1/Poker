#include "Npc.h"
#include "Player.h"
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
	cout << " ��" << n << "���� �������Ͽ��� " << *raise << " �� �����Ͽ����ϴ�. ������: " << mon << endl;
	cout << "�ǵ��� " << *round << " �Դϴ�." << endl;
}
void Npc::doCall(int n, int mon, int* round) {
	*round += n;
	cout << "�÷��̾�3 �� ���� �ؼ�" << n << " ���� �����Ͽ����ϴ�. ������: " << mon << endl;
	cout << "�ǵ��� " << *round << " �Դϴ�." << endl;
}