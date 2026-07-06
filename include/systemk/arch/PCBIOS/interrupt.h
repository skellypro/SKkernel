/*
 * interrupt.h
 *
 *  Created on: Jul 5, 2026
 *      Author: sean
 * Description: Interrupt interface for the IBM PC BIOS, PC Complaint BIOS, and PS/2 BIOS.
 *				Use this for interrupts instead of an assembly injection.
 */

#pragma once

#include <stdint.h>

#include "interrupts.h"

[[always_inline]]
inline uint16_t basic_interrupt(uint16_t i,
							uint8_t ah,
							uint8_t al,
							uint16_t bx,
							uint16_t cx,
							uint16_t dx,
							uint16_t si,
							uint16_t di) {
	uint16_t ax = (ah << 8) | al;
	asm volatile (
		"int %1\n"
		: "=a"(ax)
		: "g"(i), "a"(ax), "b"(bx), "c"(cx), "d"(dx), "s"(si), "D"(di)
		: "memory");
	return ax;
}