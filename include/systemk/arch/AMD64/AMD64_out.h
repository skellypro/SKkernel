/*
 * asm_out.h
 *
 *  Created on: Mar 11, 2024
 *      Author: sean
 */

#ifndef INCLUDE_ARCH_AMD64_AMD64_OUT_H_
#define INCLUDE_ARCH_AMD64_AMD64_OUT_H_

#ifndef AMD64
#define AMD64
#endif

#include<stddef.h>
#include<stdint.h>

#include<arch/i686/i686_out.h>

namespace assembly {

	__attribute__((always_inline))
	static inline uint64_t outQ(uint64_t val, uint16_t dest){
		asm volatile("outq %q0, %w1" : : "a"(val), "nD"(dest) : "memory");
		return dest;
	}

}

#endif /* INCLUDE_ARCH_AMD64_AMD64_OUT_H_ */
