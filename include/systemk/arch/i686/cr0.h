/*
 * cr0.h
 *
 *  Created on: Nov 8, 2024
 *      Author: sean
 * Last Change:	Dec 16, 2024
 *
 * Description:	Class to handle the CR0 register
 */

#ifndef INCLUDE_ARCH_I686_CR0_H_
#define INCLUDE_ARCH_I686_CR0_H_

#include<stddef.h>
#include<stdint.h>
#include<stdbool.h>

namespace assembly {

	class i686_cr0_C {
	public:
		i686_cr0_C();

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

		uint32_t getCR0();
		void setCR0(register uint32_t newCR0);

		bool GDTset();
		bool protectedIDTset();
	};
}

#endif /* INCLUDE_ARCH_I686_CR0_H_ */
