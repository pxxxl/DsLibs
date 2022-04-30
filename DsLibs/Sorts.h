#pragma once

#include"c_heap.hpp"
#include<iostream>

//ð�����򣨼���Ľ��棩
//ѡ������
//��������
//ϣ������
//�Զ����¹鲢
//�Ե����Ϲ鲢
//��������
//������

namespace eds {

//https://zhuanlan.zhihu.com/p/40695917

	void printArray(int* arr, int length) {
		for (int i = 0; i < length; i++) {
			std::cout << arr[i] << "  ";
		}
		std::cout << std::endl;
	}

	void swapElem(int& a, int& b) {
		int c = a;
		a = b;
		b = c;
		return;
	}

	//ð������flag��trueʱ��С����falseʱ�Ӵ�С
	void bubbleSort(int* arr,int length, bool flag) {
		if (arr == NULL) {
			return;
		}
		for (int i = 0; i < length-1; i++) {
			for (int j = 0; j < length-i-1; j++) {
				if ((arr[j] > arr[j + 1]) == flag) {
					swapElem(arr[j], arr[j + 1]);
				}
			}
		}
		return;
	}

	//������ÿһ��ѭ���н��м��飬���û�н�������ֱ���˳�
	void bubbleSortPlus(int* arr, int length, bool flag) {
		if (arr == NULL) {
			return;
		}
		bool exchange = false;
		for (int i = 0; i < length - 1; i++) {
			for (int j = 0; j < length - i - 1; j++) {
				if ((arr[j] > arr[j + 1]) == flag) {
					swapElem(arr[j], arr[j + 1]);
					exchange = true;
				}
			}
			if (exchange == false) {
				break;
			}
			else {
				exchange = false;
			}
		}
		return;
	}

	//ѡ������flag��trueʱ��С����falseʱ�Ӵ�С
	void selectSort(int* arr, int length, bool flag) {
		if (arr == NULL) {
			return;
		}
		int target = 0;
		for (int i = 0; i < length; i++) {
			for (int j = i; j < length; j++) {
				if ((arr[j] > arr[target]) == flag) {
					target = j;
				}
			}
			swapElem(arr[i], arr[target]);
			target = i + 1;
		}
		return;
	}

	//��������flag��trueʱ��С����falseʱ�Ӵ�С
	void insertSort(int* arr, int length, bool flag) {
		if (arr == NULL) {
			return;
		}
		for (int i = 0; i < length; i++) {
			int save = arr[i];
			int j = i - 1;
			for (; j >= 0; j--) {
				if ((save < arr[j]) == flag) {
					arr[j+1] = arr[j];
				}
				else {
					break;
				}
			}
			arr[j + 1] = save;
		}
	}

	void shellInsertSort(int*, int, int, bool);
	//ϣ������flag��trueʱ��С����falseʱ�Ӵ�С
	void shellSort(int* arr, int length, bool flag) {
		if (arr == NULL) {
			return;
		}
		for (int step = length / 2; step != 0; step /= 2) {
			shellInsertSort(arr, length, step, flag);
		}
	}
	void shellInsertSort(int* arr, int length, int step, bool flag) {
		for (int i = 0; i + step <= length; i += step) {
			int save = arr[i];
			int j = i - step;
			for (; j >= 0; j -= step) {
				if ((save < arr[j]) == flag) {
					arr[j + step] = arr[j];
				}
				else {
					break;
				}
			}
			arr[j + step] = save;
		}
	}

	void mergeTD(int* arr, int start, int end, bool flag, int* space);
	void mergeSortTDDetail(int* arr, int start, int end, bool flag, int* space);
	//�Զ����¹鲢����flag��trueʱ��С����falseʱ�Ӵ�С
	//start��ʼ��endβ��(start+end)/2�ض�
	void mergeSortTD(int* arr, int length, bool flag) {
		if (arr == NULL) {
			return;
		}
		int* space = new int[length];
		mergeSortTDDetail(arr, 0, length / 2, flag, space);
		mergeSortTDDetail(arr, length / 2, length, flag, space);
		mergeTD(arr, 0, length, flag, space);
		return;
	}

