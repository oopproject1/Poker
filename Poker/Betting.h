#pragma once
#include <iostream>
#include <string>
#include "Player.h"
class Betting {
private:
	int bettingMoney; // 베팅금액
	std::string bettingStart; // 베팅유무
	bool death; // 베팅하지않고 죽어있는상태

	int cardLength; // 플레이어가 보유한 카드개수 *
	int minBetting; // 기본베팅금액 *
	int maxBetting; // 최대베팅금액 *
	int round; // 라운드횟수
	int roundMoney; // 판돈
	int raiseMoney;

	int n1; // 컴퓨터1받아올금액
	int n2; // 컴2
	int n3; // 컴3

	int pround; //지불금액변수 플1
	int n1round; //지불금액변수 컴1
	int n2round;
	int n3round;

public:
	Betting();
	int getBettingMoney();
	std::string getBettingStart();
	bool getDeath();

	void setBettingMoney(int newBettingMoney);
	void setBettingStart(std::string newBettingStart);
	void setDeath(bool newDeath);
	int BettingRun(Player* player, Player* npc1, Player* npc2, Player* npc3);
};