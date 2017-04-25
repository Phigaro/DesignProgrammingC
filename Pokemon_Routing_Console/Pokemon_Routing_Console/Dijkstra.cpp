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

void Dijkstra::Dijkstra_run(int _start, int _end) {
	end = _end;
	CurNode = _start;
	Distance[_start] = 0;
	Cur_Path.add_Node(NodeInfo[0]);
	Cur_Path.set_totalWeight(Distance[0]);

	while (true) {
		Min_Weight = HUGENUM;
		for (int i = 0; i < num_Node; i++) {
			/* 방문하지 않은 노드가 있을경우
			   그 노드의 거리가 지금까지 찾은 최소 거리보다 작을 경우
			   현재 다룰 노드로 설정함, 최소 거리를 업데이트 함 */
			if (CheckNode[i] == false && Distance[i] < Min_Weight) {
				CurNode = i;
				Min_Weight = Distance[i];
			}
		}

		/* Loop 문을 돌고나서도 최소거리를 찾지 못한 경우 빠져나옴 */
		if (Min_Weight == HUGENUM) {
			break;
		}

		CheckNode[CurNode] = true;

		/* 지금까지 연결된 경로를 통해 Distance를 업데이트 함
		새로 추가한 노드를 통해, 더 작은 길이 있으면 이를 추가함 */
		for (int j = 0; j < num_Node; j++) {
			int distanceVertex = Distance[CurNode] + Matrix[CurNode][j];
			if (Distance[j] > distanceVertex) {
				Distance[j] = distanceVertex;
				history[j] = CurNode;
			}
		}

	}

	int total_Distance = Distance[end];
	int vertex = end;

	cout << _start << " ~ " << end << endl;
	cout << "최단거리 " << Distance[end] << endl;
	Print_Path();
}

void Dijkstra::Print_Path() {
	std::stack<int> path;
	int vertex = end;
	while (true) {
		if (vertex == 0 || vertex == HUGENUM) {
			break;
		}
		path.push(vertex);
		vertex = history[vertex];
	}
	while (!path.empty()) {
		cout << path.top();
		cout << " ";
		path.pop();
	}
}