	void mergeTD(int* arr, int start, int end, bool flag, int* space) {
		if (start + 1 >= end) {
			return;
		}
		int cut = (start + end) / 2;
		for (int i = start; i != end; i++) {
			space[i] = arr[i];
		}
		int curA = start;
		int curB = cut;
		for (int cur = start; cur < end; cur++) {
			if (curA != cut && curB != end) {
				if ((space[curA] < space[curB]) == flag) {
					arr[cur] = space[curA];
					curA++;
				}
				else {
					arr[cur] = space[curB];
					curB++;
				}
			}
			else if (curA == cut) {
				arr[cur] = space[curB];
				curB++;
			}
			else {
				arr[cur] = space[curA];
				curA++;
			}
		}
	}
	void mergeSortTDDetail(int* arr, int start, int end, bool flag, int* space) {
		if (start + 1 >= end) {
			return;
		}
		mergeSortTDDetail(arr, start, (end + start) / 2, flag, space);
		mergeSortTDDetail(arr, (end + start) / 2, end, flag, space);
		mergeTD(arr, start, end, flag, space);
	}

	void mergeDT(int* arr, int start, int end, int cut, bool flag, int* space);
	//�Ե����Ϲ鲢����flag��trueʱ��С����falseʱ�Ӵ�С
	//start��ʼ��endβ��(start+end)/2�ض�
	void mergeSortDT(int* arr, int length, bool flag) {
		int* space = new int[length];
		for (int step = 2; step < length; step *= 2) {
			for (int i = 0; i + step <= length; i += step) {
				mergeDT(arr, i, i + step, i + step / 2, flag, space);
			}
		}
		return;
	}

	void mergeDT(int* arr, int start, int end, int cut, bool flag, int* space){
		if (start + 1 >= end) {
			return;
		}
		for (int i = start; i != end; i++) {
			space[i] = arr[i];
		}
		int curA = start;
		int curB = cut + 1;
		for (int cur = start; cur < end; cur++) {
			if (curA != cut && curB != end) {
				if ((space[curA] < space[curB]) == flag) {
					arr[cur] = space[curA];
					curA++;
				}
				else {
					arr[cur] = space[curB];
					curB++;
				}
			}
			else if (curA == cut) {
				arr[cur] = space[curB];
				curB++;
			}
			else {
				arr[cur] = space[curA];
				curA++;
			}
		}
	}


	//https://zhuanlan.zhihu.com/p/63202860
	void quickSortDetail(int* arr, int start, int end, bool flag);
	//��������flag��trueʱ��С����falseʱ�Ӵ�С
	void quickSort(int* arr, int length, bool flag) {
		quickSortDetail(arr, 0, length, flag);
		return;
	}

	void quickSortDetail(int* arr, int start, int end, bool flag){
		if (start + 1 >= end) {
			return;
		}
		int pivot = arr[start];
		int left = start;
		int right = end - 1;
		bool blank_in_left = true;
		while (right > left) {
			if (blank_in_left) {
				if ((arr[right] > pivot) == flag) {
					right--;
				}
				else {
					arr[left] = arr[right];
					left++;
					blank_in_left = false;
				}
			}
			else {
				if ((arr[left] < pivot) == flag) {
					left++;
				}
				else {
					arr[right] = arr[left];
					right--;
					blank_in_left = true;
				}
			}
		}
		arr[right] = pivot;
		quickSortDetail(arr, start, right, flag);
		quickSortDetail(arr, right+1, end, flag);
	}

	//������flag��trueʱ��С����falseʱ�Ӵ�С
	void heapSort(int* arr, int length, bool flag) {
		if (arr == NULL) {
			return;
		}
		int min = arr[0];
		for (int i = 0; i < length; i++) {
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		auto heap = InitializeHeap<int>(length, min);
		bool minInserted = false;
		for (int i = 0; i < length; i++) {
			if ( !minInserted && arr[i] == min) {
				minInserted = true;
			}
			else {
				Insert<int>(arr[i], heap);
			}
		}
		if (flag) {
			for (int i = 0; i < length; i++) {
				arr[i] = DeleteMin(heap);
			}
		}
		else {
			for (int i = length - 1; i >= 0; i--) {
				arr[i] = DeleteMin(heap);
			}
		}
	}


}