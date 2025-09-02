/*
 * skKernel.h
 *
 *  Created on: Jan 14, 2023
 *      Author: sean
 */

#ifndef SKKERNEL_H_
#define SKKERNEL_H_

#include<systemk/skcplus.h>

#define KERNEL

#ifndef NULL
#define NULL 				0
#endif

extern "C" {
	void kernel_main();

	void init();
}

#endif /* SKKERNEL_H_ */
