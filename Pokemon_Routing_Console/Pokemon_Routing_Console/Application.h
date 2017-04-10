#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Location.h"
#include "Pokemon.h"
using namespace std;

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
	int Route[100][100];					// Route (include Time)
	s_Loca_Data Loca_Data[100];				// Location Data
	s_Loca_Identifier  Loca_Identifier[12];	// Location Identifier Data

public:
	Application();
	~Application();
	void run();
	void Load_all_data();
	int Load_route_data();
	int Load_Loca_Identifier();
	int Load_Loca_Data();
};