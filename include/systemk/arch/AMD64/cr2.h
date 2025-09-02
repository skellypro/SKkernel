/*
 * cr2.h
 *
 *  Created on: Nov 8, 2024
 *      Author: sean
 * Last Change:	Nov 8, 2024
 *
 * Description:
 */

#ifndef INCLUDE_ARCH_AMD64_CR2_H_
#define INCLUDE_ARCH_AMD64_CR2_H_

#include<stddef.h>
#include<stdint.h>

#include<arch/i686/cr2.h>

namespace assembly {

	union AMD64_cr2_t {
		uint64_t pfva;			//Page-Fault Virtual Address
		struct {
			i686_cr2_t	lower;
			uint32_t	upper;
		};
	};

}

#endif /* INCLUDE_ARCH_AMD64_CR2_H_ */
