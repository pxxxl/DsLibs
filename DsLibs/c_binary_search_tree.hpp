#pragma once

#include"settings.hpp"

namespace eds {
	template<typename T>
	struct TreeNode;

	template<typename T>
	using Position = TreeNode<T>*;

	template<typename T>
	using SearchTree = TreeNode<T>*;

	template<typename T>
	struct TreeNode {
		T Data;
		SearchTree<T> Left;
		SearchTree<T> Right;
	};

	template<typename T>
	inline SearchTree<T> MakeEmpty(SearchTree<T> Tree) {
		if (Tree != nullptr) {
			MakeEmpty(Tree->Left);
			MakeEmpty(Tree->Right);
			delete Tree;
		}
		return nullptr;
	}
	template<typename T>
	inline Position<T> Find(const T& sample, SearchTree<T> Tree) {
		if (Tree == nullptr) {
			return nullptr;
		}
		if (sample < Tree->Data) {
			return Find(sample, Tree->Left);
		}
		if (sample > Tree->Data) {
			return Find(sample, Tree->Right);
		}
		return Tree;
	}
	template<typename T>
	inline Position<T> FindMin(SearchTree<T> Tree) {
		if (Tree != nullptr) {
			while (Tree->Left != nullptr) {
				Tree = Tree->Left;
			}
		}
		return Tree;
	}
	template<typename T>
	inline SearchTree<T> FindMax(SearchTree<T> Tree) {
		if (Tree != nullptr) {
			while (Tree->Right != nullptr) {
				Tree = Tree->Right;
			}
		}
		return Tree;
	}

	template<typename T>
	inline SearchTree<T> Insert(T X, SearchTree<T> Tree) {
		if (Tree == nullptr) {
			Tree = new TreeNode<T>;
			Tree->Left = nullptr;
			Tree->Right = nullptr;
			Tree->Data = X;
		}
		else {
			if (Tree->Data == X) {
				Tree->Count++;
			}
			else if (Tree->Data > X) {
				Insert(X, Tree->Left);
			}
			else {
				Insert(X, Tree->Right);
			}
		}
		return Tree;
	}

	template<typename T>
	inline SearchTree<T> Clear(T X, SearchTree<T> Tree) {
		Position TmpCell;
		if (Tree == nullptr) {
			throw std::runtime_error("From eds::binary_search_tree : NULL TREE");
		}
		if (X > Tree->Data) {
			Clear(X, Tree->Right);
		}
		if (X < Tree->Data) {
			Clear(X, Tree->Left);
		}
		if (X = Tree->Data) {
			if (Tree->Left != nullptr && Tree->Right != nullptr) {
				TmpCell = FindMin(Tree->Right);
				Tree->Data = TmpCell->Data;
				Tree->Right = Clear(Tree->Data, Tree->Right);
			}
		}
		else {
			TmpCell = Tree;
			if (Tree->Left = nullptr) {
				Tree = Tree->Right;
			}
			else {
				Tree = Tree->Left;
			}
			delete TmpCell;
		}
		return Tree;
	}

	template<typename T>
	inline SearchTree<T> Delete(T X, SearchTree<T> Tree) {
		if (Tree == nullptr) {
			throw std::runtime_error("From eds::binary_search_tree : NULL TREE");
		}
		else {
			if (X < Tree->Data) {
				Delete(X, Tree->Left);
			}
			else if (X > Tree->Data) {
				Insert(X, Tree->Right);
			}
			else {
				if (Tree->Count != 0) {
					Count--;
				};
			}
		}
		return Tree;
	}


}