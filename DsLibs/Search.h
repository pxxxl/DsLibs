#pragma once
#include"settings.hpp"
#include"c_binary_search_tree.hpp"
#include"c_AVL_tree.hpp"

namespace eds {

	//顺序查找
	//折半查找
	//斐波那契查找
	//插值查找
	//分块查找
	
	//二叉排序树查找
	//AVL查找
	//B树查找
	//散列表查找

	//顺序查找
	int seqSearch(int* arr, int length, int target) {
		int i = 0;
		for (; arr[i] != target && i < length; i++);
		if (i == length) {
			return INFEASIBLE;
		}
		else {
			return i;
		}
	}

	//arr数组实际可用长度至少是length+1
	//顺序查找
	int seqSearchPlus(int* arr, int length, int target) {
		arr[length] = target;
		int i = 0;
		for (; arr[i] != target; i++);
		if (i == length) {
			return INFEASIBLE;
		}
		else {
			return i;
		}
	}

	//必须先排好序
	//折半查找
	int binarySearch(int* arr, int length, int target) {
		int left = 0;
		int right = length - 1;
		int middle = (left + right) / 2;
		while (left <= right) {
			if (arr[middle] < target) {
				left = middle + 1;
				middle = (left + right) / 2;
			}
			else if(arr[middle] > target) {
				right = middle - 1;
				middle = (left + right) / 2;
			}
			else {
				return middle;
			}
		}
		return INFEASIBLE;
	}

	int* Fibbonacci(int size, int* space);
	//必须先排好序
	//斐波那契查找
	//堆区污染，未完成
	int fibbonacciSearch(int* arr, int length, int target) {
		int* fibbonacci = Fibbonacci(length, new int[length]);
		int i = 0;
		for (; fibbonacci[i] - 1 < length; i++);
		int* enlarged = new int[fibbonacci[i]-1];
		memcpy(enlarged, arr, length*sizeof(int));
		for (int j = length; j < fibbonacci[i]; j++) {
			enlarged[j] = enlarged[length - 1];
		}

		int left = 0;
		int right = length - 1;
		while (left <= right) {
			int mid = left + fibbonacci[i - 1] - 1;
			if (enlarged[mid] < target) {
				left = mid + 1;
				i -= 2;
			}
			else if (enlarged[mid] > target) {
				right = mid - 1;
				i -= 1;
			}
			else {
				if (mid >= length) {
					delete[] fibbonacci;
					delete[] enlarged;
					return arr[length - 1];
				}
				else {
					delete[] fibbonacci;
					delete[] enlarged;
					return mid;
				}
			}
		}
		delete[] fibbonacci;
		delete[] enlarged;
		return INFEASIBLE;
	}
	int* Fibbonacci(int size, int* space) {
		space[0] = 1;
		space[1] = 1;
		for (int i = 2; i < size; i++) {
			space[i] = space[i - 1] + space[i - 2];
		}
		return space;
	}

	//插值查找


	int getBlock(int blockNum, int* blockMaxNum, int target);
	//要求已经分好块，且某个块的最大值不得大于在它后面的块的最小值
	//分块查找
	//没有测试过
	int blockSearch(int* arr, int length, int blockNum, int* blockIndexs, int* blockMaxNum, int target) {
		int blockIndex = getBlock(blockNum, blockMaxNum, target);
		if (blockIndex == INFEASIBLE) {
			return INFEASIBLE;
		}
		int start = blockIndexs[blockIndex];
		int end = 0;
		if (blockIndex == blockNum - 1) {
			end = length;
		}
		else {
			end = blockIndexs[blockIndex + 1];
		}
		
		return seqSearch(arr + start, end - start, target);
	}
	int getBlock(int blockNum, int* blockMaxNum, int target){
		for (int i = 0; i < blockNum; i++) {
			if (target < blockMaxNum[i]) {
				return i;
			}
		}
		return INFEASIBLE;
	}

	//二叉搜索
	//没测试过
	int binarySearchTreeSearch(int* arr, int length, int target) {
		SearchTree<int> tree = nullptr;
		for (int i = 0; i < length; i++) {
			Insert(arr[i], tree);
		}
		auto result = Find(target, tree);
		if (result == nullptr) {
			return INFEASIBLE;
		}
		else {
			return result->Data;
		}
	}

	//AVL搜索
	//没测试过
	int AVLSearch(int* arr, int length, int target) {
		AvlTree<int> tree = nullptr;
		for (int i = 0; i < length; i++) {
			Insert(arr[i], tree);
		}
		auto result = Find(target, tree);
		if (result == nullptr) {
			return INFEASIBLE;
		}
		else {
			return result->Data;
		}
	}
}