#include <iostream>
#include <array>

class Rule {
	int compareD[];


	// ī�� ������������ ����
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
		count = count + straight(card); // �Ű������� card �� �޾ƾ���
		count = count + flush(card);  // �Ű������� card �� �޾ƾ���
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
		count = count + flush(card); // �Ű������� card �� �޾ƾ���
		if (aceCount == 1 && tenCount == 1 && jackCount == 1 && queenCount == 1 && kingCount == 1 && count == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}







	// �ڽ��� ī�� ���� ������ ����
	int deckCombination(int card[]) {
		int count = 0;
		sortCard(card); // ī������
		if (royalFlush(card) == 1) {
			std::cout << "royalFlush ���� " << std::endl;
			return 10;
		}
		else if (straightFlush(card) == 1) {
			std::cout << "straightFlush ���� " << std::endl;
			return 9;
		}
		else if (fourCard(card) == 1) {
			std::cout << "fourCard " << std::endl;
			return 8;
		}
		else if (fullHouse(card) == 1) {
			std::cout << "fullHouse ���� " << std::endl;
			return 7;
		}
		else if (flush(card) == 1) {
			std::cout << "flush ���� " << std::endl;
			return 6;
		}
		else if (straight(card) == 1) {
			std::cout << "straight ���� " << std::endl;
			return 5;
		}
		else if (triple(card) == 1) {
			std::cout << "triple ���� " << std::endl;
			return 4;
		}
		else if (twoPair(card) == 1) {
			std::cout << "twoPair ���� " << std::endl;
			return 3;
		}
		else if (onePair(card) == 1) {
			std::cout << "onePair ���� " << std::endl;
			return 2;
		}
		else {
			std::cout << "���� �Ұ��� " << std::endl;
			return 1;
		}
	}





	//���� ���� ī�带 �˷��ش�.
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

	//ī���� ���ڸ� ���Ѵ�.
	void compareNumber(){
		
	}

	//ī���� ������ ���Ѵ�.
	void compare(){

}







// n���� ���и� �����ش�
	void priority() {
		int max=0;
		int count=0;
	for (int i = 0; i < player.size(); i++) {
		combination_value[i] = deckCombination(player[i].card);//��ü���� combination ���� ��ȯ����
	}
	for (int i = 0; i < player.size(); i++) {//���� ���� ��ȯ ���� �����ش�.
		if (max < combination_value[i]) {
			max = combination_value[i];
		}
	}
	for (int i = 0; i < player.size(); i++) {
		if (max == combination_value[i]) {
			compareD[] = //��ĥ������ �迭�߰�
			
		}
	}
	if (compareD[0] == 1) { //��� ����ī���϶� ���� , ��� ���� ������ ��

	}
	else if (compareD[] != 1 && compareD.size >= 2) {// ����� ~ ��Ʈ����Ʈ �÷����϶�, ������ 2���̻� ������,
		
	}
	else { // ����� ~ ��Ʈ����Ʈ �÷����϶�, ������ ��ġ�� ����� ������
	}
}

};