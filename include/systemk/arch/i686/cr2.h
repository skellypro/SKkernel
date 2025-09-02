/*
 * cr2.h
 *
 *  Created on: Nov 8, 2024
 *      Author: sean
 * Last Change:	Nov 8, 2024
 *
 * Description:
 */

#ifndef INCLUDE_ARCH_I686_CR2_H_
#define INCLUDE_ARCH_I686_CR2_H_

#include<stddef.h>
#include<stdint.h>

namespace assembly {

	class i686_cr2_C {
	public:
		i686_cr2_C();

		uint32_t getPFVA();
	private:
		struct i686_cr2_t {
			uint32_t pfva; //Page Fault Virtual Address
		}__attribute__((packed)) i686_cr2;
	};
}

#endif /* INCLUDE_ARCH_I686_CR2_H_ */
