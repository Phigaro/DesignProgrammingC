#include "Interface.h"

Interface::Interface() {

}

Interface::~Interface() {

}

void Interface::PrintMainMenu() {
	for (int i = 1; i<= 3; i++) {
		printf("%d. ���� %d\n", i,i);
	}
}

void Interface::PrintPokeMenu() {
	printf("1 : ��ī��\n");
	printf("2 : ������\n");
	printf("3 : ���̸�\n");
	printf("4 : ���α�\n");
	printf("5 : ������\n");
	printf("6 : �ߵ���\n");
	printf("7 : ������\n");
	printf("8 : �ǰ���\n");
	printf("9 : �Ḹ��\n");
	printf("10 : ���ڸ�\n");
}

void Interface::PrintTimeMenu() {
	printf("�ð��� �Է��� �ֽʽÿ�\n");
}

// Ŀ�ǵ� �Է� ���
int Interface::InputCommand() {
	int command;
	std::cout << "-----------------" << std::endl;
	std::cout << "-> ";
	std::cin >> command;
	CommandErrorDection(command);
	return command;
}

// �� int�� �Է� ���� Ž��.
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