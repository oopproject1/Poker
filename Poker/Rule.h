#pragma once
#include <iostream>
#include "Card.h"
#include <set>

class Rule {
public:
	void sortCard(int cardShape[], int cardValue[]); // 덱을 오름차순으로 정렬

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
	int priority(Card p[], Card n1[], Card n2[], Card n3[]);
	int bestCard(Card card[]);//가장강한 카드를 알려준다.

};