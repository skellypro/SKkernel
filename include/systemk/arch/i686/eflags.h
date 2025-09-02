/*
 * eflags.h
 *
 *  Created on: Nov 8, 2024
 *      Author: sean
 * Last Change:	Apr 29, 2025
 *
 * Description:	Class to handle the EFLAGS register.
 * 	This class has a built in mechanism to prevent
 * the interrupt flag (EFLAGS.int) from raising without
 * an IDT. This class is also designed to not leak the
 * value of the EFLAGS register.  The EFLAGS class
 * prevents leaks about the system state
 * by not using any data members, and by encapsulating
 * the complete value of EFLAGS. Only 1 flag can be
 * handled at a time
 */

#ifndef INCLUDE_ARCH_I686_EFLAGS_H_
#define INCLUDE_ARCH_I686_EFLAGS_H_

#include<stddef.h>
#include<stdint.h>

namespace assembly {

	class eflags_C {
	public:
		eflags_C();
		~eflags_C();

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
		int getintf();

	private:
		union eflags_t {
			uint32_t value;
			struct{
				unsigned cf : 1,		//Carry Flag
						/*reserved*/ : 1,	//system reserved
						pf : 1,			//Parity Flag
						/*reserved*/ : 1,	//system reserved
						af : 1,			//Auxilary Flag
						/*reserved*/ : 1,	//system reserved
						zf : 1,			//Zero Flag
						sf : 1,			//Sign Flag
						tf : 1,			//Trap Flag, used for debugging.  Clear to disable Single-step Mode
						intf : 1,		//Interrupt Flag
						df : 1,			//Direction Flag
						of : 1,			//Overflow Flag
						iopl : 2,		//I/O Privilege Level
						nt : 1,			//Nested Task, manipulating this flag can cause crashes in application programs
						/*reserved*/ : 1,	//system reserved
						rf : 1,			//Resume Flag
						vm : 1,			//Virtual-8086 Mode
						ac : 1,			//Alignment Check
						vif : 1,		//Virtual Interrupt Flag
						vip : 1,		//Virtual Interrupt Pending
						id : 1,			//ID Flag
						/*reserved*/ : 10;	//system reserved
			};
		}__attribute__((packed));

		//Returns a 32 bit unsigned integer that represents the EFLAGS register
		__attribute__((always_inline))
		inline uint32_t getEFLAGS() {
			register uint32_t flags;
			__asm__ volatile ("pushf"
				"pop %0"
				:"=r"(flags):);
			return flags;
		};

		//Puts the new 32 bit unsgned integer to the EFLAGS register
		//TODO: Make this take in an unsigned integer instead of a pointer to a union
		__attribute__((always_inline))
		inline void setEFLAGS(const register eflags_t newEFLAGS) {
			if(newEFLAGS.intf && !IDTset())
				return;

			__asm__ volatile ("load [%0] %eax"
					"push %eax"
					"popf"
					::"r"(newEFLAGS));
		};

		//Check to see if there is an IDT.  This is needed before using STI
		__attribute__((always_inline))
		inline bool IDTset() {
			register bool re;
			__asm__ volatile("mov %idtr %0"
					//"store %eax %0"
					:"=r" ((int)re):);
			return re;
		};
	};

}

#endif /* INCLUDE_ARCH_I686_EFLAGS_H_ */
