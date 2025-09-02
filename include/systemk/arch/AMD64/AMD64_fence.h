/*
 * fence.h
 *
 *  Created on: Mar 18, 2024
 *      Author: sean
 *
 *      Fence instructions for cache and memory management
 */

#ifndef INCLUDE_ARCH_AMD64_AMD64_FENCE_H_
#define INCLUDE_ARCH_AMD64_AMD64_FENCE_H_

#ifndef AMD64
#define AMD64
#endif

namespace assembly {

	__attribute__((always_inline))
	static inline void lfence(){
		asm volatile("lfence");
	}

	__attribute__((always_inline))
	static inline void sfence(){
		asm volatile("sfence");
	}

	__attribute__((always_inline))
	static inline void mfence(){
		asm volatile("mfence");
	}

}

#endif /* INCLUDE_ARCH_AMD64_AMD64_FENCE_H_ */
