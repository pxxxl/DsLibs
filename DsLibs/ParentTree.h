#pragma once

namespace eds {
	namespace core {
		template<typename T>
		struct PTreeNode;

		using PTreePosition = int;

		template<typename T>
		struct PTreeNode {
			T Data;
			int Parent;
		};

		template<typename T>
		struct PTreeData {
			PTreeNode* Tree;
			PTreePosition RootPosition;
			int NumOfNodes;
		};

		template<typename T>
		using PTree = PTreeData<T>*;
	}
}
