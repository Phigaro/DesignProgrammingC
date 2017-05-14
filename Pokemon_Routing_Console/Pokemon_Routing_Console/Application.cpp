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
	//interface.PrintMainMenu();
	//Con_Flag = interface.InputCommand();
	switch (CurInput)
	{
	case 1:
		//interface.PrintTimeMenu();
		Con_Time;
		//interface.PrintPokeMenu();
		Con_PokeId;
		break;
	case 2:
		//interface.PrintTimeMenu();
		Con_Time;
		break;
	case 3:
		break;
	default:
		break;
	}


	//ProblemSolve01();
	ProblemSolve02();

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

// 그리드한 방식
int Application::ProblemSolve01() {
	Dijkstra* Dij;
	Dij = new Dijkstra(*Route, NODE_CNT);
	Dij->Set_NodeInfo(NodeInfo);

	// 현재 위치를 Home으로 설정
	Home = 0;
	int CurLoca = Home;
	int TargetLoca;									// 타겟의 위치
	int curTargetLength;							// 현재 방문한 노드
	int minTargetLength = 9999;						// 가장 가까운 타겟과의 거리
	int minTargetIndex = 0;							// 가장 가까운 타겟의 인덱스
	int minVisitIndex = 0;							// 가장 가까운 타겟의 벡터 인덱스
	int totalCost = 0;								// 목적지와 돌아오는 값의 Cost 합
	int GivenTime = 700;							// 주어진 시간
	int RemainTime = GivenTime;						// 현재 남은 시간
	int ReturnCost = 0;								// 돌아오는데 소용되는 비용
	int GivenPoketBall = POKE_INIT;					// 주어진 포켓볼
	int RemainPoketBall = GivenPoketBall;			// 현재 남은 포켓볼
	int targetPokeId = 2;							// 타켓 포켓몬 ID

	cout << "Given Time	: " << GivenTime << endl;
	cout << "Given Pokeball	: " << GivenPoketBall << endl;
	cout << "Target Pokemon	: " << targetPokeId << endl << endl;

	// Dij 초기화
	Dij->Dijkstra_init();

	vector<int> VisitingTable;
	cout << "방문할 노드 리스트" << endl;
	for (int i = 0; i < NODE_CNT; i++) {
		if (Loca_Data[i].Identifier == targetPokeId) {
			VisitingTable.push_back(Loca_Data[i].loca_index);
			cout << Loca_Data[i].loca_index << " ";
		}
	}
	cout << " " << endl << endl;

	vector<int> PokeStopTable;
	cout << "포켓 스탑 리스트" << endl;
	for (int i = 0; i < NODE_CNT; i++) {
		if (Loca_Data[i].Identifier == POKESTOP_INDEX) {
			PokeStopTable.push_back(Loca_Data[i].loca_index);
			cout << Loca_Data[i].loca_index << " ";
		}
	}
	cout << " " << endl << endl;

	// 현재 위치에서 방문 할 노드의 최단 거리를 전부 구해서
	// 가장 가까운 노드 인덱스를 저장
	vector<int> MyRoute;
	vector<int> MyRouteCost;
	for (int i = 0; i < VisitingTable.size(); i++) {
		TargetLoca = VisitingTable[i];
		Dij->Dijkstra_init();
		curTargetLength = Dij->Dijkstra_run(CurLoca, TargetLoca);
		if (curTargetLength < minTargetLength) {
			minTargetLength = curTargetLength;
			minTargetIndex = TargetLoca;
		}
	}

	// 비지팅 테이블 중에서 가장 가까운 노드 순서대로 반복
	while (!(VisitingTable.size() == 0)) {
		minTargetLength = HUGENUM;

		// 포켓볼이 없을 경우
		if (RemainPoketBall <= 0) {
			cout << "포켓볼이 없습니다. 포켓볼을 가지러 가까운 포켓 스탑에 들릅니다." << endl;
			// 현재 위치에서 방문 할 노드의 최단 거리를 전부 구해서
			// 가장 가까운 노드 인덱스를 저장
			vector<int> PokeStopRoute;
			vector<int> PokeStopRouteCost;
			for (int i = 0; i < PokeStopTable.size(); i++) {
				TargetLoca = PokeStopTable[i];
				Dij->Dijkstra_init();
				curTargetLength = Dij->Dijkstra_run(CurLoca, TargetLoca);
				if (curTargetLength < minTargetLength) {
					minTargetLength = curTargetLength;
					minTargetIndex = TargetLoca;
				}
			}
			CurLoca = minTargetIndex;				// 현재 위치를 최소 타겟 인덱스로 초기화
			MyRoute.push_back(minTargetIndex);		// 방문한 노드를 저장함
			MyRouteCost.push_back(minTargetLength);	// 방문한 노드까지의 길이를 저장함
			totalCost += minTargetLength;			// 전체 Cost를 추가
			RemainPoketBall += POKE_SUPPLE;		// 포켓볼 소모
		}
		else {

			for (int i = 0; i < VisitingTable.size(); i++) {
				TargetLoca = VisitingTable[i];
				Dij->Dijkstra_init();
				curTargetLength = Dij->Dijkstra_run(CurLoca, TargetLoca);
				// 최소거리로 업데이트
				if (curTargetLength < minTargetLength) {
					minTargetLength = curTargetLength;
					minTargetIndex = TargetLoca;
					minVisitIndex = i;
				}
			}

			// 시간이 안될경우 해당 루프를 빠져나감
			Dij->Dijkstra_init();					// 집까지의 거리 계산
			int ReturnHomeCost = Dij->Dijkstra_run(minTargetIndex, Home);
			RemainTime -= minTargetLength;			// 남은 시간 초기화
			if (RemainTime < ReturnHomeCost) {
				RemainTime -= ReturnHomeCost;		// 남은 시간 초기화
				cout << endl;
				cout << "주어진 시간		" << GivenTime << endl;	// 주어진 시간
				cout << "Destination Cost	" << totalCost << endl;	// Dest 까지의 Cost
				Dij->Dijkstra_init();
				ReturnCost = Dij->Dijkstra_run(CurLoca, Home);		// Home 까지의 Cost
				cout << "최종 남은시간		" << GivenTime - (totalCost + ReturnCost) << endl << endl;	// 계산 후 남은시간
				break;
			}

			// 해당 노드 방문 현재 정보 업데이트
			CurLoca = minTargetIndex;				// 현재 위치를 최소 타겟 인덱스로 초기화
			MyRoute.push_back(minTargetIndex);		// 방문한 노드를 저장함
			MyRouteCost.push_back(minTargetLength);	// 방문한 노드까지의 길이를 저장함
			totalCost += minTargetLength;			// 전체 Cost를 추가
			RemainPoketBall -= POKE_CONSUME;		// 포켓볼 소모
			// 방문한 Node를 Table에서 삭제
			for (std::vector<int>::iterator iter = VisitingTable.begin(); iter != VisitingTable.end(); ) {
				if ((*iter) == minTargetIndex)
					iter = VisitingTable.erase(iter);
				else
					++iter;
			}
		}
	}

	cout << "방문한 노드 리스트" << endl;
	for (int i = 0; i < MyRoute.size(); i++) {
		cout << MyRoute[i] << " ";
	}
	cout << endl << endl;

	cout << "cost" << endl;
	for (int i = 0; i < MyRouteCost.size(); i++) {
		cout << MyRouteCost[i] << " ";
	}
	cout << endl << endl;

	cout << "Given Weight		" << GivenTime << endl;
	cout << "Total Weight		" << totalCost + ReturnCost << endl; // 최종 Cost
	cout << "Remain Weight		" << GivenTime - totalCost + ReturnCost << endl;
	cout << "To Dest Weight		" << totalCost << endl; // 최종 Cost
	cout << "To Home Weight		" << ReturnCost << endl;

	return 0;
}

