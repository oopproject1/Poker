#include <iostream>
#include <string>
#include "Rule.h"
#include "Card.h"
#include "Player.h"
using namespace std;

class Betting {

	//임의로 값을 넣은 예시변수, *표시변수들은 외부에서 받아와야할 변수들이다.
private:
	int money; // 플레이어 보유금액 *
	bool lose; // 플레이어 승/패 상태 *
	int card[]; //플레이어 보유카드 *
	int bettingMoney; // 베팅금액
	string bettingStart; // 베팅유무
	bool death; // 베팅하지않고 죽어있는상태

	int cardLength; // 플레이어가 보유한 카드개수 *
	int minBetting; // 기본베팅금액 *
	int maxBetting; // 최대베팅금액 *

public:
	//임시 getter
	int getMoney() { return this->money; } //이후 플레이어 클래스에서 구현되면 삭제
	bool getLose() { return this->lose; } //이후 플레이어 클래스에서 구현되면 삭제
	int getBettingMoney() { return this->bettingMoney; }
	string getBettingStart() { return this->bettingStart; }
	bool getDeath() { return this->death; }
	
	int getCardLength() { return this->cardLength; } //이후 플레이어 클래스에서 구현되면 삭제
	int getMinBetting() { return this->minBetting; } //이후 타클래스에서 구현되면 삭제
	int getMaxBetting() { return this->maxBetting; } //이후 타클래스에서 구현되면 삭제

	//임시 setter
	void setMoney(int newMoney) { this->money = newMoney; } //이후 플레이어 클래스에서 구현되면 삭제
	void setLose(bool newLose) { this->lose = newLose; } //이후 플레이어 클래스에서 구현되면 삭제
	void setBettingMoney(int newBettingMoney) { this->bettingMoney = newBettingMoney; }
	void setBettingStart(string newBettingStart) { this->bettingStart = newBettingStart; }
	void setDeath(bool newDeath) { this->death = newDeath; }

	void setCardLength(int newCardLength) { this->cardLength = newCardLength; } //이후 플레이어 클래스에서 구현되면 삭제
	void setMinBetting(int newMinBetting) { this->minBetting = newMinBetting; } //이후 타클래스에서 구현되면 삭제
	void setMoney(int newMaxBetting) { this->maxBetting = newMaxBetting; } //이후 타클래스에서 구현되면 삭제

	//Betting(int getMoney, bool getLose) {
	//	money = getMoney;
	//	lose = getLose;
	//	bettingMoney = 0;
	//	bettingStart = "Y";
	//	death = false;
	//}

	//베팅시작메소드
	void BettingRun() {
		if (this->getLose() == true) {
			cout << "당신은 이미 패배한 상태입니다." << endl;
			return;
		}
		else if (this->getMoney() < getMinBetting()) {
			setLose(true);
			cout << "최소베팅금액을 충족하지 못하여 패배하였습니다." << endl;
			return;
		}
		else if (this->getLose() == false) {
			this->setMoney(this->getMoney() - getMinBetting());
			cout << "기본베팅금액 " << getMinBetting() << "을 지불했습니다." << endl;
			cout << "베팅을 하시겠습니까? ( Y or N )" << endl;
			string BStemp;
			cin >> BStemp;
			this->setBettingStart(BStemp);
			if (this->getBettingStart() == "Y") {
				cout << "베팅할 금액을 입력하세요. 최대베팅금액은 " << getMaxBetting() << " 입니다" << endl;
				int tempBM;
				cin >> tempBM;
				this->setBettingMoney(tempBM);
				if (this->getBettingMoney() > getMaxBetting()) {
					cout << "최대베팅금액을 초과하였습니다." << endl;
				}
				else if (this->getBettingMoney() > this->getMoney()) {
					cout << "보유금액을 초과하였습니다." << endl;
				}
				else {
					this->setMoney(this->getMoney() - this->getBettingMoney());
					cout << this->getBettingMoney() << "원을 베팅하였습니다." << endl;
				}
			}
			else if (this->getBettingStart() == "N") {
				cout << "죽었습니다." << endl;
				this->setDeath(true);
			}
		}
		if (getCardLength() == 5) {
			cout << "게임이 종료되었습니다. 게임의 승자와 플레이어들의 남은 금액은 다음과 같습니다" << endl;
			//구현중
			
			
		}
		else if (getCardLength() < 5) {
			cout << "해당 턴이 종료되었습니다. 해당 턴의 승자와 베팅금액은 다음과 같습니다." << endl;
			//Card p[] = getCard_p();  //이후 플레이어 클래스가 완성되면 활성화 //플레이어와 컴퓨터가 가진 카드를 가져온다.
			//Card n1[] = getCard_n1();
			//Card n2[] = getCard_n2();
			//Card n3[] = getCard_n3();
			priority(p[], n1[], n2[], n3[]); //규칙클래스에서 승자와 플레이어들의 카드 출력
			//이후 승리한 플레이어의 보유금액에 나머지 인원의 베팅금액을 추가

			cout << "새로운 카드1장을 받았습니다: " << "newcard" << endl;;
		}
	}
}
