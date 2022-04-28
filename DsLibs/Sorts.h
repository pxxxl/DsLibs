#pragma once
#include"e_d_list.hpp"
#include<iostream>

//冒泡排序（及其改进版）
//选择排序
//插入排序
//希尔排序
//自顶向下归并
//自底向上归并
//快速排序

namespace eds {

//https://zhuanlan.zhihu.com/p/40695917

	using sarray = d_list<int>;

	void printArray(int* arr, size_t length) {
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

	//冒泡排序，flag是true时从小到大，false时从大到小
	void bubbleSort(int* arr,size_t length, bool flag) {
		if (arr == NULL) {
			return;
		}
		for (unsigned i = 0; i < length-1; i++) {
			for (unsigned j = 0; j < length-i-1; j++) {
				if ((arr[j] > arr[j + 1]) == flag) {
					swapElem(arr[j], arr[j + 1]);
				}
			}
		}
		return;
	}

	//加入在每一个循环中进行检验，如果没有交换过，直接退出
	void bubbleSortPlus(int* arr, size_t length, bool flag) {
		if (arr == NULL) {
			return;
		}
		bool exchange = false;
		for (unsigned i = 0; i < length - 1; i++) {
			for (unsigned j = 0; j < length - i - 1; j++) {
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

	//选择排序，flag是true时从小到大，false时从大到小
	void selectSort(int* arr, size_t length, bool flag) {
		if (arr == NULL) {
			return;
		}
		unsigned target = 0;
		for (unsigned i = 0; i < length; i++) {
			for (unsigned j = i; j < length; j++) {
				if ((arr[j] > arr[target]) == flag) {
					target = j;
				}
			}
			swapElem(arr[i], arr[target]);
			target = i + 1;
		}
		return;
	}

	//插入排序，flag是true时从小到大，false时从大到小
	void insertSort(int* arr, size_t length, bool flag) {
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

	void shellInsertSort(int*, size_t, unsigned, bool);
	//希尔排序，flag是true时从小到大，false时从大到小
	void shellSort(int* arr, size_t length, bool flag) {
		if (arr == NULL) {
			return;
		}
		for (unsigned step = length / 2; step != 0; step /= 2) {
			shellInsertSort(arr, length, step, flag);
		}
	}
	void shellInsertSort(int* arr, size_t length, unsigned step, bool flag) {
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
	//自顶向下归并排序，flag是true时从小到大，false时从大到小
	//start起始，end尾后，(start+end)/2截断
	void mergeSortTD(int* arr, size_t length, bool flag) {
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
	//自底向上归并排序，flag是true时从小到大，false时从大到小
	//start起始，end尾后，(start+end)/2截断
	void mergeSortDT(int* arr, size_t length, bool flag) {
		int step = 2;
		int start = 0;
		int end = 0;
		int* space = new int[length];
		while (step <= length) {
			int i = 0;
			for (; i + step <= length - 1; i += step) {
				start = i;
				end = i + step;
				mergeDT(arr, start, end, start + step / 2, flag, space);
			}
			mergeDT(arr, i, length, i + step / 2, flag, space);
			step *= 2;
		}
		mergeDT(arr, 0, length, step / 2, flag, space);
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


	//https://zhuanlan.zhihu.com/p/63202860
	void quickSortDetail(int* arr, int start, int end, bool flag);
	//快速排序，flag是true时从小到大，false时从大到小
	void quickSort(int* arr, size_t length, bool flag) {
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

}