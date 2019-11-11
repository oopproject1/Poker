#include "pch.h"
#include <iostream>

class Dealer {

	public:

	void start(){ //게임 시작 
		std::cout << "게임을 시작합니다." << std::endl;
		std::cout << "덱을 셔플합니다." << std::endl;
		std::cout << "카드를 3장씩 나눠줍니다." << std::endl;

	}  
	void attendcheck() { //참가 여부 확인
		std::cout << "참가를 하시겠습니까?" << std::endl;
	}

	void bet() { //참가를 한다면, 베팅
		std::cout << "베팅을 해주세요 (레이즈,콜,체크,올인,폴드)" << std::endl;

	}
	void card() { //카드 한장씩
		std::cout << "카드를 한장씩 나눠줍니다." << std::endl;
	}

	void winner() { //승자 결정
		
	}

	//게임 규칙 클래스 생성 후 그거에 맞는 조건 검사하여 멘트 출력
};
