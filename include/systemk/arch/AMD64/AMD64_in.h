/*
 * AMD64_in.h
 *
 *  Created on: Mar 20, 2024
 *      Author: sean
 */

#pragma once

#include<stddef.h>
#include<stdint.h>

#include<systemk/arch/i686/i686_in.h>

#ifndef AMD64
#define AMD64
#endif

namespace sk {
	namespace arch {
		// This might not be right.  Look more into the in instructions
		__attribute__((always_inline))
			static inline uint64_t inQ(uint16_t src) {
			uint64_t val;
			asm volatile("mov %1, %dx"
				"in %rax, %dx"
				"mov %rax, %0"
				:"r"(val) : "r"(src));
			return val;
		}

	}
}