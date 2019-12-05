#pragma once
#include <iostream>
#include <string>
#include "Player.h"
class Betting {
private:
	int bettingMoney; // ���ñݾ�
	std::string bettingStart; // ��������
	bool death; // ���������ʰ� �׾��ִ»���

	int cardLength; // �÷��̾ ������ ī�尳�� *
	int minBetting; // �⺻���ñݾ� *
	int maxBetting; // �ִ뺣�ñݾ� *
	int round; // ����Ƚ��
	int roundMoney; // �ǵ�
	int raiseMoney;

	int n1; // ��ǻ��1�޾ƿñݾ�
	int n2; // ��2
	int n3; // ��3

	int pround; //���ұݾ׺��� ��1
	int n1round; //���ұݾ׺��� ��1
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