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
	PriorityQueue<T> Initialize(int MaxElements, T MinData) {
		PriorityQueue H = new HeapStruct;
		H->Elements = new T[MaxElements + 1];
		H->Capacity = MaxElement;
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
		if (0 = H->Size) {
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
			std::runtime_error("From eds::c_heap::Insert : heap full");
		}
		for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2) {
			H->Elements[i] = H->Elements[i / 2];
		}
		H->Elements[i] = X;
	}

	template<typename T>
	T DeleteMin(PriorityQueue<T> H) {
		
	}



}