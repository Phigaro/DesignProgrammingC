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
	int get_Location_Id();

	void set_Id(int _Id);
	void set_Name(string _Name);
	void set_State(int _State);
	void set_Location_Id(int _Location_Id);

private:
	int Id;				// Pokemon Id
	string Name;		// Pokemon Name
	int State;			// Current State (Uncatched, catched)
	int Location_Id;	// Location Id
};