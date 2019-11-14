#pragma once
#include<iostream>
#include <string>

class player {
private:
	int playerCash; // 플레이어가 가진 보유금액
	int playerBetting; // 플레이어가 배팅할 금액
	std::string playerCard; // 플레이어가 현재 가지고 있는 카드
	std::string playerIsWin;// 플레이어가 승리했는지 패배했는지 확인

public:
	int setPlayerBetting(); // 플레이어가 베팅한 금액만큼 보유금액에서 제외한다.
	void choiceCard(); // 플레이어가 보유한 카드중 공개할 카드 3장을 공개한다.
	void playerMenu(); //플레이어가 현재 할 행동을 선택한다.
};
