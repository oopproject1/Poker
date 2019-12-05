#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
//#include "Rule.h"
#include "Card.h"
#include "Player.h"
#include "Betting.h"
#include <Windows.h>
using namespace std;



//임의로 값을 넣은 예시변수, *표시변수들은 외부에서 받아와야할 변수들이다.
Betting::Betting() {
	srand((unsigned int)time(NULL));
	n1 = (rand() % 401) + 100;
	n2 = (rand() % 401) + 100;
	n3 = (rand() % 401) + 100;
	pround = 0;
	n1round = 0;
	n2round = 0;
	n3round = 0;
	raiseMoney = 0;
	roundMoney = 0;
	round = 0;
	cardLength = 3; // 플레이어가 보유한 카드개수 *
	minBetting = 100; // 기본베팅금액 *
}
//임시 getter
int Betting::getBettingMoney() { return this->bettingMoney; }
string Betting::getBettingStart() { return this->bettingStart; }
bool Betting::getDeath() { return this->death; }


//임시 setter
void Betting::setBettingMoney(int newBettingMoney) { this->bettingMoney = newBettingMoney; }
void Betting::setBettingStart(string newBettingStart) { this->bettingStart = newBettingStart; }
void Betting::setDeath(bool newDeath) { this->death = newDeath; }
void Betting::notEnoughMoney() {

}


//Betting(int getMoney, bool getLose) {
//   money = getMoney;
//   lose = getLose;
//   bettingMoney = 0;
//   bettingStart = "Y";
//   death = false;
//}

