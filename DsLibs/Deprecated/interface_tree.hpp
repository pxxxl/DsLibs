#pragma once

#include"settings.hpp"

namespace eds {

	template<typename T>
	struct tree_node { T value; };

	template<typename T>
	class intf_tree {
	public:
		//clear the data in the linear list
		virtual void clear_tree() noexcept = 0;

		//if the tree is not empty, return true
		virtual bool is_not_empty() const noexcept = 0;

		//return the depth of the list
		virtual unsigned tree_depth() const noexcept = 0;

		//get the root node of the tree
		virtual tree_node<T>* get_root() const noexcept = 0;

		//get the parent of the tree node
		virtual tree_node<T>* get_parent(const tree_node<T>*) const noexcept = 0;

		//get the left most child of the tree node
		virtual tree_node<T>* get_left_child(const tree_node<T>*) const noexcept = 0;

		//get the right sibling of the tree node
		virtual tree_node<T>* get_right_sibling(const tree_node<T>*) const noexcept = 0;

		//insert the element
		virtual void insert_node(T inserted) = 0;

		//delete the node
		virtual void delete_node(tree_node<T>*) = 0;

		//find the value of the node
		virtual tree_node<T> find_node(T sample) = 0;

		//call func(element) on each element in the linear list
		virtual void tree_traverse(std::function<void(T& element)> func) = 0;
	};

}