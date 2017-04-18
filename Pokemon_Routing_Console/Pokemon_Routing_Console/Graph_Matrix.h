#pragma once
#include <vector>
#include "Application.h"
#include "NodeLoca.h"

#define Default_Node_Num 100

// �׷��� ���� ��� �׷�����, ����Ʈ �׷����� ���� ����

// �׷��� ������ ��� �׷����� ���ַ� ����ϱ�� �Ѵ�.

// �޸� ���� ���Ѵ�� �ӵ��� ����.

class Edge;

class Graph {
public:
	Graph();
	~Graph();
	Graph(int _num_Node);
	void Set_Matrix(int* _Matrix);		// ���� ��Ʈ���� �ʱ�ȭ
	//void Set_NodeInfo(s_Loca_Data InfoTable);				// ��� ���̺� �ʱ�ȭ
	//void Set_AddNodeInfo(s_Loca_Identifier Iden);				// ����� �̸�, ��Ÿ ������ �ʱ�ȭ
	void Add_Edge(int from_node, int to_node, int weight);

private:
	NodeLoca* StartNode;			// ���� ���
	std::vector <NodeLoca>NodeTable;	// ��� ����.
	int num_Node;					// ����� ����
	int num_Edge;					// Edge�� ����
	int** Graph_Matrix;				// ���� ���
};

struct Edge {
	int to;
	int weight;
};