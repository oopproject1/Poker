#include <iostream>
#include "Card.h"
#include "Betting.h"
#include "Player.h"
#include "Rule.h"
#include "User.h"
#include "Npc.h"

class Dealer {

public:

	void start() { //���� ���� 
		std::cout << "������ �����մϴ�." << std::endl;
		std::cout << "���� �����մϴ�." << std::endl;
		std::cout << "ī�带 3�徿 �����ݴϴ�." << std::endl;
	}

	void card() { //ī�� ���徿
		std::cout << "ī�带 ���徿 �����ݴϴ�." << std::endl;
	}

};

int main() {
	Dealer dealer;

	Player* user = new User();
	Player* npc1 = new Npc();
	Player* npc2 = new Npc();
	Player* npc3 = new Npc();

	Rule rule;

	Betting pbet;
	
	while(true){
		dealer.start();
		user->playerDrow();
		npc1->playerDrow();
		npc2->playerDrow();
		npc3->playerDrow();
		int money_ = pbet.BettingRun(user, npc1, npc2, npc3);
		if (user->getLose()) {
			user->setLose(false);
			npc1->setMoney(npc1->getMoney() + (money_ / 3));
			npc2->setMoney(npc2->getMoney() + (money_ / 3));
			npc3->setMoney(npc3->getMoney() + (money_ / 3));
		}
		else {
			int x = rule.priority(user->getCard(), npc1->getCard(), npc2->getCard(), npc3->getCard());
			if (x == 0) {
				user->setMoney(user->getMoney() + (money_ / 4));
				npc1->setMoney(npc1->getMoney() + (money_ / 4));
				npc2->setMoney(npc2->getMoney() + (money_ / 4));
				npc3->setMoney(npc3->getMoney() + (money_ / 4));
			}
			else {
				if (x == 1) {
					user->setMoney(user->getMoney() + money_);
				}
				else if (x == 2) {
					npc1->setMoney(npc1->getMoney() + money_);
				}
				else if (x == 3) {
					npc2->setMoney(npc2->getMoney() + money_);
				}
				else {
					npc3->setMoney(npc3->getMoney() + money_);
				}
			}
		}
		std::cout << "������ ��� �����Ͻðڽ��ϱ�?(Y/N)" << std::endl;
		char inp;
		std::cin >> inp;
		if (inp == 'N' || inp=='n')
			break;
		Card c;
		c.shuffle();
	}
	return 0;

}