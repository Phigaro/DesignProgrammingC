#pragma once
#include "PrSolveAlgorithms.h"

class Pr01Algorithm : public PrSolveAlgorithm {
private:
	int Time;
	int PokeID;
	std::vector<int> visitingTable;


public:
	Pr01Algorithm();
	~Pr01Algorithm();
	int run();

	void init();
	void settingVisitingTable();
	void enableReturnInTime();
};

/* 
	방문 할 노드 리스트를 가져 와야함.
	시간내에 돌아오는지 구현.
	포켓볼이 부족하면, 그걸 처리하는 알고리즘 구현.
	가장 가까운 특정 몬스터에 접근 하는 알고리즘 구현.
*/

Pr01Algorithm::Pr01Algorithm() {

}

Pr01Algorithm::~Pr01Algorithm() {

}

int Pr01Algorithm::run() {

	return 0;
}

void Pr01Algorithm::init() {

}

void Pr01Algorithm::settingVisitingTable() {

}

void Pr01Algorithm::enableReturnInTime() {

}
