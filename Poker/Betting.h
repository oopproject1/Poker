#pragma once
#include <iostream>
#include <string>

class Betting {
private:
	int money; // 플레이어 보유금액 *
	bool lose; // 플레이어 승/패 상태 *
	int bettingMoney; // 베팅금액
	string bettingStart; // 베팅유무
	bool death; // 베팅하지않고 죽어있는상태

	int cardLength; // 플레이어들이 보유한 카드개수 *
	int minBetting; // 기본베팅금액 *
	int maxBetting; // 최대베팅금액 *
public:
	//임시 getter
	int getMoney(); //이후 플레이어 클래스에서 구현되면 삭제
	bool getLose(); //이후 플레이어 클래스에서 구현되면 삭제
	int getBettingMoney();
	string getBettingStart();
	bool getDeath();
	int getCardLength(); //이후 플레이어 클래스에서 구현되면 삭제
	int getMinBetting(); //이후 타클래스에서 구현되면 삭제
	int getMaxBetting(); //이후 타클래스에서 구현되면 삭제

	//임시 setter
	void setMoney(int newMoney); //이후 플레이어 클래스에서 구현되면 삭제
	void setLose(bool newLose); //이후 플레이어 클래스에서 구현되면 삭제
	void setBettingMoney(int newBettingMoney);
	void setBettingStart(string newBettingStart);
	void setDeath(bool newDeath);

	void setCardLength(int newCardLength); //이후 플레이어 클래스에서 구현되면 삭제
	void setMinBetting(int newMinBetting); //이후 타클래스에서 구현되면 삭제
	void setMoney(int newMaxBetting); //이후 타클래스에서 구현되면 삭제
	void BettingRun();
};