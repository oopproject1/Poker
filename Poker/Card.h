#include <string>
class Card {
private:
	static int remain;
	static int remainCard[52];
	int shape_;
	int value_;
	char shape;
	std::string value;
public:
	Card();
	Card(int code);
	void cardprint();
	int getShape();
	int getValue();
	void shuffle();
};
