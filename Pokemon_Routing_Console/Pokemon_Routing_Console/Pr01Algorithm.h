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
	�湮 �� ��� ����Ʈ�� ���� �;���.
	�ð����� ���ƿ����� ����.
	���Ϻ��� �����ϸ�, �װ� ó���ϴ� �˰��� ����.
	���� ����� Ư�� ���Ϳ� ���� �ϴ� �˰��� ����.
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
