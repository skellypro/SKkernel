/*
 * fence.h
 *
 *  Created on: Mar 18, 2024
 *      Author: sean
 *
 *      Fence instructions for cache and memory management
 */

#pragma once

#ifndef AMD64
#define AMD64
#endif
namespace systemk {
	namespace arch {

		[[gnu::always_inline]]
			static inline void lfence() {
			asm volatile("lfence");
		}

		[[gnu::always_inline]]
			static inline void sfence() {
			asm volatile("sfence");
		}

		[[gnu::always_inline]]
			static inline void mfence() {
			asm volatile("mfence");
		}

	}
}
