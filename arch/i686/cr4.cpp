/*
 * cr4.cpp
 *
 *  Created on: May 5, 2025
 *      Author: sean
 * Last Change:	May 25, 2025
 *
 * Description:	Describe cr4.cpp here
 */

#include<systemk/arch/i686/cr4.h>

namespace assembly {

	uint32_t i686_cr4_c::getvme() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.vme;
	}

	uint32_t i686_cr4_c::getpvi() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.pvi;
	}

	uint32_t i686_cr4_c::gettsd() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.tsd;
	}

	uint32_t i686_cr4_c::getde() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.de;
	}

	uint32_t i686_cr4_c::getpse() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.pse;
	}

	uint32_t i686_cr4_c::getpae() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.pae;
	}

	uint32_t i686_cr4_c::getmce() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.mce;
	}

	uint32_t i686_cr4_c::getpge() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.pge;
	}

	uint32_t i686_cr4_c::getpce() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.pce;
	}

	uint32_t i686_cr4_c::getosfxr() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.osfxr;
	}

	uint32_t i686_cr4_c::getosxmmexcpt() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.osxmmexcpt;
	}

	uint32_t i686_cr4_c::getumip() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.umip;
	}

	uint32_t i686_cr4_c::getla57() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.la57;
	}

	uint32_t i686_cr4_c::getfsgbase() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.fsgbase;
	}

	uint32_t i686_cr4_c::getpcide() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.pcide;
	}

	uint32_t i686_cr4_c::getosxsave() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.osxsave;
	}

	uint32_t i686_cr4_c::getsmep() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.smep;
	}

	uint32_t i686_cr4_c::getsmap() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.smap;
	}

	uint32_t i686_cr4_c::getpke() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.pke;
	}

	uint32_t i686_cr4_c::getcet() {
		register i686_cr4_t re;
		re.value = getCR4();
		return re.cet;
	}


	int i686_cr4_c::setvme(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.vme = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setpvi(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.pvi = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::settsd(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.tsd = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setde(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.de = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setpse(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.pse = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setpae(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.pae = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setmce(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.mce = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setpge(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.pge = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setpce(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.pce = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setosfxr(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.osfxr = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setosxmmexcpt(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.osxmmexcpt = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setumip(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.umip = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setla57(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.la57 = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setfsgbase(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.fsgbase = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setpcide(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.pcide = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setosxsave(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.osxsave = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setsmep(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.smep = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setsmap(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.smap = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setpke(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.pke = x;
			setCR4(reg);
		}
		return x;
	}

	int i686_cr4_c::setcet(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register i686_cr4_t reg;
			reg.value = getCR4();
			reg.cet = x;
			setCR4(reg);
		}
		return x;
	}

}
