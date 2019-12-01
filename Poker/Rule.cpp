#include <iostream>
#include <array>
#include <set>
#include "Card.h"
#include "Rule.h"


// 카드 오름차순으로 정렬
void Rule::sortCard(int cardShape[], int cardValue[]) {
	int swap;

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
	if (card[0] == 1 && card[1] == 10 && card[2] == 11 && card[3] == 12 && card[4] == 13) {//10 J Q K A
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
int Rule::royalFlush(int cardShape[], int cardValue[]) {
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

	int cardShape[5];
	int cardValue[5];
	for (int i = 0; i < 5; i++) {
		cardShape[i] = card[i].getShape();
		cardValue[i] = card[i].getValue();
	}
	int count = 0;

	sortCard(cardShape, cardValue); // 카드정렬

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
		if (Rule::bestCard(card) == 14) {
			std::cout << "A top " << std::endl;
		}
		else if (Rule::bestCard(card) == 11) {
			std::cout << "J top " << std::endl;
		}
		else if (Rule::bestCard(card) == 12) {
			std::cout << "Q top " << std::endl;
		}
		else if (Rule::bestCard(card) == 13) {
			std::cout << "K top " << std::endl;
		}
		else {
			std::cout << Rule::bestCard(card) << " top " << std::endl;
		}

		return 1;
	}
}





//가장 높은 카드를 알려준다.
int Rule::bestCard(Card card[]) {
	int max = 0;
	int max_ = 0;

	for (int i = 0; i < 5; i++) {

		if (card[i].getValue() == 1) {

			return 14;
		}
		if (max < card[i].getValue()) {
			max = card[i].getValue();
			max_ = i;
		}
	}
	return max;

}


//////////////////// 작성 해야함







// 문양을 비교한다.





//승패를 결정한다

int Rule::priority(Card p[], Card n1[], Card n2[], Card n3[]) {

	int score[4];
	score[0] = Rule::deckCombination(p);
	score[1] = Rule::deckCombination(n1);
	score[2] = Rule::deckCombination(n2);
	score[3] = Rule::deckCombination(n3);

	int max = 0;
	int count = -1;
	std::set<int> maxDeck;


	for (int i = 0; i < 4; i++) {//가장 높은 반환 deckCombination을 구한다.
		if (max < score[i]) {
			max = score[i];
		}
	}
	for (int i = 0; i < 4; i++) {//가장 높은 반환 deckCombination이 겹칠 때마다 count 추가
		if (max == score[i]) {
			count++;
			maxDeck.insert(i);
			
		}
	}
	if (count == 0) { //승패가 명확할 때
		auto it = maxDeck.begin();
		int a = (*it) + 1;
		std::cout << "player" << a << "win" << std::endl;
		maxDeck.clear();
		return a;
	}
	else if (count != 0 && max == 1) {//top 일때
		int max_ = -1;
		int max__ = 0;
		int count_ = 0;
		for (int i = 0; i < 4; i++) {
			score[i] = 0;
		}
		for (int i = 0; i < 5; i++) {
			if (p[i].getValue() == 1)
				score[0] = 14;
			if (p[i].getValue() > score[0]) {
				score[0] = p[i].getValue();
			}
		}
		for (int i = 0; i < 5; i++) {
			if (n1[i].getValue() == 1)
				score[1] = 14;
			if (n1[i].getValue() > score[1]) {
				score[1] = n1[i].getValue();
			}
		}
		for (int i = 0; i < 5; i++) {
			if (n2[i].getValue() == 1)
				score[2] = 14;
			if (n2[i].getValue() > score[2]) {
				score[2] = n2[i].getValue();
			}
		}
		for (int i = 0; i < 5; i++) {
			if (n3[i].getValue() == 1)
				score[3] = 14;
			if (n3[i].getValue() > score[3]) {
				score[3] = n3[i].getValue();
			}
		}
		for (int i = 0; i < 4; i++) {
			if (max_ < score[i]) {
				count_ = 1;
				max_ = score[i];
				max__ = i;
			}
			else if (max_ == score[i]) {
				count_++;
			}
		}
		if (count_ == 1) {
			std::cout << "player" << max__ + 1 << "win" << std::endl;
			return max__ + 1;
		}
		else {
			return 0;
		}

	}
	else if(count != 0 && max == 2){//onepair

		for (int i = 0; i < 4; i++) {
			score[i] = -1;
		}
		for (auto it = maxDeck.begin(); it != maxDeck.end(); it++) {
			if (*it == 0) {
				int cardShape[5];
				int cardValue[5];
				for (int i = 0; i < 5; i++) {
					cardShape[i] = p[i].getShape();
					cardValue[i] = p[i].getValue();
				}

				sortCard(cardShape, cardValue);
				for (int i = 0; i < 4; i++) {
					if (cardValue[i] == cardValue[i+1]) {
						if (cardValue[i] == 1) {
							score[*it] = 14;
						}
						else {
							score[*it] = cardValue[i];
						}
						break;
					}
				}
			}
			else if (*it == 1) {
				int cardShape[5];
				int cardValue[5];
				for (int i = 0; i < 5; i++) {
					cardShape[i] = n1[i].getShape();
					cardValue[i] = n1[i].getValue();
				}

				sortCard(cardShape, cardValue);
				for (int i = 0; i < 4; i++) {
					if (cardValue[i] == cardValue[i + 1]) {
						if (cardValue[i] == 1) {
							score[*it] = 14;
						}
						else {
							score[*it] = cardValue[i];
						}
						break;
					}
				}
			}
			else if (*it == 2) {
				int cardShape[5];
				int cardValue[5];
				for (int i = 0; i < 5; i++) {
					cardShape[i] = n2[i].getShape();
					cardValue[i] = n2[i].getValue();
				}
				sortCard(cardShape, cardValue);
				for (int i = 0; i < 4; i++) {
					if (cardValue[i] == cardValue[i + 1]) {
						if (cardValue[i] == 1) {
							score[*it] = 14;
						}
						else {
							score[*it] = cardValue[i];
						}
						break;
					}
				}
			}
			else if (*it == 3) {
				int cardShape[5];
				int cardValue[5];
				for (int i = 0; i < 5; i++) {
					cardShape[i] = n3[i].getShape();
					cardValue[i] = n3[i].getValue();
				}
				sortCard(cardShape, cardValue);
				for (int i = 0; i < 4; i++) {
					if (cardValue[i] == cardValue[i + 1]) {
						if (cardValue[i] == 1) {
							score[*it] = 14;
						}
						else {
							score[*it] = cardValue[i];
						}
						break;
					}
				}
			}
		}
		int count_ = 0;
		int max__ = score[0];
		int max_ = 0;
		for (int i = 1; i < 4; i++) {
			if (max__ < score[i]) {
				max__ = score[i];
				max_ = i;
				count_ = 1;
			}
			else if (max__ == score[i]) {
				count_++;
			}
		}
		if (count_ == 1) {
			std::cout << "player" << max_ + 1 << "win" << std::endl;
			maxDeck.clear();
			return max_ + 1;
		}
		else {
			maxDeck.clear();
			return 0; }
	}
	maxDeck.clear();
	return 0;
}

