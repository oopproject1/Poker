#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Card.h"

Card::Card() {
	shape = "\0";
	value = "\0";
	shape_ = -1;
	value_ = -1;
}

void Card::cardDrow() {
	srand((unsigned int)time(NULL));
	int x = rand() % remain;
	shape_ = remainCard[x] / 13;
	value_ = (remainCard[x] % 13) + 1;
	if (shape_ == 0) {
		shape = "��";
	}
	else if (shape_ == 1) {
		shape = "��";
	}
	else if (shape_ == 2) {
		shape = "��";
	}
	else {
		shape = "��";
	}
	if (value_ == 1) {
		value = "A";
	}
	else if (value_ == 11) {
		value = "J";
	}
	else if (value_ == 12) {
		value = "Q";
	}
	else if (value_ == 13) {
		value = "K";
	}
	else {
		value = std::to_string(value_);
	}
	remainCard[x] = remainCard[--remain];
}
/*
void Card::cardDrow(int code) {
	int x = code;
	shape_ = remainCard[x] / 13;
	value_ = (remainCard[x] % 13) + 1;
	if (shape_ == 0) {
		shape = "��";
	}
	else if (shape_ == 1) {
		shape = "��";
	}
	else if (shape_ == 2) {
		shape = "��";
	}
	else {
		shape = "��";
	}
	if (value_ == 1) {
		value = "A";
	}
	else if (value_ == 11) {
		value = "J";
	}
	else if (value_ == 12) {
		value = "Q";
	}
	else if (value_ == 13) {
		value = "K";
	}
	else {
		value = std::to_string(value_);
	}
}*/

void Card::cardprint() {//ī�� ����Ʈ
	std::cout << shape << ", " << value << std::endl;
}
int Card::getShape() {//��� �ޱ�
	return shape_;
}
int Card::getValue() {//���� �ޱ�
	return value_;
}
void Card::shuffle() {//ī�� �ٽ� ����. ���߿� ���� Ŭ������ �Űܾ� ��
	remain = 52;
	for (int i = 0; i < 52; i++) {
		remainCard[i] = i;
	}
}
int Card::remain = 52;
int Card::remainCard[52] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51 };
