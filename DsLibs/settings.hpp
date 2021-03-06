#pragma once

#include<tuple>
#include<functional>
#include<optional>
#include<assert.h>
#include<stdexcept>
#include<stdio.h>
#include<iostream>

namespace eds_m {

	constexpr int FATAL = -1;

	class null_class{};
}

namespace eds {

	template<typename T>
	struct l_node {
		T data;
		l_node<T>* next = nullptr;
	};

	using status = int;

	constexpr int OK = 1;
	constexpr int INFEASIBLE = -1;

	inline void handle_memory_alloc(void* point_to_allocated_memory) {
		assert(!(point_to_allocated_memory == nullptr));
	}

	template<typename T>
	inline constexpr bool is_decimal(const double& v)
	{
		return true;
	}
	template<typename T>
	inline constexpr bool is_decimal(const float& v)
	{
		return true;
	}
	template<typename T>
	inline constexpr bool is_decimal(const long double& v)
	{
		return true;
	}
	template<typename T>
	inline constexpr bool is_decimal(const T& v)
	{
		return false;
	}

	template<typename T>
	inline constexpr bool is_integer(const int& v)
	{
		return true;
	}
	template<typename T>
	inline constexpr bool is_integer(const short& v)
	{
		return true;
	}
	template<typename T>
	inline constexpr bool is_integer(const long& v)
	{
		return true;
	}
	template<typename T>
	inline constexpr bool is_integer(const char& v)
	{
		return true;
	}
	template<typename T>
	inline constexpr bool is_integer(const long long& v)
	{
		return true;
	}
	template<typename T>
	inline constexpr bool is_integer(const T& v)
	{
		return false;
	}
	inline bool is_zero(double a) {
		if (a > -10E-6 && a < 10E-6) {
			return true;
		}
		else {
			return false;
		}
	}

	template<typename T>
	inline void swap(T& a, T& b) {
		T hold = a;
		a = b;
		b = hold;
		return;
	}

	template<typename T>
	inline const T& max(const T& a, const T& b) {
		if (a >= b) {
			return a;
		}
		else {
			return b;
		}
	}


}


