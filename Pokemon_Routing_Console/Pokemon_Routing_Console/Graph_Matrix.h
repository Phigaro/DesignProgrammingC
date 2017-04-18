#pragma once
#include <vector>
#include "Application.h"
#include "NodeLoca.h"

#define Default_Node_Num 100

// 그래프 구조 행렬 그래프와, 리스트 그래프로 구현 가능

// 그래프 구조는 행렬 그래프를 위주로 사용하기로 한다.

// 메모리 낭비가 심한대신 속도가 빠름.

class Edge;

class Graph {
public:
	Graph();
	~Graph();
	Graph(int _num_Node);
	void Set_Matrix(int* _Matrix);		// 인접 매트릭스 초기화
	//void Set_NodeInfo(s_Loca_Data InfoTable);				// 노드 테이블 초기화
	//void Set_AddNodeInfo(s_Loca_Identifier Iden);				// 노드의 이름, 기타 정보를 초기화
	void Add_Edge(int from_node, int to_node, int weight);

private:
	NodeLoca* StartNode;			// 시작 노드
	std::vector <NodeLoca>NodeTable;	// 노드 정보.
	int num_Node;					// 노드의 갯수
	int num_Edge;					// Edge의 갯수
	int** Graph_Matrix;				// 인접 행렬
};

struct Edge {
	int to;
	int weight;
};