/*
 * exception/lib.cpp
 *
 *  Created on: Jul 12, 2026
 *      Author: sean
 *
 * Description:	Standard exception handler library implementation.
 */
#include <exception>

#include <cstdlib>

namespace std {
	[[noreturn]] void terminate() noexcept {
		abort();
	}

	terminate_handler get_terminate() noexcept {
	}

	terminate_handler set_terminate(terminate_handler f) noexcept {
	}

	[[noreturn]] void unexpected() {
	}

	unexpected_handler get_unexpected() noexcept {
	}

	unexpected_handler set_unexpected(unexpected_handler f) noexcept {
	}

	bool uncaught_exception() noexcept {
		
	}

	exception_ptr current_exception() noexcept {
		return nullptr;
	}

	[[noreturn]] void rethrow_exception(exception_ptr p) {
	}

	template <class E>
	exception_ptr make_exception_ptr(E e) noexcept {
		return reinterpret_cast<exception_ptr>(new E(e));
	}

	[[noreturn]] template <class T>
	void throw_with_nested(T&& e) {
	}

	template <class T>
	void rethrow_if_nested(const T& e) {
	}
}