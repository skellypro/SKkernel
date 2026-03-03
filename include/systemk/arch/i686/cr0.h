/*
 * cr0.h
 *
 *  Created on: Nov 8, 2024
 *      Author: sean
 * Last Change:	Dec 16, 2024
 *
 * Description:	Class to handle the CR0 register
 */

#pragma once

#include<stddef.h>
#include<stdint.h>
#include<stdbool.h>

namespace sk {
	namespace arch {

		typedef class i686_cr0_C {
		public:
			i686_cr0_C();

			bool [[gnu::fastcall]] [[msvc::__fastcall]] getpe();
			bool [[gnu::fastcall]] [[msvc::__fastcall]] getmp();
			bool [[gnu::fastcall]] [[msvc::__fastcall]] getem();
			bool [[gnu::fastcall]] [[msvc::__fastcall]] getts();
			bool [[gnu::fastcall]] [[msvc::__fastcall]] getet();
			bool [[gnu::fastcall]] [[msvc::__fastcall]] getne();
			bool [[gnu::fastcall]] [[msvc::__fastcall]] getwp();
			bool [[gnu::fastcall]] [[msvc::__fastcall]] getam();
			bool [[gnu::fastcall]] [[msvc::__fastcall]] getnw();
			bool [[gnu::fastcall]] [[msvc::__fastcall]] getcd();
			bool [[gnu::fastcall]] [[msvc::__fastcall]] getpg();

			int [[gnu::fastcall]] [[msvc::__fastcall]] setpe(short = -1);
			int [[gnu::fastcall]] [[msvc::__fastcall]] setmp(short = -1);
			int [[gnu::fastcall]] [[msvc::__fastcall]] setem(short = -1);

			int [[gnu::fastcall]] [[msvc::__fastcall]] setts(short = -1);
			void clts();

			int [[gnu::fastcall]] [[msvc::__fastcall]] setet(short = -1);
			int [[gnu::fastcall]] [[msvc::__fastcall]] setne(short = -1);
			int [[gnu::fastcall]] [[msvc::__fastcall]] setwp(short = -1);
			int [[gnu::fastcall]] [[msvc::__fastcall]] setam(short = -1);
			int [[gnu::fastcall]] [[msvc::__fastcall]] setnw(short = -1);
			int [[gnu::fastcall]] [[msvc::__fastcall]] setcd(short = -1);
			int [[gnu::fastcall]] [[msvc::__fastcall]] setpg(short = -1);

		private:
			union i686_cr0_t {
				uint32_t value;
				struct {
					unsigned 	pe : 1,			//Protection Enabled
						mp : 1,			//Monitor Coprocessor
						em : 1,			//Emulation
						ts : 1,			//Task Switched
						et : 1,			//Extension Type
						ne : 1,			//Numeric Error
						/*reserved*/ : 10,	//system reserved
						wp : 1,			//Write Protect
						/*reserved*/ : 1,	//system reserved
						am : 1,			//Alignment Mask
						/*reserved*/ : 10,	//system reserved
						nw : 1,			//Not Writethrough
						cd : 1,			//Cache Disable
						pg : 1;			//Paging
				};
			}__attribute__((packed));

			[[gnu::always_inline]]
			inline unsigned long long [[gnu::fastcall]] [[msvc::__fastcall]] getCR0() {
				asm volatile ("movd %cr0, %0"
					:"=a");
			}

			[[gnu::always_inline]]
			inline void [[gnu::fastcall]] [[msvc::__fastcall]] setCR0(unsigned long long newCR0) {
				asm volatile("movd %0, cr0"
					:
					: "c" (newCR0));
			}

			[[gnu::always_inline]]
			inline bool [[gnu::fastcall]] [[msvc::__fastcall]] GDTset() {
				asm volatile ("movd %gdtr, %0"
					:"=a" (temp));
			}

			bool [[gnu::fastcall]] [[msvc::__fastcall]] protectedIDTset();
		} i686_cr0;
	}
}