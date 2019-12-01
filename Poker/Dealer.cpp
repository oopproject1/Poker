#include <iostream>
#include "Card.h"
#include "Betting.h"
#include "Player.h"
#include "Rule.h"

class Dealer {

public:

	void start() { //게임 시작 
		std::cout << "게임을 시작합니다." << std::endl;
		std::cout << "덱을 셔플합니다." << std::endl;
		std::cout << "카드를 3장씩 나눠줍니다." << std::endl;
	}

	void card() { //카드 한장씩
		std::cout << "카드를 한장씩 나눠줍니다." << std::endl;
	}

};

int main() {
	Dealer dealer;

	Player p;
	Player npc1;
	Player npc2;
	Player npc3;

	Rule rule;

	Betting pbet;
	
	while(true){
		dealer.start();
		p.playerDrow();
		npc1.playerDrow();
		npc2.playerDrow();
		npc3.playerDrow();
		int money_ = pbet.BettingRun(p, npc1, npc2, npc3);
		if (p.getLose()) {
			p.setLose(false);
			npc1.setMoney(npc1.getMoney() + (money_ / 3));
			npc2.setMoney(npc2.getMoney() + (money_ / 3));
			npc3.setMoney(npc3.getMoney() + (money_ / 3));
		}
		else {
			if (int x = rule.priority(p.getCard(), npc1.getCard(), npc2.getCard(), npc3.getCard()) == 0) {
				p.setMoney(p.getMoney() + (money_ / 4));
				npc1.setMoney(npc1.getMoney() + (money_ / 4));
				npc2.setMoney(npc2.getMoney() + (money_ / 4));
				npc3.setMoney(npc3.getMoney() + (money_ / 4));
			}
			else {
				if (x == 1) {
					p.setMoney(p.getMoney() + money_);
				}
				else if (x == 2) {
					npc1.setMoney(npc1.getMoney() + money_);
				}
				else if (x == 3) {
					npc2.setMoney(npc2.getMoney() + money_);
				}
				else {
					npc3.setMoney(npc3.getMoney() + money_);
				}
			}
		}
		std::cout << "게임을 계속 진행하시겠습니까?(Y/N)" << std::endl;
		char inp;
		std::cin >> inp;
		if (inp == 'N' || inp=='n')
			break;
		Card c;
		c.shuffle();
	}
	return 0;

}