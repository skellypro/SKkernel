/*
 * cr0.h
 *
 *  Created on: Nov 8, 2024
 *      Author: sean
 * Last Change:	Feb 5, 2025
 *
 * Description:
 */

#ifndef INCLUDE_ARCH_AMD64_CR0_H_
#define INCLUDE_ARCH_AMD64_CR0_H_

#include<stddef.h>
#include<stdint.h>

#include<arch/i686/cr0.h>

namespace assembly {

	class AMD64_cr0_C : i686_cr0_C{
	public:
		bool getpe();
		bool getmp();
		bool getem();
		bool getts();
		bool getet();
		bool getne();
		bool getwp();
		bool getam();
		bool getnw();
		bool getcd();
		bool getpg();

		int setpe(register uint8_t = -1);
		int setmp(register uint8_t = -1);
		int setem(register uint8_t = -1);

		int setts(register uint8_t = -1);
		void clts();

		int setet(register uint8_t = -1);
		int setne(register uint8_t = -1);
		int setwp(register uint8_t = -1);
		int setam(register uint8_t = -1);
		int setnw(register uint8_t = -1);
		int setcd(register uint8_t = -1);
		int setpg(register uint8_t = -1);
	private:
		union AMD64_cr0_t {
			uint64_t v;
			struct {
				i686_cr0_t	cr0;		//Refer to i686_cr0_t for lower 32 bit structure
				uint32_t	reserved64;	//system reserved
			};
		};

		uint64_t getCR0();
		void setCR0(register uint64_t newCR0);

		bool GDTset();
		bool protectedIDTset();
	};

}

#endif /* INCLUDE_ARCH_AMD64_CR0_H_ */
