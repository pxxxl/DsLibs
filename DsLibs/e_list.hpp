#pragma once

#include"settings.hpp"

namespace eds {

	template<typename T>
	struct l_node {
		T data;
		l_node<T>* next;
	};

	template<typename T>
	class l_list {
	public:
		l_list();
		l_list(std::initializer_list<T> list);

		//clear the data in the linear list
		void clear_list() noexcept;

		//if the list is not empty, return true
		bool is_not_empty() const noexcept;

		//return the length of the list
		unsigned list_length() const noexcept;

		//get the Lvalue reference of the linear list
		//make sure len > n >= 0
		T& get_item(unsigned n) const;

		//find the first element causing func(sample, tested) to return true, and return its serial number.
		//return INFEASIBLE means no element match the demand
		int locate_item(const T& sample, std::function<bool(const T& sample, const T& tested)> func) const;

		//return the former element of the sample
		T* prior_item(const T& sample) const noexcept;

		//return the latter element of the sample
		T* next_item(const T& sample) const noexcept;

		//insert the element to linear_list[n]
		//make sure len >= n >= 0
		void list_insert(T inserted, unsigned n);

		//delete the element linear_list[n]
		//make sure len > n >= 0
		void list_delete(unsigned n);

		//call func(element) on each element in the linear list
		void list_traverse(std::function<void(T& element)> func);

		//insert the element to the tail of the linear list
		void push_back(T inserted);

		//pop the tail element
		T pop_back();

		//insert the element to the head of the linear list
		void insert_front(T inserted);

		//pop the front element
		T pop_front();

		//print the list to the console
		void print_linear_list(std::ostream& out) const noexcept;


		friend std::ostream& operator<<(std::ostream& out, const l_list<T>& sample) { sample.print_linear_list(out); return out; }

		T& operator[](unsigned n) { return get_item(n); }

		//friend class d_list_iterator<T>;

		//destructor
		~l_list();

		l_list(const l_list&) = delete;
	private:
		unsigned len = 0;
		l_node<T>* head = nullptr;
	};

	template<typename T>
	inline l_list<T>::l_list(){}

	template<typename T>
	inline l_list<T>::l_list(std::initializer_list<T> list)
	{
		len = list.size();
		if (len == 0) {
			l_list();
			return;
		}
		head = new l_node<T>;
		handle_memory_alloc(head);
		auto be = list.begin();
		auto en = list.end();
		auto cur = head;
		cur->data = *be;
		be++;
		while(be != en) {
			cur->next = new l_node<T>;
			handle_memory_alloc(cur->next);
			cur->next->data = *be;
			cur = cur->next;
			be++;
		}
		cur->next = nullptr;
		return;
	}

	template<typename T>
	inline void l_list<T>::clear_list() noexcept
	{
		auto hold = head;
		while (head != nullptr) {
			hold = head->next;
			free(head);
			head = hold;
		}
		len = 0;
	}

	template<typename T>
	inline bool l_list<T>::is_not_empty() const noexcept
	{
		if (len == 0) {
			return false;
		}
		return true;
	}

	template<typename T>
	inline unsigned l_list<T>::list_length() const noexcept
	{
		return len;
	}

	template<typename T>
	inline T& l_list<T>::get_item(unsigned n) const
	{
		if (n >= len) {
			throw std::runtime_error("From eds::l_list::get_item : n >= len");
		}
		auto cur = head;
		for (unsigned i = 0; i < n; i++) {
			cur = cur->next;
		}
		return cur->data;
	}

	template<typename T>
	inline int l_list<T>::locate_item(const T& sample, std::function<bool(const T& sample, const T& tested)> func) const
	{
		auto cur = head;
		for (int i = 0; cur != nullptr; i++) {
			if (func(sample, cur->data)) {
				return i;
			}
		}
		return INFEASIBLE;
	}

	template<typename T>
	inline T* l_list<T>::prior_item(const T& sample) const noexcept
	{
		if (len == 0) {
			return nullptr;
		}
		if (sample == head->data) {
			return nullptr;
		}
		auto cur = head;
		for (; cur->next != nullptr; cur = cur->next) {
			if (sample == cur->next->data) {
				return &(cur->data);
			}
		}
		return nullptr;
	}

	template<typename T>
	inline T* l_list<T>::next_item(const T& sample) const noexcept
	{
		if (len == 0) {
			return nullptr;
		}
		auto cur = head;
		for (; cur != nullptr; cur = cur->next) {
			if (sample == cur->data) {
				if (cur->next != nullptr) {
					return &(cur->next->data);
				}
				else {
					return nullptr;
				}
			}
		}
		return nullptr;
	}

	template<typename T>
	inline void l_list<T>::list_insert(T inserted, unsigned n)
	{
		if (n > len) {
			throw std::runtime_error("From eds::l_list::list_insert : n > len");
		}
		//从头开始
		if (n == 0) {
			if (len == 0) {
				head = new l_node<T>;
				handle_memory_alloc(head);
				head->next = nullptr;
				head->data = inserted;
			}
			else {
				auto cur = new l_node<T>;
				handle_memory_alloc(cur);
				cur->next = head;
				cur->data = inserted;
			}
		}
		else {
			auto cur = head;
			for (unsigned i = 1; i < n; i++) {
				cur = cur->next;
			}
			auto cur_next = cur->next;
			cur->next = new l_node<T>;
			handle_memory_alloc(cur->next);
			cur->next->next = cur_next;
			cur->next->data = inserted;
		}
		len++;
		return;
	}

	template<typename T>
	inline void l_list<T>::list_delete(unsigned n)
	{
		if (n >= len) {
			throw std::runtime_error("From eds::l_list::list_delete : n >= len");
		}
		if (n == 0) {
			if (len == 1) {
				free(head);
				head = nullptr;
			}
			else {
				auto cur = head;
				head = head->next;
				free(cur);
			}
		}
		else {
			auto cur = head;
			for (unsigned i = 1; i < n; i++) {
				cur = cur->next;
			}
			auto hold = cur->next;
			cur->next = cur->next->next;
			free(hold);
		}
		len--;
	}

	template<typename T>
	inline void l_list<T>::list_traverse(std::function<void(T& element)> func)
	{
		auto cur = head;
		for (; cur != nullptr; cur = cur->next) {
			func(cur->data);
		}
		return;
	}

	template<typename T>
	inline void l_list<T>::push_back(T inserted)
	{
		list_insert(inserted, len);
	}

	template<typename T>
	inline T l_list<T>::pop_back()
	{
		T&& hold = std::move(get_item(len - 1));
		list_delete(len - 1);
		return hold;
	}

	template<typename T>
	inline void l_list<T>::insert_front(T inserted)
	{
		list_insert(inserted, 0);
	}

	template<typename T>
	inline T l_list<T>::pop_front()
	{
		T&& hold = std::move(get_item(0));
		list_delete(0);
		return hold;
	}

	template<typename T>
	inline void l_list<T>::print_linear_list(std::ostream& out) const noexcept
	{
		l_node<T>* cur = head;
		for (; cur != nullptr; cur = cur->next) {
			std::cout << cur->data << " ";
		}
		return;
	}

	template<typename T>
	inline l_list<T>::~l_list()
	{
		clear_list();
	}

}