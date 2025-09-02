/*
 * cr4.h
 *
 *  Created on: Nov 8, 2024
 *      Author: sean
 * Last Change:	May 25, 2025
 *
 * Description:
 */

#ifndef INCLUDE_ARCH_I686_CR4_H_
#define INCLUDE_ARCH_I686_CR4_H_

#include<stddef.h>
#include<stdint.h>

namespace assembly {

	class i686_cr4_c {
	public:
		virtual i686_cr4_c() {}
		virtual ~i686_cr4_c() {}
		virtual uint32_t getvme();
		virtual uint32_t getpvi();
		virtual uint32_t gettsd();
		virtual uint32_t getde();
		virtual uint32_t getpse();
		virtual uint32_t getpae();
		virtual uint32_t getmce();
		virtual uint32_t getpge();
		virtual uint32_t getpce();
		virtual uint32_t getosfxr();
		virtual uint32_t getosxmmexcpt();
		virtual uint32_t getumip();
		virtual uint32_t getla57();
		virtual uint32_t getfsgbase();
		virtual uint32_t getpcide();
		virtual uint32_t getosxsave();
		virtual uint32_t getsmep();
		virtual uint32_t getsmap();
		virtual uint32_t getpke();
		virtual uint32_t getcet();

		virtual int setvme(register uint8_t = -1);
		virtual int setpvi(register uint8_t = -1);
		virtual int settsd(register uint8_t = -1);
		virtual int setde(register uint8_t = -1);
		virtual int setpse(register uint8_t = -1);
		virtual int setpae(register uint8_t = -1);
		virtual int setmce(register uint8_t = -1);
		virtual int setpge(register uint8_t = -1);
		virtual int setpce(register uint8_t = -1);
		virtual int setosfxr(register uint8_t = -1);
		virtual int setosxmmexcpt(register uint8_t = -1);
		virtual int setumip(register uint8_t = -1);
		virtual int setla57(register uint8_t = -1);
		virtual int setfsgbase(register uint8_t = -1);
		virtual int setpcide(register uint8_t = -1);
		virtual int setosxsave(register uint8_t = -1);
		virtual int setsmep(register uint8_t = -1);
		virtual int setsmap(register uint8_t = -1);
		virtual int setpke(register uint8_t = -1);
		virtual int setcet(register uint8_t = -1);
	protected:
		union alignas(uint32_t) i686_cr4_t {
			uint32_t value;
			struct {
				unsigned	vme : 1,		//Virtual-8086 Mode Extensions
							pvi : 1,		//Protected-Mode Virtual Interrupts
							tsd : 1,		//Time Stamp Disable
							de : 1,			//Debugging Extensions
							pse : 1,		//Page Size Extensions
							pae : 1,		//Physical-Address Extensions
							mce : 1,		//Machine Check Enable
							pge : 1,		//Page-Global Enable
							pce : 1,		//Performance-Monitoring Counter Enabled
							osfxr : 1,		//Operating System FXSAVE/FXRSTOR Support
							osxmmexcpt : 1,	//Operating System Unmasked Exception Support
							umip : 1,		//User Mode Instruction Prevention
							la57 : 1,		//5-Level Paging Enabled
							/*reserved*/ : 3,	//system reserved
							fsgbase : 1,	//Enable RDFSBASE, RDGSBASE, WRFBASE, WRGSBASE Instructions
							pcide : 1,		//Process Context Identifier Enable
							osxsave : 1,	//XSAVE and Processor Extended Status Enable Bit
							/*reserved*/ : 1,	//system reserved
							smep : 1,		//Supervisor Mode Execution Prevention
							smap : 1,		//Supervisor Mode Access Prevention
							pke : 1,		//Protection Key Enable
							cet : 1,		//Control-flow Enforcement Technology
							/*reserved*/ : 7;	//system reserved
			};
		}__attribute__((packed));

	private:
		virtual inline uint32_t getCR4() {
			register uint32_t re;
			__asm__ volatile ("movd %cr4, %0" :"=r" (re):);
			return re;
		}

		virtual inline void setCR4(register i686_cr4_t newVal) {
			__asm__ volatile ("movd %0, %cr4"::"r"(newVal));
		}
	};

}

#endif /* INCLUDE_ARCH_I686_CR4_H_ */
