/*
 * cr8.h
 *
 *  Created on: Nov 8, 2024
 *      Author: sean
 * Last Change:	Nov 11, 2024
 *
 * Description:
 */

#ifndef INCLUDE_ARCH_AMD64_CR8_H_
#define INCLUDE_ARCH_AMD64_CR8_H_

#include<stddef.h>
#include<stdint.h>

namespace assembly {

	union cr8_t{
		uint64_t value;
		struct {
			unsigned	tpr : 4,		//Task Priority
						reserved : 60;	//system reserved
		};
	}__attribute__((packed));

}


#endif /* INCLUDE_ARCH_AMD64_CR8_H_ */
