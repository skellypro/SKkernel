/*
 * asm_out.h
 *
 *  Created on: Mar 11, 2024
 *      Author: sean
 */

#pragma once

#ifndef AMD64
#define AMD64
#endif

#include<stddef.h>
#include<stdint.h>

#include<systemk/arch/i686/i686_out.h>

namespace sk {
	namespace arch {

		__attribute__((always_inline))
			static inline uint64_t outQ(uint64_t val, uint16_t dest) {
			asm volatile("outq %q0, %w1" : : "a"(val), "nD"(dest) : "memory");
			return dest;
		}

	}
}