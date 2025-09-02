/*
 * fastsyscall.h
 *
 *  Created on: May 1, 2025
 *      Author: sean
 * Last Change:	May 25, 2025
 *
 * Description:	Describe fastsyscall.h here
 */

#ifndef INCLUDE_SYSTEMK_ARCH_AMD64_FASTSYSCALL_H_
#define INCLUDE_SYSTEMK_ARCH_AMD64_FASTSYSCALL_H_

#ifdef AMD64
#ifndef i686

#define syscall(x) __asm__ volatile("syscall %0" ::"r"(x));

#define sysret __asm__ volatile ("sysret");

#endif
#endif

#endif /* INCLUDE_SYSTEMK_ARCH_AMD64_FASTSYSCALL_H_ */
