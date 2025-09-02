/*
 * cr0.cpp
 *
 *  Created on: Dec 16, 2024
 *      Author: sean
 * Last Change:	Feb 5, 2025
 *
 * Description:	Describe cr0.cpp here
 */

#include<stddef.h>
#include<stdint.h>

#include<systemk/arch/AMD64/cr0.h>

namespace assembly {
	bool AMD64_cr0_C::getpe() {
		register AMD64_cr0_t cr0;
		cr0.v = getCR0();
		return cr0.cr0.pe;
	}
	bool AMD64_cr0_C::getmp() {
		register AMD64_cr0_t cr0;
		cr0.v = getCR0();
		return cr0.cr0.mp;
	}
	bool AMD64_cr0_C::getem() {
		register AMD64_cr0_t cr0;
		cr0.v = getCR0();
		return cr0.cr0.mp;
	}
	bool AMD64_cr0_C::getts() {
		register AMD64_cr0_t cr0;
		cr0.v = getCR0();
		return cr0.cr0.ts;
	}
	bool AMD64_cr0_C::getet() {
		register AMD64_cr0_t cr0;
		cr0.v = getCR0();
		return cr0.cr0.et;
	}
	bool AMD64_cr0_C::getne() {
		register AMD64_cr0_t cr0;
		cr0.v = getCR0();
		return cr0.cr0.ne;
	}
	bool AMD64_cr0_C::getwp() {
		register AMD64_cr0_t cr0;
		cr0.v = getCR0();
		return cr0.cr0.wp;
	}
	bool AMD64_cr0_C::getam() {
		register AMD64_cr0_t cr0;
		cr0.v = getCR0();
		return cr0.cr0.am;
	}
	bool AMD64_cr0_C::getnw() {
		register AMD64_cr0_t cr0;
		cr0.v = getCR0();
		return cr0.cr0.nw;
	}
	bool AMD64_cr0_C::getcd() {
		register AMD64_cr0_t cr0;
		cr0.v = getCR0();
		return cr0.cr0.cd;
	}
	bool AMD64_cr0_C::getpg() {
		register AMD64_cr0_t cr0;
		cr0.v = getCR0();
		return cr0.cr0.pg;
	}

	int AMD64_cr0_C::setpe(register uint8_t newPE= -1) {
		register AMD64_cr0_t cr0;
		if(GDTset() &&  0 == newPE && 1 ==newPE) {
			//TODO
		}
		return 0;
	}
	int AMD64_cr0_C::setmp(register uint8_t = -1) {
		register AMD64_cr0_t cr0;
		return 0;
	}
	int AMD64_cr0_C::setem(register uint8_t = -1) {
		register AMD64_cr0_t cr0;
		return 0;
	}

	int AMD64_cr0_C::setts(register uint8_t = -1) {
		register AMD64_cr0_t cr0;
		return 0;
	}
	void AMD64_cr0_C::clts() {
		__asm__ volatile ("clts");
	}

	int AMD64_cr0_C::setet(register uint8_t = -1) {
		register AMD64_cr0_t cr0;
		return 0;
	}
	int AMD64_cr0_C::setne(register uint8_t = -1) {
		register AMD64_cr0_t cr0;
		return 0;
	}
	int AMD64_cr0_C::setwp(register uint8_t = -1) {
		register AMD64_cr0_t cr0;
		return 0;
	}
	int AMD64_cr0_C::setam(register uint8_t = -1) {
		register AMD64_cr0_t cr0;
		return 0;
	}
	int AMD64_cr0_C::setnw(register uint8_t = -1) {
		register AMD64_cr0_t cr0;
		return 0;
	}
	int AMD64_cr0_C::setcd(register uint8_t = -1) {
		register AMD64_cr0_t cr0;
		return 0;
	}
	int AMD64_cr0_C::setpg(register uint8_t = -1) {
		register AMD64_cr0_t cr0;
		return 0;
	}

	uint64_t AMD64_cr0_C::getCR0() {
		register uint64_t temp;
		__asm__ volatile ("movl %cr0, %0" :"=r"(temp) : :);
		return temp;
	}
	void AMD64_cr0_C::setCR0(register uint64_t newCR0) {
		__asm__ volatile ("movl %0, %cr0" : :r(newCRO) :);
	}

	bool AMD64_cr0_C::GDTset() {
		register uint64_t temp;
		__asm__ volatile ("movl %gdtr, %0" :"=r"(temp): :);
		return temp > 0;
	}
	bool AMD64_cr0_C::protectedIDTset() {
		return -1;
	}
}
