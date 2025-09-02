/*
 * gdt.cpp
 *
 *  Created on: Mar 27, 2024
 *      Author: sean
 */

#include<stddef.h>

#include<systemk/arch/AMD64/gdt.h>

GDT::GDT() {
	table = gdt_entry_t();
	//load_gdt();
}

GDT::~GDT() {

}

void GDT::create_descriptor(uint32_t base, uint32_t limit, uint16_t flag){
	uint64_t descriptor = 0;

    // Create the high 32 bit segment
    descriptor  =  limit       & 0x000F0000;         // set limit bits 19:16
    descriptor |= (flag <<  8) & 0x00F0FF00;         // set type, p, dpl, s, g, d/b, l and avl fields
    descriptor |= (base >> 16) & 0x000000FF;         // set base bits 23:16
    descriptor |=  base        & 0xFF000000;         // set base bits 31:24

    // Shift by 32 to allow for low part of segment
    descriptor <<= 32;

    // Create the low 32 bit segment
    descriptor |= base  << 16;                       // set base bits 15:0
    descriptor |= limit  & 0x0000FFFF;               // set limit bits 15:0

    add_descriptor(descriptor);
}

void GDT::add_descriptor(uint64_t n) {
	/*
	uint8_t i = 0;
	while(table[i])
		i++;
	table[i] = n;*/
	table = (gdt_entry_t)n;
	load_gdt();
}

void GDT::load_gdt() {
	asm volatile ("lgdt %0" : :"o"(table));
}
