#pragma once
#include "NodeLoca.h"

typedef struct {
	NodeLoca Data;
	node* Next;
} node;

typedef node* Nptr;

typedef struct {
	int num_Node;
	int num_Edge;
	node **Start;
} graphType;

typedef graphType *graphPtr;

graphPtr InitGraph(int _num_Node)			// 정점 V개가 들어갈 수 있는 그래프 생성 
{
	graphPtr graph = new graphType;
	graph->num_Node = _num_Node;
	graph->num_Edge = 0;
	graph->Start = (node**)std::malloc(_num_Node * sizeof(node*));
	for (int i = 0; i < graph->num_Node; i++) {
		graph->Start[i] = NULL;
	}
	return graph;
}
void InsertEdge(graphPtr graph, int Snode_id, int Dnode_id)	// 정점 V1, V2를 연결하는 간선 삽입 
{
	Nptr temp = (node*)malloc(sizeof(node));		// 새로운 노드를 만들고 
	temp->Data.set_Id(Dnode_id);			// 거기에 V2의 ID 번호를 넣음 
	temp->Next = graph->Start[Snode_id];			// 새 노드가 현재 첫 노드를 가리키게  
	graph->Start[Snode_id] = temp;
	//g->L[V1] = temp;			// L[V1]이 새로만든 노드를 가리키게 
}