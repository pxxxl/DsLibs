#pragma once

#include"settings.hpp"

namespace eds {

	template<typename T>
	class r_queue {
	public:
		r_queue(unsigned size) noexcept {
			queue_base = new T[size];
			handle_memory_alloc(queue_base);
			cap = size;
		};
		r_queue(unsigned size, std::initializer_list<T> list) {
			assert(size > list.size());
			queue_base = new T[size];
			handle_memory_alloc(queue_base);
			cap = size;
			unsigned i = 0;
			for (auto item:list) {
				queue_base[i] = item;
				i++;
			}
			return;

		};
		r_queue(const r_queue& sample) {
			queue_base = new T[sample.queue_cap()];
			handle_memory_alloc(queue_base);
			cap = sample.queue_cap();
			int head_s = sample.head;
			int tail_s = sample.tail;
			for (; tail_s != head_s;) {
				queue_base[tail_s] = sample.queue_base[tail_s];
				tail_s = (tail_s + 1) % cap;
			}
		}
		r_queue(r_queue&& sample) {
			queue_base = sample.queue_base;
			sample.queue_base = nullptr;
			cap = sample.cap;
			head = sample.head;
			tail = sample.tail;
			sample.clear_queue();
		}

		//clear the queue
		void clear_queue() noexcept;

		//if queue is not empty, return true
		bool is_not_empty() const noexcept;

		//return the cap of the queue
		unsigned queue_cap() const noexcept;

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
		T* queue_base = nullptr;
		int head = 0;
		int tail = 0;
		unsigned cap = 0;
	};

	template<typename T>
	inline void r_queue<T>::clear_queue() noexcept
	{
		cap = 0;
		head = 0;
		tail = 0;
	}

	template<typename T>
	inline bool r_queue<T>::is_not_empty() const noexcept
	{
		if (head == tail) {
			return false;
		}
		return true;
	}

	template<typename T>
	inline unsigned r_queue<T>::queue_cap() const noexcept
	{
		return cap;
	}

	template<typename T>
	inline unsigned r_queue<T>::queue_length() const noexcept
	{
		return (head-tail)%cap;
	}

	template<typename T>
	inline T& r_queue<T>::get_head() const
	{
		if (head == tail) {
			throw std::runtime_error("From eds::r_queue::get_head : queue empty");
		}
		return queue_base[head];
	}

	template<typename T>
	inline void r_queue<T>::en_queue(T object)
	{
		if ((head - tail) % cap == cap - 1) {
			throw std::runtime_error("From eds::r_queue::en_queue : queue full");
		}
		head = (head + 1) % cap;
		queue_base[head] = object;
		return;
	}

	template<typename T>
	inline T r_queue<T>::de_queue()
	{
		if (head == tail) {
			throw std::runtime_error("From eds::r_queue:de_queue : queue empty");
		}
		auto form = tail;
		tail = (tail + 1) % cap;
		return queue_base[form];
	}

	template<typename T>
	inline void r_queue<T>::queue_traverse(std::function<void(T& element)> func)
	{
		for (int cur = tail; cur != head;cur = (cur+1)%cap) {
			func(queue_base[cur]);
		}
		func(queue_base[head]);
		return;
	}

}