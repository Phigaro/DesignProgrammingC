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
	int** Matrix;	// ���� ���
	vector<NodeLoca> NodeInfo;	// ��� ����
	int num_Node;	// Node ����
	int CurNode;

	bool *CheckNode;
	int *Distance;	// �Ÿ� ���
	int Min_Weight;	// �ּ� ����ġ
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

	void Dijkstra_init();	// ���� �ʱ�ȭ
	int Dijkstra_run(int _start, int _end);	// �˰��� ����
	void Print_Path();

};

