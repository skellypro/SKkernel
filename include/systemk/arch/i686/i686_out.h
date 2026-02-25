/*
 * i386_out.h
 *
 *  Created on: Mar 18, 2024
 *      Author: sean
 */

#pragma once

#include<stddef.h>
#include<stdint.h>

#ifndef AMD64 || i686
#define i686
#endif

// TODO: fix this fucky shit
namespace sk {
	namespace arch {

		__attribute__((always_inline))
			static inline uint8_t outB(uint8_t val, uint8_t dest) {
			asm volatile("outb %b0, %w1" : : "a"(val), "nD"(dest) : "memory");
			return dest;
		}

		__attribute__((always_inline))
			static inline uint16_t outW(uint16_t val, uint16_t dest) {
			asm volatile("outw %w0, %w1" : : "a"(val), "nD"(dest) : "memory");
			return dest;
		}

		__attribute__((always_inline))
			static inline uint32_t outD(uint32_t val, uint16_t dest) {
			asm volatile("outd %d0, %w1" : : "a"(val), "nD"(dest) : "memory");
			return dest;
		}

	}
}