#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class player {
public:
	int cardValue[5]; //ī�忡�� �޾ƿ;ߵ�
	char cardShape[5]; // ī�忡�� �޾ƿ;ߵ�
	int playerMoney; //���� �÷��̾��� ���� �ݾ�

	void betting(int x) { //���� �ý��� �� ����ž���

	}
	int checkShape(int x) {
		int i;
		int count = 0;
		if (x == 3) {
			if (cardShape[0] == cardShape[1] == cardShape[2])
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if (x == 4)
		{
			if (cardShape[0] == cardShape[1] == cardShape[2] == cardShape[3])
				return 1;
			else
			{
				return 0;
			}
		}
	}
	int checkValue(int x) {
		int swap;
		for (int i = 0; i < 4; i++) {
			if (cardValue[i] > cardValue[i + 1]) {
				swap = cardValue[i];
				cardValue[i] = cardValue[i + 1];
				cardValue[i + 1] = swap;
				i = -1;
			}
		}
		if (x == 3)
		{
			if (cardValue[2] - cardValue[0] == 2) //������ ������������ �����ϰ� ���� ū ������ ������ ����
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if (x == 4)
		{
			if (cardValue[3] - cardValue[0] == 3 && cardValue[3] - cardValue[0] == 4) //������� �ų� �߰��� �ϳ� ���� ���
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	void choiceCard() {
		//������ ī�� �ϳ� ����
		int choiceIndex;
		while (true)
		{
			cout << "�� ��° ī�带 �������� ������ �ּ���(1~3)" << endl;
			cin >> choiceIndex; // ī�� ����
			if (choiceIndex > 0 && choiceIndex < 4) //1~3 ������ ���ڸ� �����ϸ� �ݺ��� Ż��
				break;
			else
			{
				cout << "�ٽ� ������ �ּ���" << endl;
			}
		}
		cout << cardValue[choiceIndex] << endl;
		cout << cardShape[choiceIndex] << endl;

	}
	int onepair() { //�꿡�� ���� �;ߵ�

	}
	int thriple() { // �꿡�� �����;ߵ�

	}
	int fourcard() { //�꿡�� �����;ߵ�

	}
	int straight() {//�꿡�� �����;ߵ�

	}
	int flush() {//�꿡�� �����;ߵ�

	}
	int fullhouse() {//�꿡�� �����;ߵ�

	}
	int straightFlush() {//�꿡�� �����;ߵ�

	}
	int royalFlush() {//�꿡�� �����;ߵ�

	}
	void haveThreeCard() {
		choiceCard;
		if (checkValue(4) == 1)
		{

		}
		else if (checkShape(4) == 1)
		{

		}
		else if (thriple() == 1) {

		}
		else if (onepair() == 1) {

		}
		else {

		}
	}
	void haveFourCard() {
		if (fourcard() == 1)
		{

		}
		else if (checkValue(4) == 1)
		{

		}
		else if (checkShape(4) == 1)
		{

		}
		else if (thriple() == 1) {

		}
		else if (onepair() == 1) {

		}
		else {

		}

	}
	void haveFIveCard() {
		if (royalFlush() == 1)
		{

		}
		else if (straightFlush() == 1)
		{

		}
		else if (fourcard() == 1)
		{

		}
		else if (fullhouse() == 1)
		{

		}
		else if (flush() == 1)
		{

		}
		else if (straight() == 1)
		{

		}
		else if (thriple() == 1) {

		}
		else if (onepair() == 1) {

		}
		else {

		}
	}
	class firstNPC {

	};
	class secondNPC {

	};
	class thirdNPC {

	};
};