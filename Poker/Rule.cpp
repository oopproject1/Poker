#include <iostream>
#include <array>

class Rule {
	int compareD[];


	// 카드 오름차순으로 정렬
	void sortCard(int* card[]) {
		int swap;
		for (int i = 0; i < 4; i++) {
			if (card[i] > card[i + 1]) {
				swap = card[i];
				card[i] = card[i + 1];
				card[i + 1] = swap;
				i = 0;
			}
		}
	}








	int onePair(int card[]) {
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
	int twoPair(int card[]) {
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

	int triple(int card[]) {
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
	int straight(int card[]) {
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
	int flush(char card[]) {
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
	int fullHouse(int card[]) {
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
	int fourCard(int card[]) {
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
	int straightFlush(int card[]) {
		int count = 0;
		count = count + straight(card); // 매개변수로 card 덱 받아야함
		count = count + flush(card);  // 매개변수로 card 덱 받아야함
		if (count == 2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int royalFlush(int card[]) {
		int count = 0;
		int aceCount = 0;
		int tenCount = 0;
		int jackCount = 0;
		int queenCount = 0;
		int kingCount = 0;
		for (int i = 0; i < 5; i++)
		{
			if (card[i] == 1)
				aceCount++;
			else if (card[i + 1] == 10)
				tenCount++;
			else if (card[i + 2] == 11)
				jackCount++;
			else if (card[i + 3] == 12)
				queenCount++;
			else if (card[i + 4] == 13)
				kingCount++;
		}
		count = count + flush(card); // 매개변수로 card 덱 받아야함
		if (aceCount == 1 && tenCount == 1 && jackCount == 1 && queenCount == 1 && kingCount == 1 && count == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}







	// 자신의 카드 덱중 가능한 조합
	int deckCombination(int card[]) {
		int count = 0;
		sortCard(card); // 카드정렬
		if (royalFlush(card) == 1) {
			std::cout << "royalFlush 가능 " << std::endl;
			return 10;
		}
		else if (straightFlush(card) == 1) {
			std::cout << "straightFlush 가능 " << std::endl;
			return 9;
		}
		else if (fourCard(card) == 1) {
			std::cout << "fourCard " << std::endl;
			return 8;
		}
		else if (fullHouse(card) == 1) {
			std::cout << "fullHouse 가능 " << std::endl;
			return 7;
		}
		else if (flush(card) == 1) {
			std::cout << "flush 가능 " << std::endl;
			return 6;
		}
		else if (straight(card) == 1) {
			std::cout << "straight 가능 " << std::endl;
			return 5;
		}
		else if (triple(card) == 1) {
			std::cout << "triple 가능 " << std::endl;
			return 4;
		}
		else if (twoPair(card) == 1) {
			std::cout << "twoPair 가능 " << std::endl;
			return 3;
		}
		else if (onePair(card) == 1) {
			std::cout << "onePair 가능 " << std::endl;
			return 2;
		}
		else {
			std::cout << "조합 불가능 " << std::endl;
			return 1;
		}
	}





	//가장 높은 카드를 알려준다.
	int bestCard() {
		int max=0;
		for (int i = 0; i < card.size(); i++) {
			if (card[i] == 1) {
				return 1;
			}
			if (max < card[i]) {
				max = card[i];
			}
		}
		return max;
	}

	//카드의 숫자를 비교한다.
	void compareNumber(){
		
	}

	//카드의 문양을 비교한다.
	void compare(){

}







// n명중 승패를 정해준다
	void priority() {
		int max=0;
		int count=0;
	for (int i = 0; i < player.size(); i++) {
		combination_value[i] = deckCombination(player[i].card);//객체마다 combination 값을 반환해줌
	}
	for (int i = 0; i < player.size(); i++) {//가장 높은 반환 값을 구해준다.
		if (max < combination_value[i]) {
			max = combination_value[i];
		}
	}
	for (int i = 0; i < player.size(); i++) {
		if (max == combination_value[i]) {
			compareD[] = //겹칠떄마다 배열추가
			
		}
	}
	if (compareD[0] == 1) { //모두 단일카드일때 숫자 , 모양 높은 순으로 승

	}
	else if (compareD[] != 1 && compareD.size >= 2) {// 원페어 ~ 스트레이트 플러쉬일때, 조합이 2명이상 같을때,
		
	}
	else { // 원페어 ~ 스트레이트 플러쉬일때, 조합이 겹치는 사람이 없을때
	}
}

};