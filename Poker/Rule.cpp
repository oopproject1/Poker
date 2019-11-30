
#include <iostream>
#include <array>
#include "Card.h"
#include "Rule.h"


	Card card[5];
	int cardShape[5];
	int cardValue[5];
	

	// 카드 오름차순으로 정렬
	void Rule::sortCard(Card card[]) {
		int swap;

		for (int i = 0; i < 5; i++) {
			this->card[i] = card[i];
			cardShape[i] = card[i].Card::getShape();
			cardValue[i] = card[i].Card::getValue();
		}

		for (int i = 0; i < 4; i++) {
			if (cardShape[i] > cardShape[i + 1]) {
				swap = cardShape[i];
				cardShape[i] = cardShape[i + 1];
				cardShape[i + 1] = swap;
				i = -1;
			}
		}

		for (int i = 0; i < 4; i++) {
			if (cardValue[i] > cardValue[i + 1]) {
				swap = cardValue[i];
				cardValue[i] = cardValue[i + 1];
				cardValue[i + 1] = swap;
				i = -1;
			}
		}
	}








	int Rule::onePair(int card[]) {
		int count = 0;
		for (int i = 0; i < 4; i++) {
			if (card[i] == card[i + 1]) {
				count++;
				i++;
			}
		}
		if (count == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int Rule::twoPair(int card[]) {
		int count = 0;;
		for (int i = 0; i < 4; i++) {
			if (card[i] == card[i + 1]) {
				count++;
				i++;
			}
		}
		if (count == 2) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int Rule::triple(int card[]) {
		int count = 0;
		for (int i = 0; i < 4; i++) {
			if (card[i] == card[i + 1] && card[i + 1] == card[i + 2]) {
				count++;
				i = i + 2;
			}
		}
		if (count == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int Rule::straight(int card[]) {
		int count = 0;
		for (int i = 0; i < 4; i++) {
			if (card[i] + 1 == card[i + 1]) {
				count++;
			}
		}
		if (count == 4) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int Rule::flush(int card[]) {
		int count = 0;
		for (int i = 0; i < 4; i++) {
			if (card[i] == card[i + 1]) {
				count++;
			}
		}
		if (count == 4) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int Rule::fullHouse(int card[]) {
		int tripleCount = 0;
		int pairCount = 0;
		for (int i = 0; i < 4; i++) {
			if (card[i] == card[i + 1]) {
				if (card[i + 1] == card[i + 2]) {
					i = i + 2;
					tripleCount++;
				}
				else {
					i++;
					pairCount++;
				}
			}
			if (tripleCount == 1 && pairCount == 1) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	int Rule::fourCard(int card[]) {
		int count = 0;
		for (int i = 0; i < 2; i++) {
			if (card[i] == card[i + 1] && card[i + 1] == card[i + 2] && card[i + 2] == card[i + 3]) {
				count++;
			}
		}
		if (count == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int Rule::straightFlush(int cardShape[], int cardValue[]) {
		int count = 0;
		count = count + straight(cardValue); // 매개변수로 card 덱 받아야함
		count = count + flush(cardShape);  // 매개변수로 card 덱 받아야함
		if (count == 2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int Rule::royalFlush(int cardShape[], int CardValue[]) {
		int count = 0;
		int aceCount = 0;
		int tenCount = 0;
		int jackCount = 0;
		int queenCount = 0;
		int kingCount = 0;
		for (int i = 0; i < 5; i++)
		{
			if (cardValue[i] == 1)
				aceCount++;
			else if (cardValue[i] == 10)
				tenCount++;
			else if (cardValue[i] == 11)
				jackCount++;
			else if (cardValue[i] == 12)
				queenCount++;
			else if (cardValue[i] == 13)
				kingCount++;
		}
		count = count + flush(cardShape); // 매개변수로 card 덱 받아야함
		if (aceCount == 1 && tenCount == 1 && jackCount == 1 && queenCount == 1 && kingCount == 1 && count == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}







	// 자신의 카드 덱중 가능한 조합
	int Rule::deckCombination(Card card[]) {

		int count = 0;
		Rule::sortCard(card); // 카드정렬

		if (royalFlush(cardShape, cardValue) == 1) {
			std::cout << "royalFlush 가능 " << std::endl;
			return 10;
		}
		else if (straightFlush(cardShape, cardValue) == 1) {
			std::cout << "straightFlush 가능 " << std::endl;
			return 9;
		}
		else if (fourCard(cardValue) == 1) {
			std::cout << "fourCard " << std::endl;
			return 8;
		}
		else if (fullHouse(cardValue) == 1) {
			std::cout << "fullHouse 가능 " << std::endl;
			return 7;
		}
		else if (flush(cardShape) == 1) {
			std::cout << "flush 가능 " << std::endl;
			return 6;
		}
		else if (straight(cardValue) == 1) {
			std::cout << "straight 가능 " << std::endl;
			return 5;
		}
		else if (triple(cardValue) == 1) {
			std::cout << "triple 가능 " << std::endl;
			return 4;
		}
		else if (twoPair(cardValue) == 1) {
			std::cout << "twoPair 가능 " << std::endl;
			return 3;
		}
		else if (onePair(cardValue) == 1) {
			std::cout << "onePair 가능 " << std::endl;
			return 2;
		}
		else {
			std::cout << Rule::bestCard() << " top " << std::endl;
			return 1;
		}
	}





	//가장 높은 카드를 알려준다.
	std::string Rule::bestCard() {
		int max = 0;

		for (int i = 0; i < 5; i++) {

			if (cardValue[i] == 1) {

				return "A";
			}
			if (max < cardValue[i]) {
				max = cardValue[i];
			}
		}
		if (max == 11) {
			return "J";
		}
		if (max == 12) {
			return "Q";
		}
		if (max == 13) {
			return "K";
		}
		std::string max_ = std::to_string(max);
		return max_;
	}

	