int Application::ProblemSolve02() {
	Dijkstra* Dij;
	Dij = new Dijkstra(*Route, NODE_CNT);
	Dij->Set_NodeInfo(NodeInfo);
	Path Pr2Path;
	Home = 0;
	int CurLoca = Home;
	int NextLoca = 0;
	int CurTarget = 0;
	int TargetLoca;									// 타겟의 위치
	int curTargetLength;							// 현재 방문한 노드
	int minTargetLength = 9999;						// 가장 가까운 타겟과의 거리
	int minTargetIndex = 0;							// 가장 가까운 타겟의 인덱스
	int minVisitIndex = 0;							// 가장 가까운 타겟의 벡터 인덱스
	int totalCost = 0;								// 목적지와 돌아오는 값의 Cost 합
	int GivenTime = 700;							// 주어진 시간
	int RemainTime = GivenTime;						// 현재 남은 시간
	int ReturnCost = 0;								// 돌아오는데 소용되는 비용
	int GivenPoketBall = POKE_INIT;					// 주어진 포켓볼
	int RemainPoketBall = GivenPoketBall;			// 현재 남은 포켓볼
	vector<int> PokeStopRoute;
	vector<int> PokeStopRouteCost;


	// 포켓 스탑 리스트를 저장
	vector<int> PokeStopTable;
	cout << "포켓 스탑 리스트" << endl;
	for (int i = 0; i < NODE_CNT; i++) {
		if (Loca_Data[i].Identifier == POKESTOP_INDEX) {
			PokeStopTable.push_back(Loca_Data[i].loca_index);
			cout << Loca_Data[i].loca_index << " ";
		}
	}

	RemainPoketBall = 0;
	while (1) {
		minTargetLength = 9999;
		Dij->Dijkstra_init();							// 집까지의 거리 계산
		int ReturnHomeCost = Dij->Dijkstra_run(NextLoca, Home);

		// 다음에 방문 할 곳을 방문시 시간내에 돌아 올 수 있는지 체크	
		if (Pr2Path.get_totalWeight() + ReturnHomeCost > GivenTime) {
			// 모든 작업을 종료하고, while문을 빠져나옴.
			break;
		}

		// 현재 가진 포켓볼의 갯수가 충분한지 체크
		if (RemainPoketBall <= 0) {
			// 현재 위치로 부터 가장 가까운 포켓스탑을 방문
			for (int i = 0; i < PokeStopTable.size(); i++) {
				TargetLoca = PokeStopTable[i];
				Dij->Dijkstra_init();
				curTargetLength = Dij->Dijkstra_run(CurLoca, TargetLoca);
				if (curTargetLength < minTargetLength) {
					minTargetLength = curTargetLength;
					minTargetIndex = TargetLoca;
				}
			}
			NodeLoca Node;
			Node.set_Id(minTargetIndex);
			Node.set_Poke_Id(11);
			Node.set_Poke_Name("포켓스탑");
			Node.set_Visited(true);
			NodeInfo[minTargetIndex].set_Visited(true);
			RemainPoketBall += POKE_SUPPLE;
			Pr2Path.add_Node(Node);
			Pr2Path.set_totalWeight(curTargetLength);
			CurLoca = minTargetIndex;
		}
		else {
			// 현재 위치로 부터 가장 가까운 노드를 방문함
			// 방문하면 현재 위치를 업데이트
			for (CurTarget = 0; CurTarget < NODE_CNT; CurTarget++) {
				curTargetLength = Route[CurLoca][CurTarget];
				if (curTargetLength < minTargetLength && curTargetLength > 0 && !NodeInfo[CurTarget].get_Visited() && !NodeInfo[CurTarget].get_Poke_Id() != 11) {
					minTargetLength = curTargetLength;
					minTargetIndex = CurTarget;
				}
			}
			NodeLoca Node;
			Node.set_Id(minTargetIndex);
			Node.set_Poke_Id(Loca_Data[minTargetIndex].Identifier);
			Node.set_Poke_Name(Loca_Identifier[Loca_Data[minTargetIndex].Identifier].poke_name);
			Node.set_Visited(true);
			NodeInfo[minTargetIndex].set_Visited(true);
			RemainPoketBall -= POKE_CONSUME;
			Pr2Path.add_Node(Node);
			Pr2Path.set_totalWeight(curTargetLength);
			CurLoca = minTargetIndex;
		}

		// NextLoca 설정
		minTargetLength = 9999;
		for (CurTarget = 0; CurTarget < NODE_CNT; CurTarget++) {
			curTargetLength = Route[CurLoca][CurTarget];
			if (curTargetLength < minTargetLength && curTargetLength > 0 && !NodeInfo[CurTarget].get_Visited() && !NodeInfo[CurTarget].get_Poke_Id() != 11) {
				minTargetLength = curTargetLength;
				minTargetIndex = CurTarget;
			}
		}
		NextLoca = minTargetIndex;

		
	}
	return 0;
}