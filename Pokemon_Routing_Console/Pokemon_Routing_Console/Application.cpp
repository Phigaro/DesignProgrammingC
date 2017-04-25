#include "Application.h"

Application::Application() {

}

Application::~Application() {

}

void Application::run() {
	printf("Project on Console Application\n");
	
	// 데이터 받아옴
	Load_all_data();

	// Main으로 다룰 인접행렬 및, Node 정보 셋팅
	Graph MyGraph(NODE_CNT);
	MyGraph.Set_Matrix(*Route);
	Combine_NodeInfo();

	// 어플리케이션 시작
	interface.PrintMainMenu();
	Con_Flag = interface.InputCommand();
	switch (CurInput)
	{
	case 1:
		interface.PrintTimeMenu();
		Con_Time;
		interface.PrintPokeMenu();
		Con_PokeId;
		break;
	case 2:
		interface.PrintTimeMenu();
		Con_Time;
		break;
	case 3:
		break;
	default:
		break;
	}

	// PrSolveAlgorithm(int Con_Time, int Con_PokeId, int Con_Flag);

	// 최소 경로를 가져오는 알고리즘.
	Dijkstra Dij(*Route, NODE_CNT);
	Dij.Set_NodeInfo(NodeInfo);
	Dij.Dijkstra_init();
	int i;
	int j;
	cin >> i;
	cin >> j;
	Dij.Dijkstra_run(i,j);


	printf("\n");
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
	int max_row_num = NODE_CNT;
	int max_col_num = NODE_CNT;
	int cur_data = 0;

	infile.open("../Data/위치별소모시간.txt");

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
	int max_col_num = NODE_IDTCNT;
	int N_cur_data = 0;
	string S_cur_data = "";
	int count = 0;

	infile.open("../Data/위치식별자.txt");

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
	int max_col_num = NODE_CNT;
	int N_cur_data = 0;
	string S_dummy_data = "";

	infile.open("../Data/위치정보.txt");
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

int Application::Combine_NodeInfo() {
	for (int i = 0; i < NODE_CNT; i++) {
		NodeLoca CurNode;
		CurNode.set_Id(Loca_Data[i].loca_index);
		CurNode.set_Poke_Id(Loca_Data[i].Identifier);
		CurNode.set_Poke_Name(Loca_Identifier[CurNode.get_Poke_Id()].poke_name);
		NodeInfo.push_back(CurNode);
	}

	return 0;
}

