#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
class Card {
	static int remain;
	static int remainCard[52];
	int shape_;
	int value_;
	char shape;
	std::string value;
	public:
		Card() {
			srand((unsigned int)time(NULL));
			int x = rand() % remain;
			shape_ = remainCard[x] / 13;
			value_ = (remainCard[x] % 13) + 1;
			if (shape_ == 0) {
				shape = 'H';
			}
			else if (shape_ == 1) {
				shape = 'S';
			}
			else if (shape_ == 2) {
				shape = 'C';
			}
			else {
				shape = 'D';
			}
			if (value_ == 1) {
				value = 'A';
			}
			else if (value_ == 11) {
				value = 'J';
			}
			else if (value_ == 12) {
				value = 'Q';
			}
			else if (value_ == 13) {
				value = 'K';

			}
			else {
				value = std::to_string(value_);
			}
			remainCard[x] = remainCard[--remain];
		}
		void cardprint() {//카드 프린트
			std::cout << shape << ", " << value << std::endl;

		}
		int getShape() {//모양 받기
			return shape_;
		}
		int getValue() {//숫자 받기
			return value_;
		}
		void shuffle() {//카드 다시 섞기
			remain = 52;
			for (int i = 0; i < 52; i++) {
				remainCard[i] = i;
			}
		}
};
int Card::remain = 52;
int Card::remainCard[52] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51 };
