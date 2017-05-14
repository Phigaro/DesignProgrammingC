#include "Dijkstra.h"

#pragma once
#include <vector>


struct result {
	int Re_Time;
	int Re_Pokenum;
	int Re_Pokeball;
};

class PrSolveAlgorithm {
private:
	//Dijkstra Dij;
	result Result;
	int Flag;

public:
	int run();
	PrSolveAlgorithm() {}
	~PrSolveAlgorithm() {}
};