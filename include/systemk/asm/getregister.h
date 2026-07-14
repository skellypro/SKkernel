#pragma once

#include <stdint.h>

[[always_inline]] inline uint16_t get_si() {
	uint16_t si;
	asm volatile (
		"mov %%si, %0\n"
		: "=a"(si)
		:
		: "memory");
	return si;
}

[[always_inline]] inline uint16_t get_di() {
	uint16_t di;
	asm volatile (
		"mov %%di, %0\n"
		: "=a"(di)
		:
		: "memory");
	return di;
}