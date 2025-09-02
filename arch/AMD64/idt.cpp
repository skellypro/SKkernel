/*
 * idt.cpp
 *
 *  Created on: May 6, 2024
 *      Author: sean
 * Last Change:	Dec 16, 2024
 */

#include<systemk/arch/AMD64/idt.h>

idt::idt() {
	idtr.base = &table;
	idtr.limit = IDT_MAX_DESCRIPTORS;
	//this->lidtr();
}

void idt::set_descriptor(uint8_t vector, void* isr, uint8_t flags) {


}

void idt::lidtr() {
	asm volatile ("cli");
	asm volatile ("lidt %0": : "m" (idtr) : );
	asm volatile ("sti");
}

void exception_handler(void) __attribute__((noreturn)) {
	asm volatile ("cli");
	asm volatile ("hlt");
}
