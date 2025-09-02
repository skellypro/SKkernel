/*
 * segment_selector.h
 *
 *  Created on: Nov 20, 2024
 *      Author: sean
 */

#ifndef INCLUDE_ARCH_I686_SEGMENT_SELECTOR_H_
#define INCLUDE_ARCH_I686_SEGMENT_SELECTOR_H_

#include<stdint.h>
#include<stddef.h>

union i686_segment_selector_t {
	uint16_t v;
	struct {
		unsigned	rpl : 2,	//Requestor Privelage Level
					ti : 1,		//Table Indicator
					si : 11;	//Selector Index
	};
}__attribute__((packed));

#endif /* INCLUDE_ARCH_I686_SEGMENT_SELECTOR_H_ */
