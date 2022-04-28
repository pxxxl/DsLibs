#pragma once

namespace eds {
	namespace core {
		template<typename T>
		struct TreeNode;

		template<typename T>
		using Position = TreeNode<T>*;

		template<typename T>
		using Tree = TreeNode<T>*;

		template<typename T>
		using Forest = TreeNode<T>*;

		template<typename T>
		struct TreeNode {
			T Data;
			Tree<T> Left;
			Tree<T> Right;
		};


	}
}