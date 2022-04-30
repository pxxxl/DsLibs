#pragma once

enum class ColorType {
	Red,
	Black
};

template<typename T>
struct RedBlackNode;

template<typename T>
using RedBlackTree = RedBlackNode<T>*;

template<typename T>
struct RedBlackNode {
	T Data;
	RedBlackTree Left;
	RedBlackTree Right;
	ColorType Color;
};

