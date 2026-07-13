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