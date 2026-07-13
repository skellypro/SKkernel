#include <exception>

namespace std {
	exception::exception() throw()
	{
		
	}

	exception::exception(const exception& other) throw()
	{
		*this = other;
	}

	exception& exception::operator= (const exception & other) throw() {
		if (this != &other) {
			// Nothing to assign yet.
		}
		return *this;
	}

	virtual exception::~exception() throw() {
		
	}

	virtual const char* exception::what() const throw() {
		return "std::exception";
	}
}