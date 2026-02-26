#pragma once

#include <exception>

#ifdef AMD64 || x86_64
#include <systemk/arch/AMD64/cr2.h>
#include <systemk/arch/AMD64/exceptions.h>
#elifdef i686 || x86
#include <systemk/arch/i686/cr2.h>
#include <systemk/arch/i686/exceptions.h>
#endif

using std::exception;


class page_fault_exception : public exception {
public:
	page_fault_exception(unsigned p, unsigned long long c, void * a = sk::arch::cr2.getPFVA())
	: pid(p), addr(a), code.value(c) {}
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