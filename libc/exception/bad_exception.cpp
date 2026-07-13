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