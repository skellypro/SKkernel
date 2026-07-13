#include <exception>

namespace std {
	nested_exception::nested_exception() throw() {

	}

	nested_exception::nested_exception(const nested_exception&) throw() {

	}

	nested_exception::nested_exception& operator= (const nested_exception&) throw() {

	}

	nested_exception::~nested_exception() throw() {

	}

	const char* nested_exception::what() const throw() {
		return "std::nested_exception";
	}
}