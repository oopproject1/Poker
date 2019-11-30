#pragma once
#include <iostream>
#include "Card.h"

class Rule {

public:


	Card card[5];
	int cardShape[5];
	int cardValue[5];
	

	void sortCard(Card card[]); // 덱을 오름차순으로 정렬

	int onePair(int card[]);  
	int twoPair(int card[]);  
	int triple(int card[]);  
	int straight(int card[]);
	int flush(int card[]);
	int fullHouse(int card[]);
	int fourCard(int card[]);
	int straightFlush(int cardShape[], int cardValue[]);
	int royalFlush(int cardShape[], int CardValue[]);

	int deckCombination(Card card[]); // 가능한 덱 조합을 알려준다.

	std::string bestCard();//가장강한 카드를 알려준다.


};