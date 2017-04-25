#include "Interface.h"

Interface::Interface() {

}

Interface::~Interface() {

}

void Interface::PrintMainMenu() {
	for (int i = 1; i<= 3; i++) {
		printf("%d. 조건 %d\n", i,i);
	}
}

void Interface::PrintPokeMenu() {
	printf("1 : 피카츄\n");
	printf("2 : 라이츄\n");
	printf("3 : 파이리\n");
	printf("4 : 꼬부기\n");
	printf("5 : 버터플\n");
	printf("6 : 야도란\n");
	printf("7 : 피죤투\n");
	printf("8 : 또가스\n");
	printf("9 : 잠만보\n");
	printf("10 : 리자몽\n");
}

void Interface::PrintTimeMenu() {
	printf("시간을 입력해 주십시오\n");
}

// 커맨드 입력 기능
int Interface::InputCommand() {
	int command;
	std::cout << "-----------------" << std::endl;
	std::cout << "-> ";
	std::cin >> command;
	CommandErrorDection(command);
	return command;
}

// 비 int형 입력 에러 탐지.
void Interface::CommandErrorDection(int &command) {
	while (std::cin.fail()) {
		if (std::cin.fail()) {
			std::cout << "Error" << std::endl;
			std::cout << "-> ";
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		std::cin >> command;
	}
}