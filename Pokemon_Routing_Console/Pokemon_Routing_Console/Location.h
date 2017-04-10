#pragma once
#include <iostream>
#define NbNodeSize 5

class Location {
public:
	Location();				// Constructor
	~Location();			// Destructor

	int get_Id();			// Get Function
	int get_Poke_Id();
	int* get_Nbnode();
	int get_State();
	bool get_Visited();

	void set_Id(int _Id);	// Set Function
	void set_Poke_Id(int _Poke_Id);
	void set_Neighbor_Node(int* _Neighbor_Node);
	void set_State(int _State);
	void set_Visited(bool _Visited);

private:
	int Id;					// Location Id
	int Poke_Id;			// Pokemon Id
	int Neighbor_Node[NbNodeSize];	// Neighbor_Node Array
	int State;				// Current State (Poket_Stop Or having Pokemon etc)
	bool Visited;			// check visited.
};
