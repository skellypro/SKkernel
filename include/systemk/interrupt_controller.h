/*
 * interrupt_controller.h
 *
 *  Created on: Apr 22, 2024
 *      Author: sean
 */

#ifndef INCLUDE_INTERRUPT_CONTROLLER_H_
#define INCLUDE_INTERRUPT_CONTROLLER_H_

#include<stddef.h>
#include<stdint.h>

#ifdef AMD64
#include<systemk/arch/AMD64/AMD64_io.h>
#include<systemk/arch/AMD64/ports.h>
#include<systemk/arch/AMD64/idt.h>
#else
#ifdef i686
#include<systemk/arch/i686/i686_io.h>
#include<systemk/arch/i686/ports.h>
#include<systemk/arch/i686/idt.h>
#endif

class interrupt_controller {
public:
private:
	idt interrupt_table;
};

#endif /* INCLUDE_INTERRUPT_CONTROLLER_H_ */
