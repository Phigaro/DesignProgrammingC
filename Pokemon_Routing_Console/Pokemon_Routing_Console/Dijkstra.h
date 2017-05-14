#pragma once
#include <queue>
#include <vector>
#include <stack>
#include "Graph_Matrix.h"
#include "NodeLoca.h"
#include "Path.h"

#define HUGENUM 9999

class Dijkstra {
private:
	int** Matrix;	// 인접 행렬
	vector<NodeLoca> NodeInfo;	// 노드 정보
	int num_Node;	// Node 갯수
	int CurNode;

	bool *CheckNode;
	int *Distance;	// 거리 행렬
	int Min_Weight;	// 최소 가중치
	int *history;
	Path Cur_Path;

	int start;
	int end;

	bool init_flag;
	bool NoRouteFlag;
public:
	Dijkstra();
	Dijkstra(int* _Matrix, int _num_node);
	~Dijkstra();
	
	void Set_Matrix(int* _Matrix);
	void Set_NodeInfo(vector<NodeLoca> _NodeInfo);
	void Set_NodeNum(int _num_Node);

	void Dijkstra_init();	// 정점 초기화
	int Dijkstra_run(int _start, int _end);	// 알고리즘 적용
	void Print_Path();

};

