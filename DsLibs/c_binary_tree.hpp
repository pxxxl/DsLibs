#pragma once

#include"settings.hpp"

namespace eds {

	template<typename T>
	struct b_tree_node { b_tree_node* left; b_tree_node* right; T data; };

	template<typename T>
	class b_tree{
	public:
		b_tree() { root = new b_tree_node<T>; handle_memory_alloc(root); };
		b_tree(std::initializer_list<T> list){}

		//clear the data in the linear list
		void clear_tree() noexcept;

		//if the tree is not empty, return true
		bool is_not_empty() const noexcept;

		//return the depth of the list
		unsigned tree_depth() const noexcept;

		//get the root node of the tree
		tree_node<T>* get_root() const noexcept;

		//get the parent of the tree node
		tree_node<T>* get_parent(const tree_node<T>*) const noexcept;

		//get the left most child of the tree node
		tree_node<T>* get_left_child(const tree_node<T>*) const noexcept;

		//get the right sibling of the tree node
		tree_node<T>* get_right_sibling(const tree_node<T>*) const noexcept;

		//insert the element
		void insert_node(T inserted);

		//delete the node
		void delete_node(tree_node<T>*);

		//find the value of the node
		tree_node<T> find_node(T sample);

		//call func(element) on each element in the linear list
		void tree_traverse(std::function<void(T& element)> func);

	private:
		b_tree_node<T>* root;
	};

	template<typename T>
	inline bool b_tree<T>::is_not_empty() const noexcept
	{
		if (root == nullptr) {
			return false;
		};
		return true;
	}

	template<typename T>
	inline unsigned b_tree<T>::tree_depth() const noexcept
	{

		return 0;
	}


}