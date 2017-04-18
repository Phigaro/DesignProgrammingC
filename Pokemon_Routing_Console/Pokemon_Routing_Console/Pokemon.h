#pragma once
#include <string>
using namespace std;

class Pokemon {

public:
	Pokemon();
	~Pokemon();

	int get_Id();
	string get_Name();
	int get_State();
	int get_NodeLoca_Id();

	void set_Id(int _Id);
	void set_Name(string _Name);
	void set_State(int _State);
	void set_NodeLoca_Id(int _NodeLoca_Id);

private:
	int Id;				// Pokemon Id
	string Name;		// Pokemon Name
	int State;			// Current State (Uncatched, catched)
	int NodeLoca_Id;	// NodeLoca Id
};