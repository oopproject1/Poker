#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class player {
public:
	int cardValue[5]; //카드에서 받아와야됨
	char cardShape[5]; // 카드에서 받아와야됨
	int playerMoney; //현재 플레이어의 베팅 금액

	void betting(int x) { //베팅 시스템 과 연계돼야함

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
			if (cardValue[2] - cardValue[0] == 2) //위에서 오름차순으로 정렬하고 가장 큰 값에서 작은값 뺀다
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
			if (cardValue[3] - cardValue[0] == 3 && cardValue[3] - cardValue[0] == 4) //순서대로 거나 중간에 하나 없을 경우
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
		//오픈할 카드 하나 선택
		int choiceIndex;
		while (true)
		{
			cout << "몇 번째 카드를 오픈할지 선택해 주세요(1~3)" << endl;
			cin >> choiceIndex; // 카드 선택
			if (choiceIndex > 0 && choiceIndex < 4) //1~3 사이의 숫자를 선택하면 반복문 탈출
				break;
			else
			{
				cout << "다시 선택해 주세요" << endl;
			}
		}
		cout << cardValue[choiceIndex] << endl;
		cout << cardShape[choiceIndex] << endl;

	}
	int onepair() { //룰에서 가져 와야됨

	}
	int thriple() { // 룰에서 가져와야됨

	}
	int fourcard() { //룰에서 가져와야됨

	}
	int straight() {//룰에서 가져와야됨

	}
	int flush() {//룰에서 가져와야됨

	}
	int fullhouse() {//룰에서 가져와야됨

	}
	int straightFlush() {//룰에서 가져와야됨

	}
	int royalFlush() {//룰에서 가져와야됨

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