#pragma once
#include<iostream>
#include <string>

class player {
private:
	int playerCash; // �÷��̾ ���� �����ݾ�
	int playerBetting; // �÷��̾ ������ �ݾ�
	std::string playerCard; // �÷��̾ ���� ������ �ִ� ī��
	std::string playerIsWin;// �÷��̾ �¸��ߴ��� �й��ߴ��� Ȯ��

public:
	int setPlayerBetting(); // �÷��̾ ������ �ݾ׸�ŭ �����ݾ׿��� �����Ѵ�.
	void choiceCard(); // �÷��̾ ������ ī���� ������ ī�� 3���� �����Ѵ�.
	void playerMenu(); //�÷��̾ ���� �� �ൿ�� �����Ѵ�.
};
