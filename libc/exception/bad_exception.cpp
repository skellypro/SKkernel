/*
 * bad_exception.cpp
 *
 *  Created on: Jul 12, 2026
 *      Author: sean
 *
 * Description:	Bad exception class implementation.
 */
#include <exception>

namespace std {
	bad_exception::bad_exception() throw() {

	}

	bad_exception::bad_exception(const bad_exception&) throw() {

	}

	bad_exception& bad_exception::operator= (const bad_exception&) throw() {

	}

	bad_exception::~bad_exception() throw() {

	}

	const char* bad_exception::what() const throw() {
		return "std::bad_exception";
	}
}