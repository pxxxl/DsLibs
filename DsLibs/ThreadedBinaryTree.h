#pragma once

namespace eds {
	namespace core {
		template<typename T>
		struct ThrTreeNode;

		template<typename T>
		using ThrPosition = ThrTreeNode<T>*;

		template<typename T>
		using ThrTree = ThrTreeNode<T>*;

		template<typename T>
		struct ThrTreeNode {
			T Data;
			ThrTreeNode<T> Left;
			ThrTreeNode<T> Right;
			bool LeftExistChild;
			bool RightExistChild;
		};

		template<typename T>
		inline ThrTree<T> InOrderThreading(ThrTree<T> Tree) {

		}
	}
}