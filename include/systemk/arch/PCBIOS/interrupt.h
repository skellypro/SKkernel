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

/***************************************************
 * This function is VERY DANGEROUS!!!
 * There is no handling used in this implementation.
 * This is intended to be used in an object that
 * handles interrupts. The parameters assume the
 * caller has set up registers and memory properly.
 */
[[always_inline]]
inline uint16_t basic_interrupt(uint16_t i,
							uint16_t ax,
							uint16_t bx,
							uint16_t cx,
							uint16_t dx,
							void * si,
							void * di) {
	asm volatile (
		"int %1\n"
		: "=a"(ax)
		: "g"(i), "a"(ax), "b"(bx), "c"(cx), "d"(dx), "s"(si), "D"(di)
		: "memory");
	return ax;
}