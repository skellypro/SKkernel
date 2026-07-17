#pragma once

#include <stdint.h>

namespace sk {
	[[always_inline]] inline uint16_t get_si() {
		uint16_t x;
		asm volatile (
			"movw %si, %0\n"
			: "=a"(x)
			:
			: "memory");
		return x;
	}

	[[always_inline]] inline uint32_t get_esi() {
		uint32_t x;
		asm volatile (
			"movl %esi, %0\n"
			: "=a"(x)
			:
			: "memory");
		return x;
	}


	[[always_inline]] inline uint64_t get_rsi() {
		uint32_t x;
		asm volatile (
			"movq %rsi, %0\n"
			: "=a"(x)
			:
			: "memory");
		return x;
	}

	[[always_inline]] inline uint16_t get_di() {
		uint16_t x;
		asm volatile (
			"movw %di, %0\n"
			: "=a"(x)
			:
			: "memory");
		return x;
	}

	[[always_inline]] inline uint32_t get_edi() {
		uint32_t x;
		asm volatile (
			"movl %edi, %0\n"
			: "=a"(x)
			:
			: "memory");
		return x;
	}

	[[always_inline]] inline uint64_t get_rdi() {
		uint64_t x;
		asm volatile (
			"movq %rdi, %0\n"
			: "=a"(x)
			:
			: "memory");
		return x;
	}
}