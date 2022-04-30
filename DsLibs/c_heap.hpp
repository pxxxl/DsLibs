#pragma once

#include"settings.hpp"

namespace eds {
	template<typename T>
	struct HeapStruct {
		int Capacity;
		int Size;
		T* Elements;
	};

	template<typename T>
	using PriorityQueue = HeapStruct<T>*;

	template<typename T>
	PriorityQueue<T> InitializeHeap(int MaxElements, T MinData) {
		PriorityQueue<T> H = new HeapStruct<T>;
		H->Elements = new T[MaxElements + 1];
		H->Capacity = MaxElements;
		H->Size = 0;
		H->Elements[0] = MinData;
		return H;
	}

	template<typename T>
	int IsFull(PriorityQueue<T> H) {
		if (H->Capacity = H->Size) {
			return 1;
		}
		else {
			return 0;
		}
	}

	template<typename T>
	int IsEmpty(PriorityQueue<T> H) {
		if (0 == H->Size) {
			return 1;
		}
		else {
			return 0;
		}
	}

	template<typename T>
	const T& FindMin(PriorityQueue<T> H) {
		return H->Elements[1];
	}

	template<typename T>
	void Insert(T X, PriorityQueue<T> H) {
		int i;
		if (IsFull(H)) {
			throw std::runtime_error("From eds::c_heap::Insert : heap full");
		}
		for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2) {
			H->Elements[i] = H->Elements[i / 2];
		}
		H->Elements[i] = X;
	}

	template<typename T>
	T DeleteMin(PriorityQueue<T> H) {
		int i, Child;
		T MinElement, LastElement;

		if (IsEmpty(H)) {
			throw std::runtime_error("From eds::c_head::DeleteMin : heap empty");
		}
		MinElement = H->Elements[0];
		LastElement = H->Elements[H->Size --];

		for (i = 1; i * 2 <= H->Size; i = Child) {
			Child = i * 2;
			if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child]) {
				Child++;
			}

			if (LastElement > H->Elements[Child])
				H->Elements[i] = H->Elements[Child];
			else
				break;
		}
		H->Elements[i] = LastElement;
		return MinElement;
	}



}