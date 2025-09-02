/*
 * cr4.cpp
 *
 *  Created on: May 25, 2025
 *      Author: sean
 * Last Change:	May 25, 2025
 *
 * Description:	Describe cr4.cpp here
 */

#include<stddef.h>
#include<stdint.h>

#include<systemk/arch/AMD64/cr4.h>

namespace assembly {
	uint64_t AMD64_cr4_c::getvme() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.vme;
	}

	uint64_t AMD64_cr4_c::getpvi() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.pvi;
	}

	uint64_t AMD64_cr4_c::gettsd() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.tsd;
	}

	uint64_t AMD64_cr4_c::getde() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.de;
	}

	uint64_t AMD64_cr4_c::getpse() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.pse;
	}

	uint64_t AMD64_cr4_c::getpae() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.pae;
	}

	uint64_t AMD64_cr4_c::getmce() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.mce;
	}

	uint64_t AMD64_cr4_c::getpge() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.pge;
	}

	uint64_t AMD64_cr4_c::getpce() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.pce;
	}

	uint64_t AMD64_cr4_c::getosfxr() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.osfxr;
	}

	uint64_t AMD64_cr4_c::getosxmmexcpt() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.osxmmexcpt;
	}

	uint64_t AMD64_cr4_c::getumip() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.umip;
	}

	uint64_t AMD64_cr4_c::getla57() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.la57;
	}

	uint64_t AMD64_cr4_c::getfsgbase() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.fsgbase;
	}

	uint64_t AMD64_cr4_c::getpcide() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.pcide;
	}

	uint64_t AMD64_cr4_c::getosxsave() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.osxsave;
	}

	uint64_t AMD64_cr4_c::getsmep() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.smep;
	}

	uint64_t AMD64_cr4_c::getsmap() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.smap;
	}

	uint64_t AMD64_cr4_c::getpke() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.pke;
	}

	uint64_t AMD64_cr4_c::getcet() {
		register AMD64_cr4_t re;
		re.value = getCR4();
		return re.cr4.cet;
	}


	int AMD64_cr4_c::setvme(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.vme = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setpvi(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.pvi = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::settsd(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.tsd = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setde(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.de = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setpse(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.pse = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setpae(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.pae = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setmce(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.mce = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setpge(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.pge = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setpce(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.pce = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setosfxr(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.osfxr = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setosxmmexcpt(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.osxmmexcpt = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setumip(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.umip = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setla57(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.la57 = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setfsgbase(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.fsgbase = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setpcide(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.pcide = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setosxsave(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.osxsave = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setsmep(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.smep = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setsmap(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.smap = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setpke(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.pke = x;
			setCR4(reg);
		}
		return x;
	}

	int AMD64_cr4_c::setcet(register uint8_t x = -1) {
		if(0 == x || 1 == x) {
			register AMD64_cr4_t reg;
			reg.value = getCR4();
			reg.cr4.cet = x;
			setCR4(reg);
		}
		return x;
	}

}
