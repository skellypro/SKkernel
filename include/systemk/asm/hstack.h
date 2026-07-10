/*
 * hstack.h
 *
 *  Created on: Jul 6, 2026
 *      Author: sean
 * Description: Functions to push and pop off of the program stack.
 */

#pragma once

#include <stdint.h>

[[always_inline]]
inline void pushb(uint8_t v) {
	asm volatile (
		"pushb %0\n"
		:
		: "g"(v)
		: "memory");
}

[[always_inline]]
inline uint8_t popb() {
	uint8_t v;
	asm volatile (
		"popb %0\n"
		: "=g"(v)
		:
		: "memory");
	return v;
}

[[always_inline]]
inline void pushw(uint16_t v) {
	asm volatile (
		"pushw %0\n"
		:
	: "g"(v)
		: "memory");
}

[[always_inline]]
inline uint16_t popw() {
	uint16_t v;
	asm volatile (
		"popw %0\n"
		: "=g"(v)
		:
		: "memory");
	return v;
}

[[always_inline]]
inline void pushd(uint32_t v) {
	asm volatile (
		"pushd %0\n"
		:
	: "g"(v)
		: "memory");
}

[[always_inline]]
inline uint32_t popd() {
	uint32_t v;
	asm volatile (
		"popd %0\n"
		: "=g"(v)
		:
		: "memory");
	return v;
}

[[always_inline]]
inline void pushq(uint64_t v) {
	asm volatile (
		"pushq %0\n"
		:
	: "g"(v)
		: "memory");
}

[[always_inline]]
inline uint64_t popq() {
	uint64_t v;
	asm volatile (
		"popq %0\n"
		: "=g"(v)
		:
		: "memory");
	return v;
}