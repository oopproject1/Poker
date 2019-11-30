
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
		if(card[0] == 1 && card[1] == 10 && card[2] == 11 && card[3] == 12 && card[4] == 13){//10 J Q K A
			return 1;
		}
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

	
//////////////////// 작성 해야함

// 
void compareValue(Player p1,Player n1,Player n2,Player n3) {
	int a = 
	int max = 0;
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (max < number_Array[i]) {
			max = number_Array[i];
		}
		for (int i = 0; i < 4; i++) {
			if (max == number_Array[i]) {
				count++;
			}
			if (count == 0) {
				// max값에 해당하는 사람이이김
			}
			else {
				// max 값 중복 된느사람모양비교
			}
		}
	}

}

// 문양을 비교한다.
void compareShape(){

}





//승패를 결정한다
void priority(const int player, const int npc_1, const int npc_2, const int npc_3) {

	int player_array[4] = { player, npc_1, npc_2, npc_3 };
	int max = 0;
	int count = -1;
	for (int i = 0; i < 4; i++) {//가장 높은 반환 deckCombination을 구한다.
		if (max < player_array[i]) {
			max = player_array[i];
		}
	}
	for (int i = 0; i < 4; i++) {//가장 높은 반환 deckCombination이 겹칠 때마다 count 추가
		if (max == player_array[i]) {
			count++;
		}
	}
	if (max == 1) { //모두 단일카드일때 숫자 , 모양 높은 순으로 승

	}
	else if (count >= 1) {// 원페어 ~ 스트레이트 플러쉬일때, 조합이 2명이상 같을때,
	}
	else { // 원페어 ~ 스트레이트 플러쉬일때, 조합이 겹치는 사람이 없을때
	}
} 
