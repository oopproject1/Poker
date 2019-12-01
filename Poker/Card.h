#pragma once
#include <string>
class Card {
private:
	static int remain;
	static int remainCard[52];
	int shape_;
	int value_;
	std::string shape;
	std::string value;
public:
	Card();
	void cardDrow();
	void cardprint();
	int getShape();
	int getValue();
	void shuffle();
};
