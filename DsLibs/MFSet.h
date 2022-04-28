#pragma once
#include "ParentTree.h"

namespace eds {
	namespace core {
		template<typename T>
		using MFSet = PTree<T>;

		using MFSetPosition = PTreePosition;

		template<typename T>
		MFSetPosition FindMFSet(MFSet<T> Set, MFSetPosition Position) {
			if (Position < 1 || Position > Set->NumOfNodes) {
				return -1;
			}
			MFSetPosition i = Position;
			//���Ҹ�
			for (; Set->Tree[i].Parent > 0; i = Set->Tree[i].Parent);
			//ѹ��·��
			for (MFSetPosition j = Position, MFSetPosition t = Position; j != i; j = t) {
				t = Set->Tree[j].Parent;
				Set->Tree[j].Parent = i;
			}
			return i;
		}

		template<typename T>
		MFSet<T> MergeMFSet(MFSet<T> Set, MFSetPosition Parent, MFSetPosition Child) {
			if (Position < 1 || Position > Set->NumOfNodes || PositionB < 1 || PositionB > Set->NumOfNodes) {
				return nullptr;
			}
			Set->Tree[Child].Parent = Parent;
			return Set;
		}

		//Ҫ����ڵ��parent��洢�伯��Ԫ����Ŀ�ĸ�ֵ
		template<typename T>
		MFSet<T> MixMFSet(MFSet<T> Set, MFSetPosition I, MFSetPosition J) {
			if (Position < 1 || Position > Set->NumOfNodes || PositionB < 1 || PositionB > Set->NumOfNodes) {
				return nullptr;
			}
			if (Set->Tree[I].Parent > Set->Tree[J].Parent) {
				Set->Tree[J].Parent += Set->Tree[I].Parent;
				Set->Tree[I].Parent = J;
			}
			else {
				Set->Tree[I].Parent += Set->Tree[J].Parent;
				Set->Tree[J].Parent = I;
			}
			return Set;
		}
	}
}