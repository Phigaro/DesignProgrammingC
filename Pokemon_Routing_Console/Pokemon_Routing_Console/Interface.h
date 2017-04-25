#pragma once
#include <stdio.h>
#include <iostream>

class Interface{
public:
	Interface();
	~Interface();
	void PrintMainMenu();
	void PrintPokeMenu();
	void PrintTimeMenu();

	int InputCommand();
	void CommandErrorDection(int &command);

};