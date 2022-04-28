#pragma once
#include"Graphs.hpp"
#include"settings.hpp"

namespace eds {

	using PlainGraph = MGraph<int, int>


	void DFS(PlaintGraph G, int v, bool* visited, int vexnum) {
		visited[vexnum] = true;
		std::cout << "number:" << v << "founded" << std::endl;
		for()
	}

	void DFSTraverse(PlaintGraph G) {
		bool visited[G.arcnum];
	}

	

	
}