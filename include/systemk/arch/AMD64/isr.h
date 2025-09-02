/*
 * isr.h
 *
 *  Created on: Jan 3, 2024
 *      Author: sean
 */

#ifndef INCLUDE_ARCH_AMD64_ISR_H_
#define INCLUDE_ARCH_AMD64_ISR_H_

#include<stdint.h>

#include<irq.h>

#include<arch/AMD64/interrupt_frame.h>

__attribute__((interrupt))
void interrupt_handler(interrupt_frame * frame);

#endif /* INCLUDE_ARCH_AMD64_ISR_H_ */