//베팅시작메소드
int Betting::BettingRun(Player* user, Player* npc1, Player* npc2, Player* npc3) {
	round = 0;
	roundMoney = 0;
	//플레이어 카드
	if (user->getLose() == true) {
		cout << "당신은 이미 패배한 상태입니다." << endl;
		cout << "" << endl;
		return 0;
	}
	else if (user->getMoney() < minBetting) {
		user->setLose(true);
		cout << "최소베팅금액을 충족하지 못하여 패배하였습니다." << endl;
		cout << "" << endl;
		return 0;
	}
	else if (user->getLose() == false) {
		user->setMoney(user->getMoney() - minBetting);
		npc1->setMoney(npc1->getMoney() - minBetting);
		npc2->setMoney(npc2->getMoney() - minBetting);
		npc3->setMoney(npc3->getMoney() - minBetting);
		roundMoney += (minBetting * 4);
		cout << "기본베팅금액 " << minBetting << "을 지불했습니다." << endl;
		cout << "" << endl;



		while (round < 3) {


			Card* cardget = user->getCard();



			for (int i = 0; i < 3 + round; i++) {
				cardget[i].cardprint();
			}
			std::cout << std::endl;

			pround = 0;
			n1round = 0;
			n2round = 0;
			n3round = 0;
			raiseMoney = 0;

			string BettingType;
			while (true) {
				cout << "베팅방식을 입력하세요. (1.레이즈 2.체크 3.폴드)" << endl;
				cin >> BettingType;
				cout << "" << endl;
				if (BettingType == "1" || BettingType == "2" || BettingType == "3")
					break;
			}
			if (BettingType == "1") {
				cout << "[레이즈]베팅금액을 입력하세요. 현재보유금액은 " << user->getMoney() << ", 판돈은 " << roundMoney << " 입니다." << endl;
				int tempBM;
				cin >> tempBM;
				cout << "" << endl;
				cout << "" << endl;
				raiseMoney += tempBM;
				this->setBettingMoney(tempBM);
				if (this->getBettingMoney() > user->getMoney()) {
					while (true) {
						cout << "보유금액을 초과하였습니다." << endl;
						raiseMoney = 0;
						tempBM = 0;
						this->setBettingMoney(0);
						cout << "[레이즈]베팅금액을 입력하세요. 현재보유금액은 " << user->getMoney() << ", 판돈은 " << roundMoney << " 입니다." << endl;
						cin >> tempBM;
						cout << "" << endl;
						raiseMoney += tempBM;
						this->setBettingMoney(tempBM);
						if (this->getBettingMoney() < user->getMoney()) {
							break;
						}
					}
					user->setMoney(user->getMoney() - getBettingMoney());
					user->doBet(tempBM, user->getMoney(), &raiseMoney, &roundMoney, &pround);

				}
				else {
					user->setMoney(user->getMoney() - getBettingMoney());
					user->doBet(tempBM, user->getMoney(), &raiseMoney, &roundMoney, &pround);
					//cout << this->getBettingMoney() << "원을 베팅하였습니다. 현재보유금액은 " << player->getMoney() << ", 판돈은 " << roundMoney << " 입니다." << endl;
					//roundMoney += getNpcBettingMoney();
				}
			}
			else if (BettingType == "2") {
				cout << "[체크] 체크하여 판돈을 추가하지 않습니다. 현재보유금액은 " << user->getMoney() << ", 판돈은 " << roundMoney << " 입니다. " << endl;
				cout << "" << endl;
			}
			else if (BettingType == "3") {
				cout << "[폴드] 게임을 포기합니다." << endl;
				cout << "" << endl;
				user->setLose(true);
				return roundMoney;
			}

			n1 = (rand() % 401) + 100;
			n2 = (rand() % 401) + 100;
			n3 = (rand() % 401) + 100;

			cout << "플레이어2";
			npc1->setMoney(npc1->getMoney() - raiseMoney - n1);
			npc1->doBet(n1, npc1->getMoney(), &raiseMoney, &roundMoney, &n1round);
			//cout << "플레이어2 은" << n1 << "원을 레이즈하여서 " << raiseMoney << " 를 지불하였습니다. 보유금: " << npc1->getMoney() << endl;
			//cout << "판돈은 " << roundMoney << " 입니다." << endl;

			cout << "플레이어3";
			npc2->setMoney(npc2->getMoney() - raiseMoney - n2);
			npc2->doBet(n2, npc2->getMoney(), &raiseMoney, &roundMoney, &n2round);
			//cout << "플레이어3 은" << n2 << "원을 레이즈하여서 " << raiseMoney << " 를 지불하였습니다. 보유금: " << npc2->getMoney() << endl;
			//cout << "판돈은 " << roundMoney << " 입니다." << endl;


			cout << "플레이어4";
			npc3->setMoney(npc3->getMoney() - raiseMoney - n3);
			npc3->doBet(n3, npc3->getMoney(), &raiseMoney, &roundMoney, &n3round);
			//cout << "플레이어4 은" << n3 << "원을 레이즈하여서 " << raiseMoney << " 를 지불하였습니다. 보유금: " << npc3->getMoney() << endl;
			//cout << "판돈은 " << roundMoney << " 입니다." << endl;

			while (true) {
				cout << "베팅방식을 입력하세요. (1.레이즈 2.콜 3.폴드)" << endl;
				cin >> BettingType;
				cout << "" << endl;
				if (BettingType == "1" || BettingType == "2" || BettingType == "3")
					break;
			}
			if (BettingType == "1") {
				cout << "[레이즈]베팅금액을 입력하세요. 현재보유금액은 " << user->getMoney() << ", 판돈은 " << roundMoney << " 입니다." << endl;
				int tempBM;
				cin >> tempBM;
				cout << "" << endl;
				this->setBettingMoney(tempBM);
				if (this->getBettingMoney() > user->getMoney()) {
					while (true) {
						cout << "보유금액을 초과하였습니다." << endl;
						raiseMoney = 0;
						tempBM = 0;
						this->setBettingMoney(0);
						cout << "[레이즈]베팅금액을 입력하세요. 현재보유금액은 " << user->getMoney() << ", 판돈은 " << roundMoney << " 입니다." << endl;
						cin >> tempBM;
						cout << "" << endl;
						raiseMoney += tempBM;
						this->setBettingMoney(tempBM);
						if (this->getBettingMoney() < user->getMoney()) {
							break;
						}
					}
					user->setMoney(user->getMoney() - getBettingMoney());
					user->doBet(tempBM, user->getMoney(), &raiseMoney, &roundMoney, &pround);
				}
				else {
					user->setMoney(user->getMoney() - (getBettingMoney() + raiseMoney));
					raiseMoney += getBettingMoney();
					user->doBet(tempBM, user->getMoney(), &raiseMoney, &roundMoney, &pround);
					//cout << this->getBettingMoney() << "원을 베팅하였습니다. 현재보유금액은 " << player->getMoney() << ", 판돈은 " << roundMoney << " 입니다." << endl;

					//roundMoney += getNpcBettingMoney();
				}
			}
			else if (BettingType == "2") {
				cout << "[콜] 현재보유금액은 " << user->getMoney() << ", 판돈은 " << roundMoney << " 입니다. " << endl;
				cout << "" << endl;
				user->setMoney(user->getMoney() - (n3round - pround));
				user->doCall(n3round - pround, user->getMoney(), &roundMoney);


				cout << "플레이어2";
				n1 = n3round - n1round;
				npc1->setMoney(npc1->getMoney() - (n1));
				npc1->doCall(n1, npc1->getMoney(), &roundMoney);
				//cout << "플레이어2 은 콜을 해서" << n3round - n1round << " 원을 지불하였습니다." << endl;
				//cout << "판돈은 " << roundMoney << " 입니다." << endl;

				cout << "플레이어3";
				n2 = n3round - n2round;
				npc2->setMoney(npc2->getMoney() - (n2));
				npc2->doCall(n2, npc2->getMoney(), &roundMoney);
				//cout << "플레이어3 은 콜을 해서" << n3round - n2round << " 원을 지불하였습니다." << endl;
				//cout << "판돈은 " << roundMoney << " 입니다." << endl;

				cout << "플레이어4";
				n3 = 0;
				npc3->doCall(n3, npc3->getMoney(), &roundMoney);
				//cout << "플레이어4 은 콜을 해서" << 0 << " 원을 지불하였습니다." << endl;
				//cout << "판돈은 " << roundMoney << " 입니다." << endl;
				round++;
				continue;
			}
			else if (BettingType == "3") {
				cout << "[폴드] 게임을 포기합니다." << endl;
				user->setLose(true);
				return roundMoney;
			}

			n1 = (rand() % 401) + 100;
			n2 = (rand() % 401) + 100;
			n3 = (rand() % 401) + 100;


			cout << "플레이어2";
			npc1->setMoney(npc1->getMoney() - raiseMoney - n1);
			npc1->doBet(n1, npc1->getMoney(), &raiseMoney, &roundMoney, &n1round);
			//cout << "플레이어2 은" << n1 << "원을 레이즈하여서 " << raiseMoney << " 를 지불하였습니다. 보유금: " << npc1->getMoney() << endl;
			//cout << "판돈은 " << roundMoney << " 입니다." << endl;

			cout << "플레이어3";
			npc2->setMoney(npc2->getMoney() - raiseMoney - n2);
			npc2->doBet(n2, npc2->getMoney(), &raiseMoney, &roundMoney, &n2round);
			//cout << "플레이어3 은" << n2 << "원을 레이즈하여서 " << raiseMoney << " 를 지불하였습니다. 보유금: " << npc2->getMoney() << endl;
			//cout << "판돈은 " << roundMoney << " 입니다." << endl;


			cout << "플레이어4";
			npc3->setMoney(npc3->getMoney() - raiseMoney - n3);
			npc3->doBet(n3, npc3->getMoney(), &raiseMoney, &roundMoney, &n3round);
			//cout << "플레이어4 은" << n3 << "원을 레이즈하여서 " << raiseMoney << " 를 지불하였습니다. 보유금: " << npc3->getMoney() << endl;
			//cout << "판돈은 " << roundMoney << " 입니다." << endl;

			while (true) {
				cout << "베팅방식을 입력하세요. (1.콜 2.폴드)" << endl;
				cin >> BettingType;
				if (BettingType == "1" || BettingType == "2")
					break;
			}

			if (BettingType == "1") {
				cout << "[콜] 현재보유금액은 " << user->getMoney() << ", 판돈은 " << roundMoney << " 입니다. " << endl;
				user->setMoney(user->getMoney() - (n3round - pround));
				user->doCall(n3round - pround, user->getMoney(), &roundMoney);


				cout << "플레이어2";
				n1 = n3round - n1round;
				npc1->setMoney(npc1->getMoney() - (n1));
				npc1->doCall(n1, npc1->getMoney(), &roundMoney);
				//cout << "플레이어2 은 콜을 해서" << n3round - n1round << " 원을 지불하였습니다." << endl;
				//cout << "판돈은 " << roundMoney << " 입니다." << endl;

				cout << "플레이어3";
				n2 = n3round - n2round;
				npc2->setMoney(npc2->getMoney() - (n2));
				npc2->doCall(n2, npc2->getMoney(), &roundMoney);
				//cout << "플레이어3 은 콜을 해서" << n3round - n2round << " 원을 지불하였습니다." << endl;
				//cout << "판돈은 " << roundMoney << " 입니다." << endl;

				cout << "플레이어4";
				n3 = 0;
				npc3->doCall(n3, npc3->getMoney(), &roundMoney);
				//cout << "플레이어4 은 콜을 해서" << 0 << " 원을 지불하였습니다." << endl;
				//cout << "판돈은 " << roundMoney << " 입니다." << endl;
			}

			else if (BettingType == "2") {
				cout << "[폴드] 게임을 포기합니다." << endl;
				user->setLose(true);
				return roundMoney;
			}
			round++;
		}


	}
	cout << "Player1의 패는" << endl;
	for (int i = 0; i < 5; i++) {
		Card* cardget = user->getCard();
		cardget[i].cardprint();
	}
	Sleep(1000);
	std::cout << std::endl;
	cout << "Player2의 패는" << endl;
	for (int i = 0; i < 5; i++) { //n1 test 출력
		Card* cardget = npc1->getCard();
		cardget[i].cardprint();
	}
	Sleep(1000);
	std::cout << std::endl;
	cout << "Player3의 패는" << endl;
	for (int i = 0; i < 5; i++) { //n2 test 출력
		Card* cardget = npc2->getCard();
		cardget[i].cardprint();
	}
	Sleep(1000);
	std::cout << std::endl;
	cout << "Player4의 패는" << endl;
	for (int i = 0; i < 5; i++) { //n3 test 출력
		Card* cardget = npc3->getCard();
		cardget[i].cardprint();
	}
	Sleep(1000);
	std::cout << std::endl;
	return roundMoney;
}