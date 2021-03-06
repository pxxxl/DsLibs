#pragma once

#include"settings.hpp"

namespace eds {

template<typename T>
class intf_queue {
public:
	//clear the queue
	virtual void clear_queue() noexcept = 0;

	//if queue is not empty, return true
	virtual bool is_not_empty() const noexcept = 0;

	//return the cap of the queue
	virtual unsigned queue_cap() const noexcept = 0;

	//return the length of the queue
	unsigned queue_length() const noexcept;

	//get the head element of the queue
	virtual T& get_head() const = 0;

	//object enter the queue
	virtual void en_queue(T object) = 0;

	//object get out of the queue
	virtual T de_queue() = 0;

	//call func(element) on each elements in the queue
	virtual void queue_traverse(std::function<void(T& element)> func) = 0;

	//destructor
	virtual ~intf_queue() {};
};
}