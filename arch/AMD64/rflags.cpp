/*
 * RFLAGS.cpp
 *
 *  Created on: Mar 25, 2025
 *      Author: sean
 * Last Change:	Apr 28, 2025
 *
 * Description:	Describe RFLAGS.cpp here
 */

#include<stddef.h>
#include<stdint.h>

#include<systemk/arch/AMD64/rflags.h>

namespace assembly {


	rflags_C::rflags_C() {}

	rflags_C::rflags_C(){}

	int rflags_C::gettf() {
		register rflags_t temp;
		temp.v = getRFLAGS();
		return temp.flags.tf;
	}

	int rflags_C::getiopl() {
		register rflags_t temp;
		temp.v = getRFLAGS();
		return temp.flags.iopl;
	}

	int rflags_C::getnt() {
		register rflags_t temp;
		temp.v = getRFLAGS();
		return temp.flags.intf;
	}

	int rflags_C::getrf() {
		register rflags_t temp;
		temp.v = getRFLAGS();
		return temp.flags.rf;
	}
	int rflags_C::getvm() {
		register rflags_t temp;
		temp.v = getRFLAGS();
		return temp.flags.vm;
	}

	int rflags_C::getac() {
		register rflags_t temp;
		temp.v = getRFLAGS();
		return temp.flags.ac;
	}

	int rflags_C::getvif() {
		register rflags_t temp;
		temp.v = getRFLAGS();
		return temp.flags.vif;
	}

	int rflags_C::getvip() {
		register rflags_t temp;
		temp.v = getRFLAGS();
		return temp.flags.vip;
	}

	int rflags_C::getid() {
		register rflags_t temp;
		temp.v = getRFLAGS();
		return temp.flags.id;
	}

	int rflags_C::settf(register uint8_t newTF= -1) {
		if(newTF > -1) {
			register rflags_t temp;
			temp.flags.tf = newTF;
			setRFLAGS(temp);
		}
		return newTF;
	}

	int rflags_C::setiopl(register uint8_t newIOPL = -1) {
		if(newIOPL > -1) {
			register rflags_t temp;
			temp.flags.tf = newIOPL;
			setRFLAGS(temp);
		}
		return newIOPL;
	}

	int rflags_C::setnt(register uint8_t newNT = -1) {
		if(newNT > -1) {
			register rflags_t temp;
			temp.flags.tf = newNT;
			setRFLAGS(temp);
		}
		return newNT;
	}

	int rflags_C::setrf(register uint8_t newRF = -1) {
		if(newRF > -1) {
			register rflags_t temp;
			temp.flags.tf = newRF;
			setRFLAGS(temp);
		}
		return newRF;
	}

	int rflags_C::setvm(register uint8_t newVM= -1) {
		if(newVM > -1) {
			register rflags_t temp;
			temp.flags.tf = newVM;
			setRFLAGS(temp);
		}
		return newVM;
	}

	int rflags_C::setac(register uint8_t newAC = -1) {
		if(newAC > -1) {
			register rflags_t temp;
			temp.flags.tf = newAC;
			setRFLAGS(temp);
		}
		return newAC;
	}

	int rflags_C::setvif(register uint8_t newVIF= -1) {
		return -1;
	}

	int rflags_C::setvip(register uint8_t newVIP = -1) {
		if(newVIP > -1) {
			register rflags_t temp;
			temp.flags.tf = newVIP;
			setRFLAGS(temp);
		}
		return newVIP;
	}

	int rflags_C::setid(register uint8_t newID = -1) {
		if(newID > -1) {
			register rflags_t temp;
			temp.flags.tf = newID;
			setRFLAGS(temp);
		}
		return newID;
	}

	/*
	int rflags_C::sti() {
		register int r = 1;
		if(IDTset())
			__asm__ volatile ("sti");
		else
			r--;
		return r;
	}
	*/

	/*
	void rflags_C::cli() {
		__asm__ volatile("cli");
	}
	*/

	int rflags_C::getintf() {
		register rflags_t temp;
		temp.v = getRFLAGS();
		return temp.flags.intf;
	}
}
