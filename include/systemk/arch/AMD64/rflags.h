/*
 * rflags.h
 *
 *  Created on: Nov 8, 2024
 *      Author: sean
 * Last Change:	Apr 28, 2024
 *
 * Description:	Functions and data structure to handle the RFLAGS register.
 */

#ifndef INCLUDE_ARCH_AMD64_RFLAGS_H_
#define INCLUDE_ARCH_AMD64_RFLAGS_H_

#include<stddef.h>
#include<stdint.h>

#include<arch/i686/eflags.h>

namespace assembly {
	//TODO Finish this class
	class rflags_C : eflags_C {
	public:
		rflags_C();
		~rflags_C();

		int gettf();
		int getiopl();
		int getnt();
		int getrf();
		int getvm();
		int getac();
		int getvif();
		int getvip();
		int getid();

		int settf(register uint8_t = -1);
		int setiopl(register uint8_t newIOPL);
		int setnt(register uint8_t = -1);
		int setrf(register uint8_t = -1);
		int setvm(register uint8_t = -1);
		int setac(register uint8_t = -1);
		int setvif(register uint8_t = -1);
		int setvip(register uint8_t = -1);
		int setid(register uint8_t = -1);

		int getintf();

		__attribute((always_inline))
		int sti() {
			register int r = 1;
			if(IDTset())
				__asm__ volatile ("sti");
			else
				r--;
			return r;
		}

		__attribute((always_inline))
		inline void cli() {
			__asm__ volatile("cli");
		}

	private:
		union rflags_t {
			uint64_t v;
			struct {
				eflags_t flags;			//Lower 32 bits are the same as EFLAGS, so refer to eflags_t for structure
				uint32_t reserved64;	//system reserved
			};
		}__attribute__((packed));

		//Returns a 64 bit unsigned integer that represents the EFLAGS register
		__attribute__((always_inline))
		inline uint64_t getRFLAGS() {
			register uint64_t flags;
			__asm__ volatile ("pushf"
				"popl %0"
				:"=r"(flags):);
			return flags;
		};

		//Puts the new 64bit unsgned integer to the EFLAGS register
		//TODO: Make this take in an unsigned integer instead of a pointer to a union
		__attribute__((always_inline))
		inline void setRFLAGS(const register rflags_t newRFLAGS) {
			if(newRFLAGS.flags.intf && !IDTset())
				return;
			//register uint64_t flags;
			__asm__ volatile ("pushl %0"
				"popf"
				::"r"(newRFLAGS));
			//return flags;
		};

		//Check to see if there is an IDT.  This is needed before using STI
		//bool IDTset();
	};

}

#endif /* INCLUDE_ARCH_AMD64_RFLAGS_H_ */
