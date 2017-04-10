#include "Location.h"

Location::Location() {
	Id = -1;
	Poke_Id = -1;
	State = 0;
	Visited = false;
}

Location::~Location() {

}

int Location::get_Id() {
	return Id;
}

int Location::get_Poke_Id() {
	return Poke_Id;
}

int* Location::get_Nbnode(){
	return Neighbor_Node;
}

int Location::get_State() {
	return State;
}

bool Location::get_Visited() {
	return Visited;
}

void Location::set_Id(int _Id) {
	Id = _Id;
}
void Location::set_Poke_Id(int _Poke_Id) {
	Poke_Id = _Poke_Id;
}
void Location::set_Neighbor_Node(int* _Neighbor_Node) {
	for (int i = 0; i < NbNodeSize; i++) {
		if(!(*(_Neighbor_Node + i)==NULL))
		Neighbor_Node[i] = *(_Neighbor_Node + i);
	}
}
void Location::set_State(int _State) {
	State = _State;
}
void Location::set_Visited(bool _Visited) {
	Visited = _Visited;
}