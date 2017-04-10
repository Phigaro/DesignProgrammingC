#include "Application.h"

Application::Application() {

}

Application::~Application() {

}

void Application::run() {
	printf("Project on Console Application\n");

	Load_all_data();

	system("pause");
}

void Application::Load_all_data() {
	Load_route_data();
	Load_Loca_Identifier();
	Load_Loca_Data();
}
int Application::Load_route_data() {
	ifstream infile;
	int row_idx = 0;
	int col_idx = 0;
	int max_row_num = 100;
	int max_col_num = 100;
	int cur_data = 0;

	infile.open("../Data/��ġ���Ҹ�ð�.txt");

	while (!infile.eof()) {
		infile >> cur_data;
		*(Route[col_idx] + row_idx) = cur_data;
		row_idx++;
		if (row_idx == max_row_num) {
			row_idx = 0;
			col_idx++;
			if (col_idx == max_col_num)
				col_idx = 0;
		}
	}
	infile.close();
	return 1;
}
int Application::Load_Loca_Identifier() {
	ifstream infile;
	int row_idx = 0;
	int col_idx = 0;
	int max_row_num = 3;
	int max_col_num = 12;
	int N_cur_data = 0;
	string S_cur_data = "";
	int count = 0;

	infile.open("../Data/��ġ�ĺ���.txt");

	while (!infile.eof()) {

		switch (count % 3) {
		case 0:
			infile >> N_cur_data;
			Loca_Identifier[col_idx].loca_index = N_cur_data;
			break;
		case 1:
			infile >> S_cur_data;
			break;
		case 2:
			infile >> S_cur_data;
			Loca_Identifier[col_idx].poke_name = S_cur_data;
			break;
		}
		row_idx++;
		if (row_idx == max_row_num) {
			row_idx = 0;
			col_idx++;
			if (col_idx == max_col_num)
				col_idx = 0;
		}
		count++;
	}
	infile.close();
	return 1;
}
int Application::Load_Loca_Data() {
	ifstream infile;
	int col_idx = 0;
	int max_row_num = 2;
	int max_col_num = 100;
	int N_cur_data = 0;
	string S_dummy_data = "";

	infile.open("../Data/��ġ����.txt");
	infile >> S_dummy_data; infile >> S_dummy_data;

	while (!infile.eof()) {
		infile >> N_cur_data;
		Loca_Data[col_idx].loca_index = N_cur_data;
		infile >> N_cur_data;
		Loca_Data[col_idx].Identifier = N_cur_data;
		col_idx++;
		if (col_idx == max_col_num)
			break;
	}
	infile.close();
	return 1;
}

