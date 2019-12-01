#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
//#include "Rule.h"
#include "Card.h"
#include "Player.h"
#include "Betting.h"
using namespace std;



//���Ƿ� ���� ���� ���ú���, *ǥ�ú������� �ܺο��� �޾ƿ;��� �������̴�.
Betting::Betting() {
	srand((unsigned int)time(NULL));
	n1 = (rand() % 401) + 100;
	n2 = (rand() % 401) + 100;
	n3 = (rand() % 401) + 100;
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


//Betting(int getMoney, bool getLose) {
//   money = getMoney;
//   lose = getLose;
//   bettingMoney = 0;
//   bettingStart = "Y";
//   death = false;
//}

//���ý��۸޼ҵ�
int Betting::BettingRun(Player& player, Player& npc1, Player& npc2, Player& npc3) {
	round = 0;
	roundMoney = 0;
	//�÷��̾� ī��
	if (player.getLose() == true) {
		cout << "����� �̹� �й��� �����Դϴ�." << endl;
		return 0;
	}
	else if (player.getMoney() < minBetting) {
		player.setLose(true);
		cout << "�ּҺ��ñݾ��� �������� ���Ͽ� �й��Ͽ����ϴ�." << endl;
		return 0;
	}
	else if (player.getLose() == false) {
		player.setMoney(player.getMoney() - minBetting);
		roundMoney += (minBetting * 4);
		cout << "�⺻���ñݾ� " << minBetting << "�� �����߽��ϴ�." << endl;

		

		while (round < 3) {
			

			Card* cardget = player.getCard();
			
			
			
			for (int i = 0; i < 3 + round; i++) {
				cardget[i].cardprint();
			}
			std::cout << std::endl;
			
			pround = 0;
			n1round = 0;
			n2round = 0;
			n3round = 0;
			raiseMoney = 0;
			
			cout << "���ù���� �Է��ϼ���. (1.������ 2.üũ 3.����)" << endl;
			string BettingType;
			cin >> BettingType;
			if (BettingType == "1") {
				cout << "[������]���ñݾ��� �Է��ϼ���. ���纸���ݾ��� " << player.getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�." << endl;
				int tempBM;
				cin >> tempBM;
				raiseMoney += tempBM;
				this->setBettingMoney(tempBM);
				if (this->getBettingMoney() > player.getMoney()) {
					cout << "�����ݾ��� �ʰ��Ͽ����ϴ�." << endl;
				}
				else {
					player.setMoney(player.getMoney() - getBettingMoney());
					roundMoney += getBettingMoney();
					pround += getBettingMoney();
					cout << this->getBettingMoney() << "���� �����Ͽ����ϴ�. ���纸���ݾ��� " << player.getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�." << endl;
					//roundMoney += getNpcBettingMoney();
				}
			}
			else if (BettingType == "2") {
				cout << "[üũ] üũ�Ͽ� �ǵ��� �߰����� �ʽ��ϴ�. ���纸���ݾ��� " << player.getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�. " << endl;
			}
			else if (BettingType == "3") {
				cout << "[����] ������ �����մϴ�." << endl;
				player.setLose(true);
				return roundMoney;
			}

			n1 = (rand() % 401) + 100;
			n2 = (rand() % 401) + 100;
			n3 = (rand() % 401) + 100;
			
			raiseMoney += n1;
			roundMoney += raiseMoney;
			n1round += raiseMoney;
			npc1.setMoney(npc1.getMoney() - n1round);
			cout << "�÷��̾�2 ��" << n1 << "���� �������Ͽ��� " << raiseMoney << " �� �����Ͽ����ϴ�. ������: " << npc1.getMoney() << endl;
			cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

			raiseMoney += n2;
			roundMoney += raiseMoney;
			n2round += raiseMoney;
			npc2.setMoney(npc2.getMoney() - n2round);
			cout << "�÷��̾�3 ��" << n2 << "���� �������Ͽ��� " << raiseMoney << " �� �����Ͽ����ϴ�. ������: " << npc2.getMoney() << endl;
			cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

			raiseMoney += n3;
			roundMoney += raiseMoney;
			n3round += raiseMoney;
			npc3.setMoney(npc3.getMoney() - n3round);
			cout << "�÷��̾�4 ��" << n3 << "���� �������Ͽ��� " << raiseMoney << " �� �����Ͽ����ϴ�. ������: " << npc3.getMoney() << endl;
			cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

			cout << "���ù���� �Է��ϼ���. (1.������ 2.�� 3.����)" << endl;
			BettingType;
			cin >> BettingType;
			if (BettingType == "1") {
				cout << "[������]���ñݾ��� �Է��ϼ���. ���纸���ݾ��� " << player.getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�." << endl;
				int tempBM;
				cin >> tempBM;
				this->setBettingMoney(tempBM);
				if (this->getBettingMoney() > player.getMoney()) {
					cout << "�����ݾ��� �ʰ��Ͽ����ϴ�." << endl;
				}
				else {
					player.setMoney(player.getMoney() - (getBettingMoney() + raiseMoney));
					raiseMoney += getBettingMoney();
					roundMoney += raiseMoney;
					pround += raiseMoney;
					cout << this->getBettingMoney() << "���� �����Ͽ����ϴ�. ���纸���ݾ��� " << player.getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�." << endl;

					//roundMoney += getNpcBettingMoney();
				}
			}
			else if (BettingType == "2") {
				cout << "[��] ���纸���ݾ��� " << player.getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�. " << endl;
				player.setMoney(player.getMoney() - (n3round - pround));

				roundMoney += n3round - pround;
				cout << "���纸���ݾ��� " << player.getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�." << endl;

				roundMoney += n3round - n1round;
				npc1.setMoney(npc1.getMoney() - roundMoney);
				cout << "�÷��̾�2 �� ���� �ؼ�" << n3round - n1round << " ���� �����Ͽ����ϴ�." << endl;
				cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

				roundMoney += n3round - n2round;
				npc2.setMoney(npc2.getMoney() - roundMoney);
				cout << "�÷��̾�3 �� ���� �ؼ�" << n3round - n2round << " ���� �����Ͽ����ϴ�." << endl;
				cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;


				cout << "�÷��̾�4 �� ���� �ؼ�" << 0 << " ���� �����Ͽ����ϴ�." << endl;
				cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;
				round++;
				continue;
			}
			else if (BettingType == "3") {
				cout << "[����] ������ �����մϴ�." << endl;
				player.setLose(true);
				return roundMoney;
			}

			n1 = (rand() % 401) + 100;
			n2 = (rand() % 401) + 100;
			n3 = (rand() % 401) + 100;

			raiseMoney += n1;
			roundMoney += raiseMoney;
			n1round += raiseMoney;
			npc1.setMoney(npc1.getMoney() - n1round);
			cout << "�÷��̾�2 ��" << n1 << "���� �������Ͽ��� " << raiseMoney << " �� �����Ͽ����ϴ�. ������: " <<  npc1.getMoney() <<endl;
			cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

			raiseMoney += n2;
			roundMoney += raiseMoney;
			n2round += raiseMoney;
			npc2.setMoney(npc2.getMoney() - n2round);
			cout << "�÷��̾�3 ��" << n2 << "���� �������Ͽ��� " << raiseMoney << " �� �����Ͽ����ϴ�. ������: " << npc2.getMoney() << endl;
			cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

			raiseMoney += n3;
			roundMoney += raiseMoney;
			n3round += raiseMoney;
			npc3.setMoney(npc3.getMoney() - n3round);
			cout << "�÷��̾�4 ��" << n3 << "���� �������Ͽ��� " << raiseMoney << " �� �����Ͽ����ϴ�. ������: " << npc3.getMoney() << endl;
			cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

			cout << "���ù���� �Է��ϼ���. (1.�� 2.����)" << endl;
			BettingType;
			cin >> BettingType;

			if (BettingType == "1") {
				player.setMoney(player.getMoney() - (n3round - pround));

				roundMoney += n3round - pround;
				cout << "���纸���ݾ��� " << player.getMoney() << ", �ǵ��� " << roundMoney << " �Դϴ�." << endl;

				roundMoney += n3round - n1round;
				npc1.setMoney(npc1.getMoney() - roundMoney);
				cout << "�÷��̾�2 �� ���� �ؼ�" << n3round - n1round << " ���� �����Ͽ����ϴ�." << endl;
				cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

				roundMoney += n3round - n2round;
				npc2.setMoney(npc2.getMoney() - roundMoney);
				cout << "�÷��̾�3 �� ���� �ؼ�" << n3round - n2round << " ���� �����Ͽ����ϴ�." << endl;
				cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;


				cout << "�÷��̾�4 �� ���� �ؼ�" << 0 << " ���� �����Ͽ����ϴ�." << endl;
				cout << "�ǵ��� " << roundMoney << " �Դϴ�." << endl;

			}
			else if (BettingType == "2") {
				cout << "[����] ������ �����մϴ�." << endl;
				player.setLose(true);
				return roundMoney;
			}
			round++;
		}


	}

	for (int i = 0; i < 5; i++) {
		Card* cardget = player.getCard();
		cardget[i].cardprint();
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) { //n1 test ���
		Card* cardget = npc1.getCard();
		cardget[i].cardprint();
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) { //n2 test ���
		Card* cardget = npc2.getCard();
		cardget[i].cardprint();
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) { //n3 test ���
		Card* cardget = npc3.getCard();
		cardget[i].cardprint();
	}
	std::cout << std::endl;
	return roundMoney;
}
