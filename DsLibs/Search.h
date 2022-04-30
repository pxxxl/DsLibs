#pragma once
#include"settings.hpp"
#include"c_binary_search_tree.hpp"
#include"c_AVL_tree.hpp"

namespace eds {

	//˳�����
	//�۰����
	//쳲���������
	//��ֵ����
	//�ֿ����
	
	//��������������
	//AVL����
	//B������
	//ɢ�б����

	//˳�����
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

	//arr����ʵ�ʿ��ó���������length+1
	//˳�����
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

	//�������ź���
	//�۰����
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
	//�������ź���
	//쳲���������
	//������Ⱦ��δ���
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

	//��ֵ����


	int getBlock(int blockNum, int* blockMaxNum, int target);
	//Ҫ���Ѿ��ֺÿ飬��ĳ��������ֵ���ô�����������Ŀ����Сֵ
	//�ֿ����
	//û�в��Թ�
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

	//��������
	//û���Թ�
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

	//AVL����
	//û���Թ�
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