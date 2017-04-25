#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "NodeLoca.h"
#include "Pokemon.h"
#include "Graph_Matrix.h"
#include "Dijkstra.h"
#include "Interface.h"

using namespace std;

#define NODE_CNT 100		// 노드의 갯수
#define NODE_IDTCNT 12		// 노드 식별자의 가짓수

struct s_Loca_Identifier {
	int loca_index;
	string poke_name;
};

struct s_Loca_Data {
	int loca_index;
	int Identifier;
};

class Application {
private:
	int Route[NODE_CNT][NODE_CNT];					// Route (include Time)
	s_Loca_Data Loca_Data[NODE_CNT];				// NodeLoca Data
	s_Loca_Identifier  Loca_Identifier[NODE_IDTCNT];	// NodeLoca Identifier Data
	vector<NodeLoca> NodeInfo;

	Interface interface;
	int Con_Time;
	int Con_PokeId;
	int Con_Flag;
	int CurInput;

public:
	Application();
	~Application();
	void run();
	void Load_all_data();
	int Load_route_data();
	int Load_Loca_Identifier();
	int Load_Loca_Data();
	int Combine_NodeInfo();
};