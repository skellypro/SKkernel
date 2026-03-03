/*
 * cr0.h
 *
 *  Created on: Nov 8, 2024
 *      Author: sean
 * Last Change:	Feb 5, 2025
 *
 * Description:
 */

#pragma once

#include<stddef.h>
#include<stdint.h>

#include<systemk/arch/i686/cr0.h>

namespace sk {
	namespace arch {

		typedef class AMD64_cr0_C : i686_cr0_C {
		public:
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
			void [[gnu::fastcall]] [[msvc::__fastcall]] clts();

			int [[gnu::fastcall]] [[msvc::__fastcall]] setet(short = -1);
			int [[gnu::fastcall]] [[msvc::__fastcall]] setne(short = -1);
			int [[gnu::fastcall]] [[msvc::__fastcall]] setwp(short = -1);
			int [[gnu::fastcall]] [[msvc::__fastcall]] setam(short = -1);
			int [[gnu::fastcall]] [[msvc::__fastcall]] setnw(short = -1);
			int [[gnu::fastcall]] [[msvc::__fastcall]] setcd(short = -1);
			int [[gnu::fastcall]] [[msvc::__fastcall]] setpg(short = -1);
		private:
			union AMD64_cr0_t {
				uint64_t v;
				struct {
					i686_cr0_t	cr0;		//Refer to i686_cr0_t for lower 32 bit structure
					uint32_t	reserved64;	//system reserved
				};
			};

			[[gnu::always_inline]]
			inline unsigned long long [[gnu::fastcall]] [[msvc::__fastcall]] getCR0() {
				asm volatile ("movl %cr0, %0"
					:"=a"
					:
					: );
			}

			[[gnu::always_inline]]
			inline void [[gnu::fastcall]] [[msvc::__fastcall]] setCR0(unsigned long long newCR0) {
				asm volatile ("movl %0, %cr0"
					:
					: "c"(newCRO)
					: );
			}

			[[gnu::always_inline]]
			inline bool [[gnu::fastcall]] [[msvc::__fastcall]] GDTset() {
				asm volatile ("movl %gdtr, %0"
					:"=a"
					:
					: ); // :)
			}
			bool [[gnu::fastcall]] [[msvc::__fastcall]] protectedIDTset();
		} AMD64_cr0;

	}
}