#include "Application.h"

Application::Application() {

}

Application::~Application() {

}

void Application::run() {
	printf("Project on Console Application\n");

	// ������ �޾ƿ�
	Load_all_data();

	// Main���� �ٷ� ������� ��, Node ���� ����
	Graph MyGraph(NODE_CNT);
	MyGraph.Set_Matrix(*Route);
	Combine_NodeInfo();

	// ���ø����̼� ����
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
	int max_col_num = NODE_IDTCNT;
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
	int max_col_num = NODE_CNT;
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

// �׸����� ���
int Application::ProblemSolve01() {
	Dijkstra* Dij;
	Dij = new Dijkstra(*Route, NODE_CNT);
	Dij->Set_NodeInfo(NodeInfo);

	// ���� ��ġ�� Home���� ����
	Home = 0;
	int CurLoca = Home;
	int TargetLoca;									// Ÿ���� ��ġ
	int curTargetLength;							// ���� �湮�� ���
	int minTargetLength = 9999;						// ���� ����� Ÿ�ٰ��� �Ÿ�
	int minTargetIndex = 0;							// ���� ����� Ÿ���� �ε���
	int minVisitIndex = 0;							// ���� ����� Ÿ���� ���� �ε���
	int totalCost = 0;								// �������� ���ƿ��� ���� Cost ��
	int GivenTime = 700;							// �־��� �ð�
	int RemainTime = GivenTime;						// ���� ���� �ð�
	int ReturnCost = 0;								// ���ƿ��µ� �ҿ�Ǵ� ���
	int GivenPoketBall = POKE_INIT;					// �־��� ���Ϻ�
	int RemainPoketBall = GivenPoketBall;			// ���� ���� ���Ϻ�
	int targetPokeId = 2;							// Ÿ�� ���ϸ� ID

	cout << "Given Time	: " << GivenTime << endl;
	cout << "Given Pokeball	: " << GivenPoketBall << endl;
	cout << "Target Pokemon	: " << targetPokeId << endl << endl;

	// Dij �ʱ�ȭ
	Dij->Dijkstra_init();

	vector<int> VisitingTable;
	cout << "�湮�� ��� ����Ʈ" << endl;
	for (int i = 0; i < NODE_CNT; i++) {
		if (Loca_Data[i].Identifier == targetPokeId) {
			VisitingTable.push_back(Loca_Data[i].loca_index);
			cout << Loca_Data[i].loca_index << " ";
		}
	}
	cout << " " << endl << endl;

	vector<int> PokeStopTable;
	cout << "���� ��ž ����Ʈ" << endl;
	for (int i = 0; i < NODE_CNT; i++) {
		if (Loca_Data[i].Identifier == POKESTOP_INDEX) {
			PokeStopTable.push_back(Loca_Data[i].loca_index);
			cout << Loca_Data[i].loca_index << " ";
		}
	}
	cout << " " << endl << endl;

	// ���� ��ġ���� �湮 �� ����� �ִ� �Ÿ��� ���� ���ؼ�
	// ���� ����� ��� �ε����� ����
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

	// ������ ���̺� �߿��� ���� ����� ��� ������� �ݺ�
	while (!(VisitingTable.size() == 0)) {
		minTargetLength = HUGENUM;

		// ���Ϻ��� ���� ���
		if (RemainPoketBall <= 0) {
			cout << "���Ϻ��� �����ϴ�. ���Ϻ��� ������ ����� ���� ��ž�� �鸨�ϴ�." << endl;
			// ���� ��ġ���� �湮 �� ����� �ִ� �Ÿ��� ���� ���ؼ�
			// ���� ����� ��� �ε����� ����
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
			CurLoca = minTargetIndex;				// ���� ��ġ�� �ּ� Ÿ�� �ε����� �ʱ�ȭ
			MyRoute.push_back(minTargetIndex);		// �湮�� ��带 ������
			MyRouteCost.push_back(minTargetLength);	// �湮�� �������� ���̸� ������
			totalCost += minTargetLength;			// ��ü Cost�� �߰�
			RemainPoketBall += POKE_SUPPLE;		// ���Ϻ� �Ҹ�
		}
		else {

			for (int i = 0; i < VisitingTable.size(); i++) {
				TargetLoca = VisitingTable[i];
				Dij->Dijkstra_init();
				curTargetLength = Dij->Dijkstra_run(CurLoca, TargetLoca);
				// �ּҰŸ��� ������Ʈ
				if (curTargetLength < minTargetLength) {
					minTargetLength = curTargetLength;
					minTargetIndex = TargetLoca;
					minVisitIndex = i;
				}
			}

			// �ð��� �ȵɰ�� �ش� ������ ��������
			Dij->Dijkstra_init();					// �������� �Ÿ� ���
			int ReturnHomeCost = Dij->Dijkstra_run(minTargetIndex, Home);
			RemainTime -= minTargetLength;			// ���� �ð� �ʱ�ȭ
			if (RemainTime < ReturnHomeCost) {
				RemainTime -= ReturnHomeCost;		// ���� �ð� �ʱ�ȭ
				cout << endl;
				cout << "�־��� �ð�		" << GivenTime << endl;	// �־��� �ð�
				cout << "Destination Cost	" << totalCost << endl;	// Dest ������ Cost
				Dij->Dijkstra_init();
				ReturnCost = Dij->Dijkstra_run(CurLoca, Home);		// Home ������ Cost
				cout << "���� �����ð�		" << GivenTime - (totalCost + ReturnCost) << endl << endl;	// ��� �� �����ð�
				break;
			}

			// �ش� ��� �湮 ���� ���� ������Ʈ
			CurLoca = minTargetIndex;				// ���� ��ġ�� �ּ� Ÿ�� �ε����� �ʱ�ȭ
			MyRoute.push_back(minTargetIndex);		// �湮�� ��带 ������
			MyRouteCost.push_back(minTargetLength);	// �湮�� �������� ���̸� ������
			totalCost += minTargetLength;			// ��ü Cost�� �߰�
			RemainPoketBall -= POKE_CONSUME;		// ���Ϻ� �Ҹ�
			// �湮�� Node�� Table���� ����
			for (std::vector<int>::iterator iter = VisitingTable.begin(); iter != VisitingTable.end(); ) {
				if ((*iter) == minTargetIndex)
					iter = VisitingTable.erase(iter);
				else
					++iter;
			}
		}
	}

	cout << "�湮�� ��� ����Ʈ" << endl;
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
	cout << "Total Weight		" << totalCost + ReturnCost << endl; // ���� Cost
	cout << "Remain Weight		" << GivenTime - totalCost + ReturnCost << endl;
	cout << "To Dest Weight		" << totalCost << endl; // ���� Cost
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
	int TargetLoca;									// Ÿ���� ��ġ
	int curTargetLength;							// ���� �湮�� ���
	int minTargetLength = 9999;						// ���� ����� Ÿ�ٰ��� �Ÿ�
	int minTargetIndex = 0;							// ���� ����� Ÿ���� �ε���
	int minVisitIndex = 0;							// ���� ����� Ÿ���� ���� �ε���
	int totalCost = 0;								// �������� ���ƿ��� ���� Cost ��
	int GivenTime = 700;							// �־��� �ð�
	int RemainTime = GivenTime;						// ���� ���� �ð�
	int ReturnCost = 0;								// ���ƿ��µ� �ҿ�Ǵ� ���
	int GivenPoketBall = POKE_INIT;					// �־��� ���Ϻ�
	int RemainPoketBall = GivenPoketBall;			// ���� ���� ���Ϻ�
	vector<int> PokeStopRoute;
	vector<int> PokeStopRouteCost;


	// ���� ��ž ����Ʈ�� ����
	vector<int> PokeStopTable;
	cout << "���� ��ž ����Ʈ" << endl;
	for (int i = 0; i < NODE_CNT; i++) {
		if (Loca_Data[i].Identifier == POKESTOP_INDEX) {
			PokeStopTable.push_back(Loca_Data[i].loca_index);
			cout << Loca_Data[i].loca_index << " ";
		}
	}

	RemainPoketBall = 0;
	while (1) {
		minTargetLength = 9999;
		Dij->Dijkstra_init();							// �������� �Ÿ� ���
		int ReturnHomeCost = Dij->Dijkstra_run(NextLoca, Home);

		// ������ �湮 �� ���� �湮�� �ð����� ���� �� �� �ִ��� üũ	
		if (Pr2Path.get_totalWeight() + ReturnHomeCost > GivenTime) {
			// ��� �۾��� �����ϰ�, while���� ��������.
			break;
		}

		// ���� ���� ���Ϻ��� ������ ������� üũ
		if (RemainPoketBall <= 0) {
			// ���� ��ġ�� ���� ���� ����� ���Ͻ�ž�� �湮
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
			Node.set_Poke_Name("���Ͻ�ž");
			Node.set_Visited(true);
			NodeInfo[minTargetIndex].set_Visited(true);
			RemainPoketBall += POKE_SUPPLE;
			Pr2Path.add_Node(Node);
			Pr2Path.set_totalWeight(curTargetLength);
			CurLoca = minTargetIndex;
		}
		else {
			// ���� ��ġ�� ���� ���� ����� ��带 �湮��
			// �湮�ϸ� ���� ��ġ�� ������Ʈ
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

		// NextLoca ����
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