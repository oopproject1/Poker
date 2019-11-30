#pragma once
#include <iostream>
#include "Card.h"

class Rule {

public:


	Card card[5];
	int cardShape[5];
	int cardValue[5];
	

	void sortCard(Card card[]); // ���� ������������ ����

	int onePair(int card[]);  
	int twoPair(int card[]);  
	int triple(int card[]);  
	int straight(int card[]);
	int flush(int card[]);
	int fullHouse(int card[]);
	int fourCard(int card[]);
	int straightFlush(int cardShape[], int cardValue[]);
	int royalFlush(int cardShape[], int CardValue[]);

	int deckCombination(Card card[]); // ������ �� ������ �˷��ش�.

	std::string bestCard();//���尭�� ī�带 �˷��ش�.


};