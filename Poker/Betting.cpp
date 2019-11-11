#include <iostream>
#include <string>
using namespace std;

public class Betting {

//���Ƿ� ���� ���� ���ú���, *ǥ�ú������� �ܺο��� �޾ƿ;��� �������̴�.
private:
	int money; // �÷��̾� �����ݾ� *
	bool lose; // �÷��̾� ��/�� ���� *
	int bettingMoney; // ���ñݾ�
	char bettingStart; // ��������
	bool death; // ���������ʰ� �׾��ִ»���

	int cardLength = 3; // �÷��̾���� ������ ī�尳�� *
	int minBetting = 100; // �⺻���ñݾ� *
	int maxBetting = 10000; // �ִ뺣�ñݾ� *

public:
	//�ӽ� getter
	int getMoney() { return this.money; }
	bool getLose() { return this.lose; }
	int getBettingMoney() { return this.bettingMoney; }
	char getBettingStart() { return this.bettingStart; }
	bool getDeath() { return this.death; }

	int getCardLength() { return this.cardLength; }
	int getMinBetting() { return this.minBetting; }
	int getMaxBetting() { return this.maxBetting; }

	//�ӽ� setter
	void setMoney(int newMoney) { this.money = newMoney; }
	void setLose(bool newLose) { this.lose = newLose; }
	void setBettingMoney(int newBettingMoney) { this.bettingMoney = newBettingMoney; }
	void setBettingStart(char newBettingStart) { this.bettingStart = newBettingStart; }
	void setDeath(bool newDeath) { this.death = newDeath; }

	void setCardLength(int newCardLength) { this.cardLength = newCardLength; }
	void setMinBetting(int newMinBetting) { this.minBetting = newMinBetting; }
	void setMoney(int newMaxBetting) { this.maxBetting = newMaxBetting; }

	//�� �÷��̾� ������
	Betting(int getMoney, bool getLose) {
		money = getMoney;
		lose = getLose;
		bettingMoney = 0;
		bettingStart = "Y";
		death = false;
	}

	//���ý��۸޼ҵ�
	public BettingRun() {
		if (this.getLose() == true) {
			cout << "����� �̹� �й��� �����Դϴ�." << endl;
			return;
		}
		else if (this.getMoney() < getMinBetting()) {
			setLose(true);
			cout << "�ּҺ��ñݾ��� �������� ���Ͽ� �й��Ͽ����ϴ�." << endl;
			return;
		}
		else if (this.getLose() == false) {
			this.setMoney(this.getMoney() - getMinBetting());
			cout << "�⺻���ñݾ� " << getMinBetting() << "�� �����߽��ϴ�." << endl;
			cout << "������ �Ͻðڽ��ϱ�? ( Y or N )"<< std::endl;
			cin >> char BStemp >> endl;
			this.setBettingStart(BStemp);
			if (this.getBettingStart() == "Y") {
				cout << "������ �ݾ��� �Է��ϼ���. �ִ뺣�ñݾ��� " << getMaxBetting() << " �Դϴ�" << endl;
				cin >> int tempBM >> std::endl;
				this.setBettingMoney(tempBM);
				if (this.getBettingMoney() > getMaxBetting()) {
					cout << "�ִ뺣�ñݾ��� �ʰ��Ͽ����ϴ�." << endl;
				}
				else if (this.getBettingMoney() > this.getMoney()) {
					cout << "�����ݾ��� �ʰ��Ͽ����ϴ�." << endl;
				}
				else {
					this.setMoney(this.getMoney() - this.getBettingMoney());
					cout << this.getBettingMoney() << "���� �����Ͽ����ϴ�." << endl;
				}
			}
			else if (this.getBettingStart() == "N") {
				cout << "�׾����ϴ�." << endl;
				this.setDeath(true);
			}
		}
		if (getCardLength() == 5) {
			cout << "������ ����Ǿ����ϴ�. ������ ���ڿ� �÷��̾���� ���� �ݾ��� ������ �����ϴ�" << endl;
			//���� ���ӱ�ĢŬ������ �����Ͽ� �ڵ��߰�
		}
		else if (getCardLength() < 5) {
			cout << "�ش� ���� ����Ǿ����ϴ�. �ش� ���� ���ڿ� ���ñݾ��� ������ �����ϴ�." << endl;
			//���� ���ӱ�ĢŬ������ �����Ͽ� �ڵ��߰�
			
			cout << "���ο� ī��1���� �޾ҽ��ϴ�: " << "newcard" << endl;;
		}
	}
};