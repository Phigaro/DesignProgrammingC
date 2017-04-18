#pragma once
#include "NodeLoca.h"
#include <vector>

class Path{
private:
	// 노드의 정보를 담은 벡터리스트
	std::vector<NodeLoca> Path_Node_List;
	int total_weight;

public:
	Path() {
		total_weight = 0;
	}
	~Path(){}
	
	std::vector<NodeLoca> get_Path() {
		return Path_Node_List;
	}
	int get_totalWeight() {
		return total_weight;
	}
	
	int add_Node(NodeLoca _node) {
		Path_Node_List.push_back(_node);
		return 1;
	}

	int delete_Node(int _node_id) {
		/*std::vector<NodeLoca>::iterator iter;
		iter = Path_Node_List.begin;
		while (iter == Path_Node_List.end) {
			if (iter[0].get_Id() == _node_id) {
				Path_Node_List.erase(iter);
				return 1;
			}
			iter++;
		}*/
		return 0;
	}

	void set_Path(std::vector<NodeLoca> _Path) {
		Path_Node_List = _Path;
	}

	void set_totalWeight(int _Weight) {
		total_weight += _Weight;
	}

};