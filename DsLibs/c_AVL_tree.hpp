#pragma once
#include"settings.hpp"

namespace eds {
	template<typename T>
	struct AvlNode;

	template<typename T>
	using APosition = AvlNode<T>*;

	template<typename T>
	using AvlTree = AvlNode<T>*;

	template<typename T>
	struct AvlNode {
		T Data;
		AvlTree<T> Left;
		AvlTree<T> Right;
		int Height;
	};

	template<typename T>
	inline AvlTree<T> MakeEmpty(AvlTree<T> Tree) {
		if (Tree != nullptr) {
			MakeEmpty(Tree->Left);
			MakeEmpty(Tree->Right);
			delete Tree;
		}
		return nullptr;
	}
	template<typename T>
	inline APosition<T> Find(const T& sample, AvlTree<T> Tree) {
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
	inline APosition<T> FindMin(AvlTree<T> Tree) {
		if (Tree != nullptr) {
			while (Tree->Left != nullptr) {
				Tree = Tree->Left;
			}
		}
		return Tree;
	}
	template<typename T>
	inline AvlTree<T> FindMax(AvlTree<T> Tree) {
		if (Tree != nullptr) {
			while (Tree->Right != nullptr) {
				Tree = Tree->Right;
			}
		}
		return Tree;
	}

	template<typename T>
	static int Height(APosition<T> Tree) {
		if (Tree == nullptr) {
			return -1;
		}
		else {
			return Tree->Height;
		}
	}

	template<typename T>
	static APosition<T> SingleRotateWithLeft(APosition<T> K2) {
		APosition<T> K1 = K2->Left;
		K2->Left = K1->Right;
		K1->Right = K2;
		
		K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;
		K1->Height = max(Height(K1->Left), Height(K1->Right)) + 1;
		return K1;
	}

	template<typename T>
	static APosition<T> SingleRotateWithRight(APosition<T> K2) {
		APosition<T> K1 = K2->Right;
		K2->Right = K1->Left;
		K1->Left = K2;

		K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;
		K1->Height = max(Height(K1->Left), Height(K1->Right)) + 1;
		return K1;
	}

	template<typename T>
	static APosition<T> DoubleRotateWithLeft(APosition<T> K3) {
		K3->Left = SingleRotateWithRight(K3->Left);
		return SingleRotateWithLeft(K3);
	}

	template<typename T>
	static APosition<T> DoubleRotateWithRight(APosition<T> K3) {
		K3->Left = SingleRotateWithLeft(K3->Left);
		return SingleRotateWithRight(K3);
	}

	template<typename T>
	inline AvlTree<T> Insert(T X, AvlTree<T> Tree) {
		if (Tree == nullptr) {
			Tree = new AvlNode<T>;
			Tree->Left = nullptr;
			Tree->Right = nullptr;
			Tree->Data = X;
			Tree->Height = 0;
		}
		else {
			if (X < Tree->Data) {
				Insert(X, Tree->Left);
				if (Height(Tree->Left) - Height(Tree->Right) == 2) {
					if (X < Tree->Left->Data) {
						Tree = SingleRotateWithLeft(Tree);
					}
					else {
						Tree = DoubleRotateWithRight(Tree);
					}
				}
			}
			else {
				Insert(X, Tree->Right);
				if (Height(Tree->Right) - Height(Tree->Left) == 2) {
					if (X < Tree->Right->Data) {
						Tree = SingleRotateWithRight(Tree);
					}
					else {
						Tree = DoubleRotateWithLeft(Tree);
					}
				}
			}
		}
		Tree->Height = max(Height(Tree->Right), Height(Tree->Left)) + 1;
		return Tree;
	}

	template<typename T>
	inline AvlTree<T> Delete(T X, AvlTree<T>* Tree) {

	}


}