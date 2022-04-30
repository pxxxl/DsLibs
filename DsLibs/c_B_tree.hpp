#pragma once

#include"settings.hpp"

namespace eds {
	template<typename T>
	int BTreeBinarySearch(T* arr, int length, const T& target);

	template<typename T, unsigned N>
	struct BTNode;

	template<typename T, unsigned N>
	using BTPosition = BTNode<T>*;

	template<typename T, unsigned N>
	using BTree = BTNode<T>*;

	template<typename T, unsigned N>
	struct BTNode {
		int KeyNum;
		BTNode* Parent;
		T* Keys;
		BTNode** Childs;
	};

	template<typename T, unsigned N>
	BTPosition<T, N> Find(BTree Tree, const T& Target, int& position) {
		BTPosition<T, N> Cursor = Tree;

		while (Cursor != nullptr) {
			int Result = BTreeBinarySearch(Tree->Keys, KeyNum, Target);
			if ((Tree->Keys)[Result] == Target) {
				position = Result;
				return Cursor;
			}
			else {
				Cursor = Childs[Result + 1];
			}
		}
		return nullptr;
	}

	//返回使得arr[i]<=target的最大i,i最大是length-1;
	template<typename T>
	int BTreeBinarySearch(T* arr, int length, const T& target){
		int left = 0;
		int right = length - 1;
		int middle = (left + right) / 2;
		while (left <= right) {
			if (arr[middle] < target) {
				left = middle + 1;
				middle = (left + right) / 2;
			}
			else if (arr[middle] > target) {
				right = middle - 1;
				middle = (left + right) / 2;
			}
			else {
				return middle;
			}
		}
		return INFEASIBLE;
	}
}