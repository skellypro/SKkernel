/*
 * nested_exception.cpp
 *
 *  Created on: Jul 12, 2026
 *      Author: sean
 *
 * Description:	Nested exception class implementation.
 */
#include <exception>

namespace std {
	nested_exception::nested_exception() noexcept {

	}

	nested_exception::nested_exception(const nested_exception&) noexcept {

	}

	nested_exception::nested_exception& operator= (const nested_exception&) noexcept {

	}

	nested_exception::~nested_exception() noexcept {

	}

	const char* nested_exception::what() const noexcept {
		return "std::nested_exception";
	}
}