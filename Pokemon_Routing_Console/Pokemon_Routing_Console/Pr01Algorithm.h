#pragma once
#include "PrSolveAlgorithms.h"

class Pr01Algorithm : PrSolveAlgorithm {
private:
	int Time;
	int PokeID;
	std::vector<int> visitingTable;
public:
	Pr01Algorithm();
	~Pr01Algorithm();
	void run();

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

void Pr01Algorithm::run() {

}

void Pr01Algorithm::init() {

}

void Pr01Algorithm::settingVisitingTable() {

}

void Pr01Algorithm::enableReturnInTime() {

}
