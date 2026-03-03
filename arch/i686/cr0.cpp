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

namespace sk {
	namespace arch {

		i686_cr0_C::i686_cr0_C() {}

		bool [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::getpe() {
			return (dynamic_cast<i686_cr0_t>(this->getCR0())).pe;
		}

		bool [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::getmp() {
			return (dynamic_cast<i686_cr0_t>(this->getCR0())).mp;
		}

		bool [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::getem() {
			return (dynamic_cast<i686_cr0_t>(this->getCR0())).em;
		}

		bool [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::getts() {
			return (dynamic_cast<i686_cr0_t>(this->getCR0())).ts;
		}

		bool [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::getet() {
			return (dynamic_cast<i686_cr0_t>(this->getCR0())).et;
		}

		bool [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::getne() {
			return (dynamic_cast<i686_cr0_t>(this->getCR0())).ne;
		}

		bool [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::getwp() {
			return (dynamic_cast<i686_cr0_t>(this->getCR0())).wp;
		}

		bool [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::getam() {
			return (dynamic_cast<i686_cr0_t>(this->getCR0())).am;
		}

		bool [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::getnw() {
			return (dynamic_cast<i686_cr0_t>(this->getCR0())).nw;
		}

		bool [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::getcd() {
			return (dynamic_cast<i686_cr0_t>(this->getCR0())).cd;
		}

		bool [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::getpg() {
			return (dynamic_cast<i686_cr0_t>(this->getCR0())).pg;
		}

		int [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::setpe(short newpe = -1) {
			i686_cr0_t cr0;
			if (newpe > -1 && GDTset() && protectedIDTset()) {
				cr0.value = getCR0();
				cr0.pe = newpe;
				setCR0(cr0.value);
			}
			return cr0.pe;
		}

		int [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::setmp(short newmp = -1) {
			i686_cr0_t cr0;
			if (newmp > -1) {
				cr0.value = getCR0();
				cr0.mp = newmp;
				setCR0(cr0.value);
			}
			return cr0.mp;
		}

		int [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::setem(short newem = -1) {
			i686_cr0_t cr0;
			if (newem > -1) {
				cr0.value = getCR0();
				cr0.em = newem;
				setCR0(cr0.value);
			}
			return cr0.em;
		}

		int [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::setts(short newts = -1) {
			i686_cr0_t cr0;
			if (newts > -1) {
				cr0.value = getCR0();
				cr0.ts = newts;
				setCR0(cr0.value);
			}
			return cr0.ts;
		}

		void [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::clts() {
			__asm__ volatile ("clts");
		}

		int [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::setet(short newet = -1) {
			i686_cr0_t cr0;
			if (newet > -1) {
				cr0.value = getCR0();
				cr0.et = newet;
				setCR0(cr0.value);
			}
			return cr0.et;
		}

		int [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::setne(short newne = -1) {
			i686_cr0_t cr0;
			if (newne > -1) {
				cr0.value = getCR0();
				cr0.ne = newne;
				setCR0(cr0.value);
			}
			return cr0.ne;
		}

		int [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::setwp(short newwp = -1) {
			i686_cr0_t cr0;
			if (newwp > -1) {
				cr0.value = getCR0();
				cr0.wp = newwp;
				setCR0(cr0.value);
			}
			return cr0.wp;
		}

		int [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::setam(short newam = -1) {
			i686_cr0_t cr0;
			if (newam > -1) {
				cr0.value = getCR0();
				cr0.am = newam;
				setCR0(cr0.value);
			}
			return cr0.am;
		}

		int [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::setnw(short newnw = -1) {
			i686_cr0_t cr0;
			if (newnw > -1) {
				cr0.value = getCR0();
				cr0.nw = newnw;
				setCR0(cr0.value);
			}
			return cr0.nw;
		}

		int [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::setcd(short newcd = -1) {
			i686_cr0_t cr0;
			if (newcd > -1) {
				cr0.value = getCR0();
				cr0.cd = newcd;
				setCR0(cr0.value);
			}
			return cr0.cd;
		}

		int [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::setpg(short newpg = -1) {
			return -1;
		}

		/*
		unsigned long long [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::getCR0() {
			asm volatile ("mov %cr0, %0"
				:"=a");
		}
		*/

		/*
		void [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::setCR0(unsigned long long newCR0) {
			asm volatile("mov %0, cr0"
				:
			: "c" (newCR0));
		}
		*/

		/*
		bool [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::GDTset() {
			asm volatile ("movd %gdtr, %0"
				:"=a" (temp));
		}
		*/

		// stub
		bool [[gnu::fastcall]] [[msvc::__fastcall]] i686_cr0_C::protectedIDTset() {
			return 0;
		}


	}
}