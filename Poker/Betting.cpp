#include <iostream>
#include <string>
using namespace std;

public class Betting {

//임의로 값을 넣은 예시변수, *표시변수들은 외부에서 받아와야할 변수들이다.
private:
	int money; // 플레이어 보유금액 *
	bool lose; // 플레이어 승/패 상태 *
	int bettingMoney; // 베팅금액
	char bettingStart; // 베팅유무
	bool death; // 베팅하지않고 죽어있는상태

	int cardLength = 3; // 플레이어들이 보유한 카드개수 *
	int minBetting = 100; // 기본베팅금액 *
	int maxBetting = 10000; // 최대베팅금액 *

public:
	//임시 getter
	int getMoney() { return this.money; }
	bool getLose() { return this.lose; }
	int getBettingMoney() { return this.bettingMoney; }
	char getBettingStart() { return this.bettingStart; }
	bool getDeath() { return this.death; }

	int getCardLength() { return this.cardLength; }
	int getMinBetting() { return this.minBetting; }
	int getMaxBetting() { return this.maxBetting; }

	//임시 setter
	void setMoney(int newMoney) { this.money = newMoney; }
	void setLose(bool newLose) { this.lose = newLose; }
	void setBettingMoney(int newBettingMoney) { this.bettingMoney = newBettingMoney; }
	void setBettingStart(char newBettingStart) { this.bettingStart = newBettingStart; }
	void setDeath(bool newDeath) { this.death = newDeath; }

	void setCardLength(int newCardLength) { this.cardLength = newCardLength; }
	void setMinBetting(int newMinBetting) { this.minBetting = newMinBetting; }
	void setMoney(int newMaxBetting) { this.maxBetting = newMaxBetting; }

	//각 플레이어 생성자
	Betting(int getMoney, bool getLose) {
		money = getMoney;
		lose = getLose;
		bettingMoney = 0;
		bettingStart = "Y";
		death = false;
	}

	//베팅시작메소드
	public BettingRun() {
		if (this.getLose() == true) {
			cout << "당신은 이미 패배한 상태입니다." << endl;
			return;
		}
		else if (this.getMoney() < getMinBetting()) {
			setLose(true);
			cout << "최소베팅금액을 충족하지 못하여 패배하였습니다." << endl;
			return;
		}
		else if (this.getLose() == false) {
			this.setMoney(this.getMoney() - getMinBetting());
			cout << "기본베팅금액 " << getMinBetting() << "을 지불했습니다." << endl;
			cout << "베팅을 하시겠습니까? ( Y or N )"<< std::endl;
			cin >> char BStemp >> endl;
			this.setBettingStart(BStemp);
			if (this.getBettingStart() == "Y") {
				cout << "베팅할 금액을 입력하세요. 최대베팅금액은 " << getMaxBetting() << " 입니다" << endl;
				cin >> int tempBM >> std::endl;
				this.setBettingMoney(tempBM);
				if (this.getBettingMoney() > getMaxBetting()) {
					cout << "최대베팅금액을 초과하였습니다." << endl;
				}
				else if (this.getBettingMoney() > this.getMoney()) {
					cout << "보유금액을 초과하였습니다." << endl;
				}
				else {
					this.setMoney(this.getMoney() - this.getBettingMoney());
					cout << this.getBettingMoney() << "원을 베팅하였습니다." << endl;
				}
			}
			else if (this.getBettingStart() == "N") {
				cout << "죽었습니다." << endl;
				this.setDeath(true);
			}
		}
		if (getCardLength() == 5) {
			cout << "게임이 종료되었습니다. 게임의 승자와 플레이어들의 남은 금액은 다음과 같습니다" << endl;
			//이후 게임규칙클래스를 참조하여 코드추가
		}
		else if (getCardLength() < 5) {
			cout << "해당 턴이 종료되었습니다. 해당 턴의 승자와 베팅금액은 다음과 같습니다." << endl;
			//이후 게임규칙클래스를 참조하여 코드추가
			
			cout << "새로운 카드1장을 받았습니다: " << "newcard" << endl;;
		}
	}
}
