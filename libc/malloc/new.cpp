/*
 * new.cpp
 *
 *  Created on: Jul 12, 2026
 *      Author: sean
 *
 * Description:	Implementation of operators new, and delete,
 *				And associated exception handlers.
 */
#include <new>

#include <cstdlib>

extern "C" {
	void* operator new(std::size_t size) {
		volatile void* temp;
		if (nullptr == (temp = malloc(size)))
			throw std::bad_alloc();
		return temp;
	}

	void* operator new(std::size_t size, void* ptr) noexcept {
		volatile void* temp;
		if (nullptr == (temp = realloc(ptr,size)))
			throw std::bad_alloc();
		return temp;
	}

	void* operator new(std::size_t size, const std::nothrow_t& nothrow_value) noexcept {
		volatile void* temp;
		if (nullptr == (temp = malloc(size))){
			if (nothrow != nothrow_value)
				throw std::bad_alloc();
		}
		return temp;
	}

	void* operator new[](std::size_t num, std::size_t size) {
		volatile void* temp;
		if (nullptr == (temp = calloc(num, size)))
			throw std::bad_alloc();
		return temp;
	}

	void* operator new[](std::size_t size, void* ptr) noexcept {
		volatile void* temp;
		if (nullptr == (temp = realloc(ptr,size)))
			throw std::bad_array_new_length();
		return temp;
	}

	void* operator new[](std::size_t size, const std::nothrow_t& nothrow_value) noexcept {
		volatile void* temp;
		if (nullptr == (temp = malloc(size)))
			if (nothrow != nothrow_value)
				throw std::bad_alloc();
		return temp;
	}

	void operator delete(void* old) noexcept {
		try {
			free(old);
		} catch (...) {
			throw std::bad_alloc();
		}
	}

	// Placement delete. This will always do nothing, as per the C++ standard.
	void operator delete(void* ptr, void* voidptr2) noexcept {
	}

	void operator delete(void* ptr, const std::nothrow_t& nothrow_constant) noexcept {
		try {
			free(old);
		} catch (...) {
			if (nothrow != nothrow_constant)
				throw std::bad_alloc();
		}

	}

	void operator delete[](void* old) noexcept {
		try {
			free(old);
		} catch (...) {
			throw std::bad_alloc();
		}
	}

	// Placement delete. This will always do nothing, as per the C++ standard.
	void operator delete[](void* ptr, void* voidptr2) noexcept {
	}

	void operator delete[](void* ptr, const std::nothrow_t& nothrow_constant) noexcept {
		try {
			free(old);
		} catch (...) {
			if (nothrow != nothrow_constant)
				throw std::bad_alloc();
		}
	}
}

namespace std {

	bad_alloc::bad_alloc() noexcept {
	}

	bad_alloc::bad_alloc(const bad_alloc&) noexcept {
	}

	bad_alloc& bad_alloc::operator=(const bad_alloc&) noexcept {
	}

	bad_alloc::~bad_alloc() {
	}

	const char* bad_alloc::what() const noexcept override {
		return "std::bad_alloc";
	}

	bad_array_new_length::bad_array_new_length() noexcept {
	}

	bad_array_new_length::bad_array_new_length(const bad_array_new_length&) noexcept {
	}

	bad_array_new_length::bad_array_new_length& operator=(const bad_array_new_length&) noexcept {
	}

	bad_array_new_length::~bad_array_new_length() {
	}

	const char* bad_array_new_length::what() const noexcept override {
		return "std::bad_array_new_length";
	}

	// TODO: Implement these functions :)
	new_handler set_new_handler(new_handler new_p) noexcept {
		
	}

	new_handler get_new_handler() noexcept {

	}
}