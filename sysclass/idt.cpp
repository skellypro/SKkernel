/*
 * idt.cpp
 *
 *  Created on: Dec 27, 2023
 *      Author: sean
 */

#include<systemk/irq.h>

#include<systemk/arch/AMD64/idt.h>
#include<systemk/arch/AMD64/gdt.h>

__attribute__((noreturn))
void exception_handler() {
	hang:	asm volatile ("cli;"
							"hlt;"); // Completely hangs the computer
	goto hang;
}

idt::idt(){
	init();
}
void idt::set_descriptor(uint8_t vector, void * isr, uint8_t flags) {
	idt_entry_t* descriptor	=	&table[vector];

	descriptor->isr_low		=	(uint64_t)isr & 0xFFFF;
	descriptor->kernel_cs	=	GDT_OFFSET_KERNEL_CODE;
	descriptor->ist			=	0;
	descriptor->attributes	=	flags;
	descriptor->isr_mid		=	((uint64_t)isr >> 16) & 0xFFFF;
	descriptor->isr_high	=	((uint64_t)isr >> 32) & 0xFFFFFFFF;
	descriptor->reserved	=	0;
}

void idt::init(){
	idtr.base = (uintptr_t)&table[0];
	idtr.limit = (uint16_t)sizeof(idt_entry_t) * IDT_MAX_DESCRIPTORS - 1;

	for (uint8_t vector = 0; vector < 32; vector++) {
			set_descriptor(vector, isr_stub_table[vector], 0x8E);
			vectors[vector] = true;
	}

	asm volatile ("lidt %0" : : "m"(idtr)); // load the new IDT
	asm volatile ("sti"); // set the interrupt flag
}
