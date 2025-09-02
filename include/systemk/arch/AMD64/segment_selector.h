/*
 * segment_selector.h
 *
 *  Created on: Jan 8, 2024
 *      Author: sean
 */

#ifndef INCLUDE_ARCH_AMD64_SEGMENT_SELECTOR_H_
#define INCLUDE_ARCH_AMD64_SEGMENT_SELECTOR_H_

#include<stdint.h>
#include<stddef.h>

// this feels really sloppy ngl this is a legacy segment descriptor
struct segment_selector{
	union{
		struct{
			unsigned int a;
			unsigned int b;
		};
		struct{
			uint16_t limit0;
			uint16_t base0;
			unsigned basl: 8, type: 4, s:1, dpl:2, p:1;
			unsigned limit: 4, avl: 1, l: 1, g: 1, base2: 8;
		};
	};
}__attribute__((packed));

#endif /* INCLUDE_ARCH_AMD64_SEGMENT_SELECTOR_H_ */
