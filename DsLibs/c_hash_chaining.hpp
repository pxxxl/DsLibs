#pragma once

#include"settings.hpp"

namespace eds {
	using Index = int;

	template<typename T>
	struct ListNode {
		ListNode* Next;
		T Data;
	};

	template<typename T>
	using Position = ListNode<T>*;
	template<typename T>
	using List = ListNode<T>*;

	template<typename T>
	struct HashTbl {
		int TableSize;
		List* TheLists;
		std::function<int(const T&)> Hash;
	};

	template<typename T>
	using HashTable = HashTbl*;

	template<typename T>
	inline HashTable<T> InitializeTable(int Tablesize, std::function<int(const T&)> hash) {
		Hashtabl = new HashTbl;
		HashTabl->TableSize = Tablesize;
		HashTabl->TheLists = new List[Tablesize];
		for (int i = 0; i < tab->TableSize; i++) {
			tab->TheLists[i] = nullptr;
		}
		HashTabl->Hash = hash;
		return HashTabl;
	}

	template<typename T>
	inline void DestroyTable(HashTable<T> tab) {
		for (int i = 0; i < tab->TableSize; i++) {
			List list = tab->TheLists[i];
			if (list == nullptr) {
				continue;
			}
			List cur = list->Next;
			while (list->Next != nullptr) {
				delete list;
				list = cur;
				cur = list->Next;
			}
			delete list;
		}
		delete tab->Lists;
		delete tab;
	}

	template<typename T>
	inline Position<T> Find(HashTable<T> tab, const T& key) {
		int index = tab->Hash(key);
		if (index >= tab->TableSize) {
			throw std::runtime_error("From eds::Hash::Find : hash error");
		}
		List<T> cur = tab[index];
		if(cur == nullptr){
			return nullptr;
		}
		if (cur->Data == key) {
			return cur;
		}
		while (cur->Next != nullptr && cur->Next->Data != key) {
			cur = cur->Next;
		}
		return cur->Next;
	}

	template<typename T>
	inline void Insert(HashTable<T> tab, T key) {

	}
}