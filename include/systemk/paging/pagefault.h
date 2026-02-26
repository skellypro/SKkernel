#pragma once

#include <exception>

#ifdef AMD64 || x86_64
#include <systemk/arch/AMD64/cr2.h>
#elifdef i686 || x86
#include <systemk/arch/i686/cr2.h>

using std::exception;

typedef struct alignas(sizeof(unsigned long long)) _page_fault_error_code_struct {
	union {
			struct {
			unsigned p : 1;
			unsigned w : 1;
			unsigned u : 1;
			unsigned resrvedwrite : 1;
			unsigned i : 1;
			unsigned pk : 1;
			unsigned ss : 1;
			unsigned : 7;
			unsigned sgx : 1;
		};
		unsigned long long value;

	};
} page_fault_code;

class page_fault_exception : public exception {
public:
	page_fault_exception(unsigned p, unsigned long long c) : exception()
<<<<<<< HEAD
	: pid(p), addr(sk::arch::cr2.getPFVA()), code.value(c) {}
=======
	: pid(p), addr(a), code.value(arch::cr2.getPFVA()) {}
>>>>>>> f2a416e3daddc50119886e134e18e81951fefa8e
	unsigned get_pid() {
		return pid;
	}
	void* get_addr() {
		return addr;
	}
	page_fault_code get_code() {
		return code;
	}
private:
	unsigned pid;
	void* addr;
	page_fault_code code;
};