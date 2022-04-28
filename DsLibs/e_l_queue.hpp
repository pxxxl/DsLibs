#pragma once

#include"settings.hpp"
#include"e_d_list.hpp"

namespace eds {
	template<typename T>
	class l_queue {
	public:
		l_queue() noexcept {};
		l_queue(std::initializer_list<T> list) :d_list(list) {};

		//clear the queue
		void clear_queue() noexcept;

		//if queue is not empty, return true
		bool is_not_empty() const noexcept;

		//return the length of the queue
		unsigned queue_length() const noexcept;

		//get the head element of the queue
		T& get_head() const noexcept;

		//object enter the queue
		void en_queue(T object);

		//object get out of the queue
		T de_queue();

		//call func(element) on each elements in the queue
		void queue_traverse(std::function<void(T& element)> func);

	private:
		d_list<T> d_list;
	};
	template<typename T>
	inline void l_queue<T>::clear_queue() noexcept
	{
		d_list.clear_list();
		return;
	}

	template<typename T>
	inline bool l_queue<T>::is_not_empty() const noexcept
	{
		return d_list.is_not_empty();
	}

	template<typename T>
	inline unsigned l_queue<T>::queue_length() const noexcept
	{
		return d_list.list_length();
	}

	template<typename T>
	T& l_queue<T>::get_head() const noexcept
	{
		return d_list[0];
	}


	template<typename T>
	void l_queue<T>::en_queue(T object)
	{
		d_list.insert_front(std::forward<T>(object));
		return;
	}

	template<typename T>
	T l_queue<T>::de_queue()
	{
		return d_list.pop_back();
	}

	template<typename T>
	void l_queue<T>::queue_traverse(std::function<void(T& element)> func)
	{
		d_list.list_traverse(func);
		return;
	}
}

