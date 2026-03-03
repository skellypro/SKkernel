/*
 * cr0.cpp
 *
 *  Created on: Dec 16, 2024
 *      Author: sean
 * Last Change:	Feb 5, 2025
 *
 * Description:	Implementations for member functions of class AMD64_cr0_C
 */

#include<stddef.h>
#include<stdint.h>

#include<systemk/arch/AMD64/cr0.h>

namespace sk {
	namespace arch {
		bool [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::getpe() {
			return (dynamic_cast<AMD64_cr0_t>(this->getCR0())).pe;
		}
		bool [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::getmp() {
			return (dynamic_cast<AMD64_cr0_t>(this->getCR0())).mp;
		}
		bool [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::getem() {
			return (dynamic_cast<AMD64_cr0_t>(this->getCR0())).em;
		}
		bool [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::getts() {
			return (dynamic_cast<AMD64_cr0_t>(this->getCR0())).ts;
		}
		bool [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::getet() {
			return (dynamic_cast<AMD64_cr0_t>(this->getCR0())).et;
		}
		bool [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::getne() {
			return (dynamic_cast<AMD64_cr0_t>(this->getCR0())).ne;
		}
		bool [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::getwp() {
			return (dynamic_cast<AMD64_cr0_t>(this->getCR0())).wp;
		}
		bool [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::getam() {
			return (dynamic_cast<AMD64_cr0_t>(this->getCR0())).am;
		}
		bool [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::getnw() {
			return (dynamic_cast<AMD64_cr0_t>(this->getCR0())).nw;
		}
		bool [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::getcd() {
			return (dynamic_cast<AMD64_cr0_t>(this->getCR0())).cd;
		}
		bool [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::getpg() {
			return (dynamic_cast<AMD64_cr0_t>(this->getCR0())).pg;
		}

		int [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::setpe(short newPE = -1) {
			AMD64_cr0_t cr0;
			if (GDTset() && 0 == newPE && 1 == newPE) {
				//TODO
			}
			return 0;
		}
		int [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::setmp(short = -1) {
			AMD64_cr0_t cr0;
			return 0;
		}
		int [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::setem(short = -1) {
			AMD64_cr0_t cr0;
			return 0;
		}

		int [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::setts(short = -1) {
			AMD64_cr0_t cr0;
			return 0;
		}
		void [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::clts() {
			asm volatile ("clts");
		}

		int [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::setet(short = -1) {
			AMD64_cr0_t cr0;
			return 0;
		}
		int [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::setne(short = -1) {
			AMD64_cr0_t cr0;
			return 0;
		}
		int [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::setwp(short = -1) {
			AMD64_cr0_t cr0;
			return 0;
		}
		int [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::setam(short = -1) {
			AMD64_cr0_t cr0;
			return 0;
		}
		int [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::setnw(short = -1) {
			AMD64_cr0_t cr0;
			return 0;
		}
		int [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::setcd(short = -1) {
			AMD64_cr0_t cr0;
			return 0;
		}
		int [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::setpg(short = -1) {
			AMD64_cr0_t cr0;
			return 0;
		}

		/*
		unsigned long long [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::getCR0() {
			asm volatile ("movl %cr0, %0"
				:"=a"
				:
				: );
		}
		*/

		/*
		void [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::setCR0(unsigned long long newCR0) {
			asm volatile ("movl %0, %cr0"
				:
				: "c"(newCRO)
				: );
		}
		*/

		/*
		bool [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::GDTset() {
			asm volatile ("movl %gdtr, %0"
				:"=a"
				:
				:); // :)
		}
		*/

		// stub
		bool [[gnu::fastcall]] [[msvc::__fastcall]] AMD64_cr0_C::protectedIDTset() {
			return 0;
		}
	}
}