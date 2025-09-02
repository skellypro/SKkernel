/*
 * idt.h
 *
 *  Created on: Apr 22, 2024
 *      Author: sean
 */

#ifndef INCLUDE_ARCH_I686_IDT_H_
#define INCLUDE_ARCH_I686_IDT_H_

#include<stddef.h>
#include<stdint.h>

#define IDT_MAX_DESCRIPTORS 256

typedef struct {
	uint16_t    isr_low;      // The lower 16 bits of the ISR's address
	uint16_t    kernel_cs;    // The GDT segment selector that the CPU will load into CS before calling the ISR
	uint8_t     reserved;     // Set to zero
	uint8_t     attributes;   // Type and attributes; see the IDT page
	uint16_t    isr_high;     // The higher 16 bits of the ISR's address
} __attribute__((packed)) idt_entry_t;

typedef struct {
	uint16_t	limit;
	/*uint32_t*/ void *	base;
} __attribute__((packed)) idtr_t;

class idt{
public:
	idt();
	void set_descriptor(uint8_t vector, void* isr, uint8_t flags);
private:
	void init();
	__attribute__((aligned(0x10)))
	idt_entry_t	table[IDT_MAX_DESCRIPTORS];

	idtr_t idtr;

	void* isr_stub_table[];

	void lidtr();
};

#endif /* INCLUDE_ARCH_I686_IDT_H_ */
