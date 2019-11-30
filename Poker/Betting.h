#pragma once
#include <iostream>
#include <string>

class Betting {
private:
	int money; // �÷��̾� �����ݾ� *
	bool lose; // �÷��̾� ��/�� ���� *
	int bettingMoney; // ���ñݾ�
	string bettingStart; // ��������
	bool death; // ���������ʰ� �׾��ִ»���

	int cardLength; // �÷��̾���� ������ ī�尳�� *
	int minBetting; // �⺻���ñݾ� *
	int maxBetting; // �ִ뺣�ñݾ� *
public:
	//�ӽ� getter
	int getMoney(); //���� �÷��̾� Ŭ�������� �����Ǹ� ����
	bool getLose(); //���� �÷��̾� Ŭ�������� �����Ǹ� ����
	int getBettingMoney();
	string getBettingStart();
	bool getDeath();
	int getCardLength(); //���� �÷��̾� Ŭ�������� �����Ǹ� ����
	int getMinBetting(); //���� ŸŬ�������� �����Ǹ� ����
	int getMaxBetting(); //���� ŸŬ�������� �����Ǹ� ����

	//�ӽ� setter
	void setMoney(int newMoney); //���� �÷��̾� Ŭ�������� �����Ǹ� ����
	void setLose(bool newLose); //���� �÷��̾� Ŭ�������� �����Ǹ� ����
	void setBettingMoney(int newBettingMoney);
	void setBettingStart(string newBettingStart);
	void setDeath(bool newDeath);

	void setCardLength(int newCardLength); //���� �÷��̾� Ŭ�������� �����Ǹ� ����
	void setMinBetting(int newMinBetting); //���� ŸŬ�������� �����Ǹ� ����
	void setMoney(int newMaxBetting); //���� ŸŬ�������� �����Ǹ� ����
	void BettingRun();
};