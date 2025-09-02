/*
 * AMD64_in.h
 *
 *  Created on: Mar 20, 2024
 *      Author: sean
 */

#ifndef INCLUDE_ARCH_AMD64_AMD64_IN_H_
#define INCLUDE_ARCH_AMD64_AMD64_IN_H_

#include<stddef.h>
#include<stdint.h>

#include<arch/i686/i686_in.h>

#ifndef AMD64
#define AMD64
#endif

namespace assembly {
	// This might not be right.  Look more into the in instructions
	__attribute__((always_inline))
	static inline uint64_t inQ(uint16_t src){
		uint64_t val;
		asm volatile("mov %1, %dx"
					 "in %rax, %dx"
					 "mov %rax, %0"
					:"r"(val):"r"(src));
		return val;
	}

}

#endif /* INCLUDE_ARCH_AMD64_AMD64_IN_H_ */
