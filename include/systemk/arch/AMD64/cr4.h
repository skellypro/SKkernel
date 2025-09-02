/
 * cr4.h
 *
 *  Created on: Nov 8, 2024
 *      Author: sean
 * Last Change:	May 25, 2024
 *
 * Description:
 */

#ifndef INCLUDE_ARCH_AMD64_CR4_H_
#define INCLUDE_ARCH_AMD64_CR4_H_

#include<stddef.h>
#include<stdint.h>

#include<arch/i686/cr4.h>

namespace assembly {

	class AMD64_cr4_c : i686_cr4_c {
	public:
		AMD64_cr4_c() {}
		~AMD64_cr4_c() {}
		uint64_t getvme();
		uint64_t getpvi();
		uint64_t gettsd();
		uint64_t getde();
		uint64_t getpse();
		uint64_t getpae();
		uint64_t getmce();
		uint64_t getpge();
		uint64_t getpce();
		uint64_t getosfxr();
		uint64_t getosxmmexcpt();
		uint64_t getumip();
		uint64_t getla57();
		uint64_t getfsgbase();
		uint64_t getpcide();
		uint64_t getosxsave();
		uint64_t getsmep();
		uint64_t getsmap();
		uint64_t getpke();
		uint64_t getcet();

		int setvme(register uint8_t = -1);
		int setpvi(register uint8_t = -1);
		int settsd(register uint8_t = -1);
		int setde(register uint8_t = -1);
		int setpse(register uint8_t = -1);
		int setpae(register uint8_t = -1);
		int setmce(register uint8_t = -1);
		int setpge(register uint8_t = -1);
		int setpce(register uint8_t = -1);
		int setosfxr(register uint8_t = -1);
		int setosxmmexcpt(register uint8_t = -1);
		int setumip(register uint8_t = -1);
		int setla57(register uint8_t = -1);
		int setfsgbase(register uint8_t = -1);
		int setpcide(register uint8_t = -1);
		int setosxsave(register uint8_t = -1);
		int setsmep(register uint8_t = -1);
		int setsmap(register uint8_t = -1);
		int setpke(register uint8_t = -1);
		int setcet(register uint8_t = -1);
	private:
		union alignas(uint64_t) AMD64_cr4_t {
			uint64_t value;
			struct {
				i686_cr4_t cr4;		//Refer to i686_cr4_t for lower 32 bit structure
				uint32_t reserved;	//system reserved
			};
		}__attribute__((packed));

		inline uint64_t getCR4() {
			register uint64_t re;
			__asm__ volatile ("movl %cr4, %0" :"=r" (re):);
			return re;
		}

		inline void setCR4(register AMD64_cr4_t newVal) {
			__asm__ volatile ("movl %0, %cr4"::"r"(newVal));
		}
	};

}

#endif /* INCLUDE_ARCH_AMD64_CR4_H_ */
