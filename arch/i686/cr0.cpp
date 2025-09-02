/*
 * cr0.cpp
 *
 *  Created on: Nov 22, 2024
 *      Author: sean
 * Last Change:	Dec 16, 2024
 *
 * Description:	Describe cr0.cpp here
 */

#include<stddef.h>
#include<stdint.h>
#include<stdbool.h>

#include<systemk/arch/i686/cr0.h>

namespace assembly {

	i686_cr0_C::i686_cr0_C(){}

	bool i686_cr0_C::getpe() {
		register i686_cr0_t cr0;
		cr0.value = getCR0();
		return cr0.pe;
	}

	bool i686_cr0_C::getmp() {
		register i686_cr0_t cr0;
		cr0.value = getCR0();
		return cr0.mp;
	}

	bool i686_cr0_C::getem() {
		register i686_cr0_t cr0;
		cr0.value = getCR0();
		return cr0.em;
	}

	bool i686_cr0_C::getts() {
		register i686_cr0_t cr0;
		cr0.value = getCR0();
		return cr0.ts;
	}

	bool i686_cr0_C::getet() {
		register i686_cr0_t cr0;
		cr0.value = getCR0();
		return cr0.et;
	}

	bool i686_cr0_C::getne() {
		register i686_cr0_t cr0;
		cr0.value = getCR0();
		return cr0.ne;
	}

	bool i686_cr0_C::getwp() {
		register i686_cr0_t cr0;
		cr0.value = getCR0();
		return cr0.wp;
	}

	bool i686_cr0_C::getam() {
		register i686_cr0_t cr0;
		cr0.value = getCR0();
		return cr0.am;
	}

	bool i686_cr0_C::getnw() {
		register i686_cr0_t cr0;
		cr0.value = getCR0();
		return cr0.nw;
	}

	bool i686_cr0_C::getcd() {
		register i686_cr0_t cr0;
		cr0.value = getCR0();
		return cr0.cd;
	}

	bool i686_cr0_C::getpg() {
		register i686_cr0_t cr0;
		cr0.value = getCR0();
		return cr0.pg;
	}

	int i686_cr0_C::setpe(register uint8_t newpe = -1) {
		register i686_cr0_t cr0;
		register bool condition = newpe > -1 && GDTset() && protectedIDTset();
		if(condition){
			cr0.value = getCR0();
			cr0.pe = newpe;
			setCR0(cr0.value);
		}
		return cr0.pe;
	}

	int i686_cr0_C::setmp(register uint8_t newmp = -1) {
		register i686_cr0_t cr0;
		if(newmp > -1) {
			cr0.value = getCR0();
			cr0.mp = newmp;
			setCR0(cr0.value);
		}
		return newmp;
	}

	int i686_cr0_C::setem(register uint8_t newem = -1) {
		register i686_cr0_t cr0;
		if(newem > -1){
			cr0.value = getCR0();
			cr0.em = newem;
			setCR0(cr0.value);
		}
		return newem;
	}

	int i686_cr0_C::setts(register uint8_t newts = -1) {
		register i686_cr0_t cr0;
		if(newts > -1) {
			cr0.value = getCR0();
			cr0.ts = newts;
			setCR0(cr0.value);
		}
		return newts;
	}

	void i686_cr0_C::clts() {
		__asm__ volatile ("clts");
	}

	int i686_cr0_C::setet(register uint8_t newet = -1) {
		register i686_cr0_t cr0;
		if(newet > -1) {
			cr0.value = getCR0();
			cr0.et = newet;
			setCR0(cr0.value);
		}
		return newet;
	}

	int i686_cr0_C::setne(register uint8_t newne = -1) {
		register i686_cr0_t cr0;
		if(newne > -1) {
			cr0.value = getCR0();
			cr0.ne = newne;
			setCR0(cr0.value);
		}
		return newne;
	}

	int i686_cr0_C::setwp(register uint8_t newwp = -1) {
		register i686_cr0_t cr0;
		if(newwp > -1) {
			cr0.value = getCR0();
			cr0.wp = newwp;
			setCR0(cr0.value);
		}
		return newwp;
	}

	int i686_cr0_C::setam(register uint8_t newam = -1) {
		register i686_cr0_t cr0;
		if(newam > -1) {
			cr0.value = getCR0();
			cr0.am = newam;
			setCR0(cr0.value);
		}
		return newam;
	}

	int i686_cr0_C::setnw(register uint8_t newnw = -1) {
		register i686_cr0_t cr0;
		if(newnw > -1) {
			cr0.value = getCR0();
			cr0.nw = newnw;
			setCR0(cr0.value);
		}
		return newnw;
	}

	int i686_cr0_C::setcd(register uint8_t newcd = -1) {
		register i686_cr0_t cr0;
		if(newcd > -1) {
			cr0.value = getCR0();
			cr0.cd = newcd;
			setCR0(cr0.value);
		}
		return newcd;
	}

	int i686_cr0_C::setpg(register uint8_t newpg = -1) {
		return -1;
	}


	uint32_t i686_cr0_C::getCR0() {
		register uint32_t temp;
		__asm__ volatile ("mov %cr0, %0"
				:"=r" (temp));
		return temp;
	}

	void i686_cr0_C::setCR0(register uint32_t newCR0) {
		__asm__ volatile("mov %0, cr0" : :(newCR0));
	}


	bool i686_cr0_C::GDTset() {
		register unsigned int temp;
		__asm__ volatile ("movd %gdtr, %0"
				:"=r" (temp));
		return temp;
	}

	bool i686_cr0_C::protectedIDTset() {
		return -1;
	}


}
