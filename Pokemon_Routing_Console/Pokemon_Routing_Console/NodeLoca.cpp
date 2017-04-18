#include "NodeLoca.h"

NodeLoca::NodeLoca() {
	Id = -1;
	Poke_Id = -1;
	State = 0;
	for (int i = 0; i < NbNodeSize; i++) {
		Neighbor_Node[i] = -1;
	}
	Visited = false;
}

NodeLoca::~NodeLoca() {

}

int NodeLoca::get_Id() {
	return Id;
}

int NodeLoca::get_Poke_Id() {
	return Poke_Id;
}

std::string NodeLoca::get_Poke_Name() {
	return Poke_Name;
}

int* NodeLoca::get_Nbnode(){
	return Neighbor_Node;
}

int NodeLoca::get_State() {
	return State;
}

bool NodeLoca::get_Visited() {
	return Visited;
}

void NodeLoca::set_Id(int _Id) {
	Id = _Id;
}
void NodeLoca::set_Poke_Id(int _Poke_Id) {
	Poke_Id = _Poke_Id;
}
void NodeLoca::set_Poke_Name(std::string _Poke_Name) {
	Poke_Name = _Poke_Name;
}
void NodeLoca::set_Neighbor_Node(int* _Neighbor_Node) {
	for (int i = 0; i < NbNodeSize; i++) {
		if(!(*(_Neighbor_Node + i)==NULL))
		Neighbor_Node[i] = *(_Neighbor_Node + i);
	}
}
void NodeLoca::set_State(int _State) {
	State = _State;
}
void NodeLoca::set_Visited(bool _Visited) {
	Visited = _Visited;
}