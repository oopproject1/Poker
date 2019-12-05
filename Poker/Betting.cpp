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



//���Ƿ� ���� ���� ���ú���, *ǥ�ú������� �ܺο��� �޾ƿ;��� �������̴�.
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
	cardLength = 3; // �÷��̾ ������ ī�尳�� *
	minBetting = 100; // �⺻���ñݾ� *
}
//�ӽ� getter
int Betting::getBettingMoney() { return this->bettingMoney; }
string Betting::getBettingStart() { return this->bettingStart; }
bool Betting::getDeath() { return this->death; }


//�ӽ� setter
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

//���ý��۸޼ҵ�
int Betting::BettingRun(Player* user, Player* npc1, Player* npc2, Player* npc3) {
	round = 0;
	roundMoney = 0;
	//�÷��̾� ī��
	if (user->getLose() == true) {
		cout << "����� �̹� �й��� �����Դϴ�." << endl;
		cout << "" << endl;
		return 0;
	}
	else if (user->getMoney() < minBetting) {
		user->setLose(true);
		cout << "�ּҺ��ñݾ��� �������� ���Ͽ� �й��Ͽ����ϴ�." << endl;
		cout << "" << endl;
		return 0;
	}
	else if (user->getLose() == false) {
		user->setMoney(user->getMoney() - minBetting);
		npc1->setMoney(npc1->getMoney() - minBetting);
		npc2->setMoney(npc2->getMoney() - minBetting);
		npc3->setMoney(npc3->getMoney() - minBetting);
		roundMoney += (minBetting * 4);
		cout << "�⺻���ñݾ� " << minBetting << "�� �����߽��ϴ�." << endl;
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
				cout << "���ù���� �Է��ϼ���. (1.������ 2.üũ 3.����)" << endl;
				cin >> BettingType;
				cout << "" << endl;
				if (BettingType == "1" || BettingType == "2" || BettingType == "3")
					break;
			}
			if (BettingType == "1") {
				cout << "[������]���ñݾ��� �Է��ϼ���. ���纸���ݾ��� " << user->getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�." << endl;
				int tempBM;
				cin >> tempBM;
				cout << "" << endl;
				cout << "" << endl;
				raiseMoney += tempBM;
				this->setBettingMoney(tempBM);
				if (this->getBettingMoney() > user->getMoney()) {
					while (true) {
						cout << "�����ݾ��� �ʰ��Ͽ����ϴ�." << endl;
						raiseMoney = 0;
						tempBM = 0;
						this->setBettingMoney(0);
						cout << "[������]���ñݾ��� �Է��ϼ���. ���纸���ݾ��� " << user->getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�." << endl;
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
					//cout << this->getBettingMoney() << "���� �����Ͽ����ϴ�. ���纸���ݾ��� " << player->getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�." << endl;
					//roundMoney += getNpcBettingMoney();
				}
			}
			else if (BettingType == "2") {
				cout << "[üũ] üũ�Ͽ� �ǵ��� �߰����� �ʽ��ϴ�. ���纸���ݾ��� " << user->getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�. " << endl;
				cout << "" << endl;
			}
			else if (BettingType == "3") {
				cout << "[����] ������ �����մϴ�." << endl;
				cout << "" << endl;
				user->setLose(true);
				return roundMoney;
			}

			n1 = (rand() % 401) + 100;
			n2 = (rand() % 401) + 100;
			n3 = (rand() % 401) + 100;

			cout << "�÷��̾�2";
			npc1->setMoney(npc1->getMoney() - raiseMoney - n1);
			npc1->doBet(n1, npc1->getMoney(), &raiseMoney, &roundMoney, &n1round);
			//cout << "�÷��̾�2 ��" << n1 << "���� �������Ͽ��� " << raiseMoney << " �� �����Ͽ����ϴ�. ������: " << npc1->getMoney() << endl;
			//cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

			cout << "�÷��̾�3";
			npc2->setMoney(npc2->getMoney() - raiseMoney - n2);
			npc2->doBet(n2, npc2->getMoney(), &raiseMoney, &roundMoney, &n2round);
			//cout << "�÷��̾�3 ��" << n2 << "���� �������Ͽ��� " << raiseMoney << " �� �����Ͽ����ϴ�. ������: " << npc2->getMoney() << endl;
			//cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;


			cout << "�÷��̾�4";
			npc3->setMoney(npc3->getMoney() - raiseMoney - n3);
			npc3->doBet(n3, npc3->getMoney(), &raiseMoney, &roundMoney, &n3round);
			//cout << "�÷��̾�4 ��" << n3 << "���� �������Ͽ��� " << raiseMoney << " �� �����Ͽ����ϴ�. ������: " << npc3->getMoney() << endl;
			//cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

			while (true) {
				cout << "���ù���� �Է��ϼ���. (1.������ 2.�� 3.����)" << endl;
				cin >> BettingType;
				cout << "" << endl;
				if (BettingType == "1" || BettingType == "2" || BettingType == "3")
					break;
			}
			if (BettingType == "1") {
				cout << "[������]���ñݾ��� �Է��ϼ���. ���纸���ݾ��� " << user->getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�." << endl;
				int tempBM;
				cin >> tempBM;
				cout << "" << endl;
				this->setBettingMoney(tempBM);
				if (this->getBettingMoney() > user->getMoney()) {
					while (true) {
						cout << "�����ݾ��� �ʰ��Ͽ����ϴ�." << endl;
						raiseMoney = 0;
						tempBM = 0;
						this->setBettingMoney(0);
						cout << "[������]���ñݾ��� �Է��ϼ���. ���纸���ݾ��� " << user->getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�." << endl;
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
					//cout << this->getBettingMoney() << "���� �����Ͽ����ϴ�. ���纸���ݾ��� " << player->getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�." << endl;

					//roundMoney += getNpcBettingMoney();
				}
			}
			else if (BettingType == "2") {
				cout << "[��] ���纸���ݾ��� " << user->getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�. " << endl;
				cout << "" << endl;
				user->setMoney(user->getMoney() - (n3round - pround));
				user->doCall(n3round - pround, user->getMoney(), &roundMoney);


				cout << "�÷��̾�2";
				n1 = n3round - n1round;
				npc1->setMoney(npc1->getMoney() - (n1));
				npc1->doCall(n1, npc1->getMoney(), &roundMoney);
				//cout << "�÷��̾�2 �� ���� �ؼ�" << n3round - n1round << " ���� �����Ͽ����ϴ�." << endl;
				//cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

				cout << "�÷��̾�3";
				n2 = n3round - n2round;
				npc2->setMoney(npc2->getMoney() - (n2));
				npc2->doCall(n2, npc2->getMoney(), &roundMoney);
				//cout << "�÷��̾�3 �� ���� �ؼ�" << n3round - n2round << " ���� �����Ͽ����ϴ�." << endl;
				//cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

				cout << "�÷��̾�4";
				n3 = 0;
				npc3->doCall(n3, npc3->getMoney(), &roundMoney);
				//cout << "�÷��̾�4 �� ���� �ؼ�" << 0 << " ���� �����Ͽ����ϴ�." << endl;
				//cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;
				round++;
				continue;
			}
			else if (BettingType == "3") {
				cout << "[����] ������ �����մϴ�." << endl;
				user->setLose(true);
				return roundMoney;
			}

			n1 = (rand() % 401) + 100;
			n2 = (rand() % 401) + 100;
			n3 = (rand() % 401) + 100;


			cout << "�÷��̾�2";
			npc1->setMoney(npc1->getMoney() - raiseMoney - n1);
			npc1->doBet(n1, npc1->getMoney(), &raiseMoney, &roundMoney, &n1round);
			//cout << "�÷��̾�2 ��" << n1 << "���� �������Ͽ��� " << raiseMoney << " �� �����Ͽ����ϴ�. ������: " << npc1->getMoney() << endl;
			//cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

			cout << "�÷��̾�3";
			npc2->setMoney(npc2->getMoney() - raiseMoney - n2);
			npc2->doBet(n2, npc2->getMoney(), &raiseMoney, &roundMoney, &n2round);
			//cout << "�÷��̾�3 ��" << n2 << "���� �������Ͽ��� " << raiseMoney << " �� �����Ͽ����ϴ�. ������: " << npc2->getMoney() << endl;
			//cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;


			cout << "�÷��̾�4";
			npc3->setMoney(npc3->getMoney() - raiseMoney - n3);
			npc3->doBet(n3, npc3->getMoney(), &raiseMoney, &roundMoney, &n3round);
			//cout << "�÷��̾�4 ��" << n3 << "���� �������Ͽ��� " << raiseMoney << " �� �����Ͽ����ϴ�. ������: " << npc3->getMoney() << endl;
			//cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

			while (true) {
				cout << "���ù���� �Է��ϼ���. (1.�� 2.����)" << endl;
				cin >> BettingType;
				if (BettingType == "1" || BettingType == "2")
					break;
			}

			if (BettingType == "1") {
				cout << "[��] ���纸���ݾ��� " << user->getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�. " << endl;
				user->setMoney(user->getMoney() - (n3round - pround));
				user->doCall(n3round - pround, user->getMoney(), &roundMoney);


				cout << "�÷��̾�2";
				n1 = n3round - n1round;
				npc1->setMoney(npc1->getMoney() - (n1));
				npc1->doCall(n1, npc1->getMoney(), &roundMoney);
				//cout << "�÷��̾�2 �� ���� �ؼ�" << n3round - n1round << " ���� �����Ͽ����ϴ�." << endl;
				//cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

				cout << "�÷��̾�3";
				n2 = n3round - n2round;
				npc2->setMoney(npc2->getMoney() - (n2));
				npc2->doCall(n2, npc2->getMoney(), &roundMoney);
				//cout << "�÷��̾�3 �� ���� �ؼ�" << n3round - n2round << " ���� �����Ͽ����ϴ�." << endl;
				//cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

				cout << "�÷��̾�4";
				n3 = 0;
				npc3->doCall(n3, npc3->getMoney(), &roundMoney);
				//cout << "�÷��̾�4 �� ���� �ؼ�" << 0 << " ���� �����Ͽ����ϴ�." << endl;
				//cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;
			}

			else if (BettingType == "2") {
				cout << "[����] ������ �����մϴ�." << endl;
				user->setLose(true);
				return roundMoney;
			}
			round++;
		}


	}
	cout << "Player1�� �д�" << endl;
	for (int i = 0; i < 5; i++) {
		Card* cardget = user->getCard();
		cardget[i].cardprint();
	}
	Sleep(1000);
	std::cout << std::endl;
	cout << "Player2�� �д�" << endl;
	for (int i = 0; i < 5; i++) { //n1 test ���
		Card* cardget = npc1->getCard();
		cardget[i].cardprint();
	}
	Sleep(1000);
	std::cout << std::endl;
	cout << "Player3�� �д�" << endl;
	for (int i = 0; i < 5; i++) { //n2 test ���
		Card* cardget = npc2->getCard();
		cardget[i].cardprint();
	}
	Sleep(1000);
	std::cout << std::endl;
	cout << "Player4�� �д�" << endl;
	for (int i = 0; i < 5; i++) { //n3 test ���
		Card* cardget = npc3->getCard();
		cardget[i].cardprint();
	}
	Sleep(1000);
	std::cout << std::endl;
	return roundMoney;
}