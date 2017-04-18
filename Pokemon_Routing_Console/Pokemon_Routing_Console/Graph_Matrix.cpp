#include "Graph_Matrix.h"

Graph::Graph() {
	num_Node = Default_Node_Num;
	Graph_Matrix = new int *[num_Node];					//��Ʈ���� �޸� �Ҵ�
	for (int i = 0; i < num_Node; i++)
	{
		Graph_Matrix[i] = new int[num_Node];				//��Ʈ���� [i-row] �޸� �Ҵ�
		memset(Graph_Matrix[i], 0, sizeof(int)*num_Node);	//�޸� 0���� �ʱ�ȭ
	}
}

Graph::~Graph() {
	for (int i = 0; i < num_Node; i++)
	{
		delete[] Graph_Matrix[i];							//��Ʈ���� [i-row]  �޸� �Ҹ�
	}
	delete[] Graph_Matrix;									//��Ʈ���� �޸� ����     
}

Graph::Graph(int _num_Node) {
	num_Node = _num_Node;
	Graph_Matrix = new int *[_num_Node];					//��Ʈ���� �޸� �Ҵ�
	for (int i = 0; i < _num_Node; i++)
	{
		Graph_Matrix[i] = new int[_num_Node];				//��Ʈ���� [i-row] �޸� �Ҵ�
		memset(Graph_Matrix[i], 0, sizeof(int)*_num_Node);	//�޸� 0���� �ʱ�ȭ
	}
}

void Graph::Set_Matrix(int* _Matrix) {
	for (int i = 0; i < num_Node; i++)
	{
		for (int j = 0; j < num_Node; j++) {
			Graph_Matrix[i][j] = *((_Matrix + i) + j);
		}
	}
}

// Node
/*
void Graph::Set_NodeInfo(s_Loca_Data InfoTable) {
	for (int i = 0; i < num_Node; i++) {
		NodeTable[i].set_Id(i);
		NodeTable[i].set_Poke_Id((InfoTable+i)->Identifier);
	}
}*/

void Graph::Add_Edge(int from_node, int to_node, int weight) {
	Graph_Matrix[from_node][to_node] = weight;
	Graph_Matrix[to_node][from_node] = weight;
}