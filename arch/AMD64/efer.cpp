/*
 * efer.cpp
 *
 *  Created on: Dec 16, 2024
 *      Author: sean
 * Last Change:	Apr 28, 2025
 *
 * Description:	Describe efer.cpp here
 */

#include<stddef.h>
#include<stdint.h>

#include<systemk/arch/AMD64/efer.h>

namespace assembly {

	efer_C::efer_C() {}

	efer_C::~efer_C() {}

	int efer_C::getsce() {
		register efer_t temp;
		temp.value = getEFER();
		return temp.sce;
	}
	int efer_C::getlme() {
		register efer_t temp;
		temp.value = getEFER();
		return temp.lme;
	}
	int efer_C::getlma() {
		register efer_t temp;
		temp.value = getEFER();
		return temp.lma;
	}
	int efer_C::getnxe() {
		register efer_t temp;
		temp.value = getEFER();
		return temp.nxe;
	}
	int efer_C::getsvme() {
		register efer_t temp;
		temp.value = getEFER();
		return temp.svme;
	}
	int efer_C::getlmsle() {
		register efer_t temp;
		temp.value = getEFER();
		return temp.lmsle;
	}
	int efer_C::gettce() {
		register efer_t temp;
		temp.value = getEFER();
		return temp.tce;
	}
	int efer_C::getmcommit() {
		register efer_t temp;
		temp.value = getEFER();
		return temp.mcommit;
	}
	int efer_C::getintwb() {
		register efer_t temp;
		temp.value = getEFER();
		return temp.intwb;
	}
	int efer_C::getuaie() {
		//TODO
		register efer_t temp;
		temp.value = getEFER();
		return temp.uaie;
	}
	int efer_C::getaibrse() {
		register efer_t temp;
		temp.value = getEFER();
		return temp.aibrse;
	}

	int efer_C::setsce(register uint8_t newSCE = -1) {
		if(-1 != newSCE) {
			register efer_t temp;
			temp.value = getEFER();
			temp.sce =  newSCE;
			setEFER(temp.value);
		}
		return newSCE;
	}
	int efer_C::setlme(register uint8_t newLME = -1) {
		if(-1 != newLME) {
			register efer_t temp;
			temp.value = getEFER();
			temp.lme =  newLME;
			setEFER(temp.value);
		}
		return newLME;
	}
	int efer_C::setlma(register uint8_t newLMA = -1) {
		if(-1 != newLMA) {
			register efer_t temp;
			temp.value = getEFER();
			temp.lma =  newLMA;
			setEFER(temp.value);
		}
		return newLMA;
	}
	int efer_C::setnxe(register uint8_t newNXE = -1) {
		if(-1 != newNXE) {
			register efer_t temp;
			temp.value = getEFER();
			temp.nxe =  newNXE;
			setEFER(temp.value);
		}
		return newNXE;
	}
	int efer_C::setsvme(register uint8_t newSVME = -1) {
		if(-1 != newSVME) {
			register efer_t temp;
			temp.value = getEFER();
			temp.svme =  newSVME;
			setEFER(temp.value);
		}
		return newSVME;
	}
	int efer_C::setlmsle(register uint8_t newLMSLE = -1) {
		if(-1 != newLMSLE) {
			register efer_t temp;
			temp.value = getEFER();
			temp.lmsle = newLMSLE;
			setEFER(temp.value);
		}
		return newLMSLE;
	}
	int efer_C::settce(register uint8_t newTCE = -1) {
		if(-1 != newTCE) {
			register efer_t temp;
			temp.value = getEFER();
			temp.tce =  newTCE;
			setEFER(temp.value);
		}
		return newTCE;
	}
	int efer_C::setmcommit(register uint8_t newMCOMMIT = -1) {
		if(-1 != newMCOMMIT) {
			register efer_t temp;
			temp.value = getEFER();
			temp.mcommit =  newMCOMMIT;
			setEFER(temp.value);
		}
		return newMCOMMIT;
	}
	int efer_C::setintwb(register uint8_t newINTWB = -1) {
		if(-1 != newINTWB) {
			register efer_t temp;
			temp.value = getEFER();
			temp.intwb = newINTWB ;
			setEFER(temp.value);
		}
		return newINTWB;
	}
	int efer_C::setuaie(register uint8_t newUAIE = -1) {
		if(-1 != newUAIE) {
			register efer_t temp;
			temp.value = getEFER();
			temp.uaie = newUAIE ;
			setEFER(temp.value);
		}
		return newUAIE;
	}
	int efer_C::setaibrse(register uint8_t newAIBRSE = -1) {
		if(-1 != newAIBRSE) {
			register efer_t temp;
			temp.value = getEFER();
			temp.aibrse = newAIBRSE;
			setEFER(temp.value);
		}
		return newAIBRSE;
	}

}
