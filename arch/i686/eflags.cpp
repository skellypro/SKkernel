/*
 * eflags.cpp
 *
 *  Created on: Nov 21, 2024
 *      Author: sean
 * Last Change:	Apr 28, 2025
 *
 * Description:	Class to handle the EFLAGS register.
 * 	This class has a built in mechanism to prevent
 * the interrupt flag (EFLAGS.int) from raising without
 * an IDT. This class is also designed to not leak the
 * value of the EFLAGS register.  The EFLAGS class
 * prevents leaks about the system state
 * by not using any data members.
 *
 */

#include<stddef.h>
#include<stdint.h>

#include<systemk/arch/i686/eflags.h>

namespace assembly {

	eflags_C::eflags_C() {}

	eflags_C::~eflags_C(){}

	int eflags_C::gettf() {
		register eflags_t temp;
		temp.value = getEFLAGS();
		return temp.tf;
	}

	int eflags_C::getiopl() {
		register eflags_t temp;
		temp.value = getEFLAGS();
		return temp.iopl;
	}

	int eflags_C::getnt() {
		register eflags_t temp;
		temp.value = getEFLAGS();
		return temp.intf;
	}

	int eflags_C::getrf() {
		register eflags_t temp;
		temp.value = getEFLAGS();
		return temp.rf;
	}
	int eflags_C::getvm() {
		register eflags_t temp;
		temp.value = getEFLAGS();
		return temp.vm;
	}

	int eflags_C::getac() {
		register eflags_t temp;
		temp.value = getEFLAGS();
		return temp.ac;
	}

	int eflags_C::getvif() {
		register eflags_t temp;
		temp.value = getEFLAGS();
		return temp.vif;
	}

	int eflags_C::getvip() {
		register eflags_t temp;
		temp.value = getEFLAGS();
		return temp.vip;
	}

	int eflags_C::getid() {
		register eflags_t temp;
		temp.value = getEFLAGS();
		return temp.id;
	}

	int eflags_C::settf(register uint8_t newTF= -1) {
		if(newTF > -1) {
			register eflags_t temp;
			temp.tf = newTF;
			setEFLAGS(temp);
		}
		return newTF;
	}

	int eflags_C::setiopl(register uint8_t newIOPL = -1) {
		if(newIOPL > -1) {
			register eflags_t temp;
			temp.tf = newIOPL;
			setEFLAGS(temp);
		}
		return newIOPL;
	}

	int eflags_C::setnt(register uint8_t newNT = -1) {
		if(newNT > -1) {
			register eflags_t temp;
			temp.tf = newNT;
			setEFLAGS(temp);
		}
		return newNT;
	}

	int eflags_C::setrf(register uint8_t newRF = -1) {
		if(newRF > -1) {
			register eflags_t temp;
			temp.tf = newRF;
			setEFLAGS(temp);
		}
		return newRF;
	}

	int eflags_C::setvm(register uint8_t newVM= -1) {
		if(newVM > -1) {
			register eflags_t temp;
			temp.tf = newVM;
			setEFLAGS(temp);
		}
		return newVM;
	}

	int eflags_C::setac(register uint8_t newAC = -1) {
		if(newAC > -1) {
			register eflags_t temp;
			temp.tf = newAC;
			setEFLAGS(temp);
		}
		return newAC;
	}

	int eflags_C::setvif(register uint8_t newVIF= -1) {
		return -1;
	}

	int eflags_C::setvip(register uint8_t newVIP = -1) {
		if(newVIP > -1) {
			register eflags_t temp;
			temp.tf = newVIP;
			setEFLAGS(temp);
		}
		return newVIP;
	}

	int eflags_C::setid(register uint8_t newID = -1) {
		if(newID > -1) {
			register eflags_t temp;
			temp.tf = newID;
			setEFLAGS(temp);
		}
		return newID;
	}

	/*
	int eflags_C::sti() {
		register int r = 1;
		if(IDTset())
			__asm__ volatile ("sti");
		else
			r--;
		return r;
	}
	*/

	/*
	void eflags_C::cli() {
		__asm__ volatile("cli");
	}
	*/

	int eflags_C::getintf() {
		register eflags_t temp;
		temp.value = getEFLAGS();
		return temp.intf;
	}


	/*
	uint32_t eflags_C::getEFLAGS() {
		register uint32_t flags;
		__asm__ volatile ("pushf"
			"pop %0"
			:"=r"(flags):);
		return flags;
	}
	 */

	/*
	void eflags_C::setEFLAGS(register const eflags_t * newEFLAGS) {
		if(newEFLAGS->intf && !IDTset())
			return;

		__asm__ volatile ("load [%0] %eax"
				"push %eax"
				"popf"
				::"m"(newEFLAGS));
	}
	*/

	/*
	bool eflags_C::IDTset() {
		register bool re;
		__asm__ volatile("mov %idtr %0"
				//"store %eax %0"
				:"=r" ((int)re):);
		return re;
	}
	*/

}
