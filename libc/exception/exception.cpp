#include <exception>

namespace std {
	exception::exception() noexcept
	{

	}

	exception::exception(const exception& other) noexcept
	{
		*this = other;
	}

	exception& exception::operator= (const exception& other) noexcept {
		if (this != &other) {
			// Nothing to assign yet.
		}
		return *this;
	}

	virtual exception::~exception() noexcept {

	}

	virtual const char* exception::what() const noexcept {
		return "std::exception";
	}
}