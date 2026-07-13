#include <new>

#include <cstdlib>

extern "C" {
	void* operator new(std::size_t size) {
		void* temp;
		try {
			temp = malloc(size);
		} catch (std::bad_alloc& e) {
			throw e;
		}
		return temp;
	}

	void* operator new(std::size_t size, void* ptr) noexcept {
		void* temp;
		try {
			temp = realloc(ptr, size);
		} catch (std::bad_alloc& e) {
			throw e;
		}
		return temp;
	}

	void* operator new(std::size_t size, const std::nothrow_t& nothrow_value) noexcept {
		void* temp;
		try {
			temp = malloc(size);
		}
		catch (std::bad_alloc& e) {
			if (nothrow_value) {
				return nullptr;
			}
			throw e;
		}
		return temp;
	}

	void* operator new[](std::size_t num, std::size_t size) {
		void* temp;
		try {
			temp = calloc(num, size);
		}
		catch (std::bad_alloc& e) {
			throw e;
		}
		return temp;
	}

	void* operator new[](std::size_t size, void* ptr) noexcept {
		void* temp;
		try {
			temp = realloc(ptr, size);
		} catch (std::bad_alloc& e) {
			throw e;
		} catch (std::bad_array_new_length& e) {
			throw e;
		}
		return temp;
	}

	void* operator new[](std::size_t size, const std::nothrow_t& nothrow_value) noexcept {
		void* temp;
		try {
			temp = calloc(num, size);
		}
		catch (std::bad_alloc& e) {
			if (nothrow_value) {
				return nullptr;
			}
			throw e;
		}
		return temp;
	}

	void operator delete(void* old) noexcept {
		try {
			free(old);
		}
		catch (std::bad_alloc& e) {
			throw e;
		}
	}

	void operator delete(void* ptr, void* voidptr2) noexcept {
	}

	void operator delete(void* ptr, const std::nothrow_t& nothrow_constant) noexcept {
		try {
			free(old);
		}
		catch (std::bad_alloc& e) {
			if (nothrow_constant);
			else
				throw e;
		}
	}

	void operator delete[](void* old) noexcept {
		try {
			free(old);
		}
		catch (std::bad_alloc& e) {
			throw e;
		}
	}

	void operator delete[](void* ptr, void* voidptr2) noexcept {
	}

	void operator delete[](void* ptr, const std::nothrow_t& nothrow_constant) noexcept {
		try {
			free(old);
		}
		catch (std::bad_alloc& e) {
			if (nothrow_constant);
			else
				throw e;
		}
	}
}

namespace std {

	bad_alloc::bad_alloc() noexcept {
	}

	bad_alloc::bad_alloc(const bad_alloc&) noexcept {
	}

	bad_alloc& bad_alloc::operator= (const bad_alloc&) noexcept {
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

	bad_array_new_length::bad_array_new_length& operator= (const bad_array_new_length&) noexcept {
	}

	bad_array_new_length::~bad_array_new_length() {
	}

	const char* bad_array_new_length::what() const noexcept override {
		return "std::bad_array_new_length";
	}

	new_handler set_new_handler(new_handler new_p) noexcept {
		
	}

	new_handler get_new_handler() noexcept {

	}
}