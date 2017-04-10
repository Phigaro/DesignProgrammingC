#include "Pokemon.h"

Pokemon::Pokemon() {

}

Pokemon::~Pokemon() {

}

int Pokemon::get_Id() {
	return Id;
}

string Pokemon::get_Name() {
	return Name;
}

int Pokemon::get_State() {
	return State;
}

int Pokemon::get_Location_Id() {
	return Location_Id;
}

void Pokemon::set_Id(int _Id) {
	Id = _Id;
}

void Pokemon::set_Name(string _Name) {
	Name = _Name;
}

void Pokemon::set_State(int _State) {
	State = _State;
}

void Pokemon::set_Location_Id(int _Location_Id) {
	Location_Id = _Location_Id;
}