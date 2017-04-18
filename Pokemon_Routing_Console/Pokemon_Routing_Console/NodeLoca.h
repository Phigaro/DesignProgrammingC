#pragma once
#include <iostream>
#include <string>
#define NbNodeSize 5

class NodeLoca {
public:
	NodeLoca();				// Constructor
	~NodeLoca();			// Destructor

	int get_Id();			// Get Function
	int get_Poke_Id();
	std::string get_Poke_Name();
	int* get_Nbnode();
	int get_State();
	bool get_Visited();

	void set_Id(int _Id);	// Set Function
	void set_Poke_Id(int _Poke_Id);
	void set_Poke_Name(std::string _Poke_Name);
	void set_Neighbor_Node(int* _Neighbor_Node);
	void set_State(int _State);
	void set_Visited(bool _Visited);

private:
	int Id;					// NodeLoca Id
	int Poke_Id;			// Pokemon Id
	int Neighbor_Node[NbNodeSize];	// Neighbor_Node Array
	int State;				// Current State (Poket_Stop Or having Pokemon etc)
	std::string Poke_Name;	// Pokemon Name
	bool Visited;			// check visited.
};
