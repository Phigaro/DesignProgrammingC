#include "Dijkstra.h"

Dijkstra::Dijkstra() {
	num_Node = 100;
	CurNode = 0;
	init_flag = false;
}

Dijkstra::Dijkstra(int* _Matrix, int _num_node) {
	num_Node = _num_node;
	Matrix = (int**)malloc(sizeof(int*)*_num_node);
	for (int i = 0; i < num_Node; i++)
	{
		Matrix[i] = new int[_num_node];
		for (int j = 0; j < num_Node; j++) {
			Matrix[i][j] = *((_Matrix + i*num_Node) + j);
		}
	}
}

Dijkstra::~Dijkstra() {
	delete Matrix;
	delete CheckNode;
	delete Distance;
	delete history;
}

void Dijkstra::Set_Matrix(int* _Matrix) {
	for (int i = 0; i < num_Node; i++)
	{
		for (int j = 0; j < num_Node; j++) {
			Matrix[i][j] = *((_Matrix + i*num_Node) + j);
		}
	}
}

void Dijkstra::Set_NodeInfo(vector<NodeLoca> _NodeInfo) {
	NodeInfo = _NodeInfo;
}

void Dijkstra::Set_NodeNum(int _num_Node) {
	num_Node = _num_Node;
}

void Dijkstra::Dijkstra_init() {
	if (init_flag) {
		delete CheckNode;
		delete Distance;
		delete history;
	}

	Min_Weight = 0;
	CheckNode = new bool[num_Node];
	Distance = new int[num_Node];
	history = new int[num_Node];

	for (int i = 0; i < num_Node; i++) {
		CheckNode[i] = false;

		Distance[i] = HUGENUM;
		history[i] = HUGENUM;
		for (int j = 0; j < num_Node; j++) {
			if (Matrix[i][j] == -1) {
				Matrix[i][j] = HUGENUM;
			}
		}
	}
	init_flag = true;
}

int Dijkstra::Dijkstra_run(int _start, int _end) {
	NoRouteFlag = true;
	end = _end;
	start = _start;
	CurNode = _start;
	Distance[_start] = 0;
	Cur_Path.add_Node(NodeInfo[0]);
	Cur_Path.set_totalWeight(Distance[0]);

	while (true) {
		Min_Weight = HUGENUM;
		for (int i = 0; i < num_Node; i++) {
			/* �湮���� ���� ��尡 �������
			   �� ����� �Ÿ��� ���ݱ��� ã�� �ּ� �Ÿ����� ���� ���
			   ���� �ٷ� ���� ������, �ּ� �Ÿ��� ������Ʈ �� */
			if (CheckNode[i] == false && Distance[i] < Min_Weight) {
				CurNode = i;
				Min_Weight = Distance[i];
				NoRouteFlag = false;
			}
		}

		/* Loop ���� �������� �ּҰŸ��� ã�� ���� ��� �������� */
		if (Min_Weight == HUGENUM) {
			break;
		}

		CheckNode[CurNode] = true;

		/* ���ݱ��� ����� ��θ� ���� Distance�� ������Ʈ ��
		���� �߰��� ��带 ����, �� ���� ���� ������ �̸� �߰��� */
		for (int j = 0; j < num_Node; j++) {
			int distanceVertex = Distance[CurNode] + Matrix[CurNode][j];
			if (Distance[j] > distanceVertex) {
				Distance[j] = distanceVertex;
				history[j] = CurNode;
			}
		}

	}

	int total_Distance = Distance[end];
	if (Distance[end] < 0) {
		Distance[end] = -1;
	}
	int vertex = end;

	//cout << _start << "����	" << end <<  "���� �ִܰŸ�	" << Distance[end] << endl;
	//Print_Path();
	return total_Distance;
}

void Dijkstra::Print_Path() {
	std::stack<int> path;
	int vertex = end;
	bool flag = true;
	if (history[vertex] < 0) {
		cout << "No Route!!" << endl;
		flag = false;
	}
	while (flag) {
		if (vertex == start || vertex == HUGENUM) {
			break;
		}
		path.push(vertex);
		vertex = history[vertex];
	}
	cout << start << " ";
	while (!path.empty()) {
		cout << path.top();
		cout << " ";
		path.pop();
	}
	cout << endl << endl;
}