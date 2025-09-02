/*
 * interrupt_frame.h
 *
 *  Created on: Jan 8, 2024
 *      Author: sean
 */

#ifndef INCLUDE_ARCH_AMD64_INTERRUPT_FRAME_H_
#define INCLUDE_ARCH_AMD64_INTERRUPT_FRAME_H_

#include<stdint.h>

struct interrupt_frame {
	uint64_t rip;
	uint64_t cs;
	uint64_t rflags;
	uint64_t rsp;
	uint64_t ss;
};

#endif /* INCLUDE_ARCH_AMD64_INTERRUPT_FRAME_H_ */
