/*
 * fastsyscall.h
 *
 *  Created on: May 1, 2025
 *      Author: sean
 * Last Change:	May 25, 2025
 *
 * Description:	Describe fastsyscall.h here
 */

#ifndef INCLUDE_SYSTEMK_ARCH_I686_FASTSYSCALL_H_
#define INCLUDE_SYSTEMK_ARCH_I686_FASTSYSCALL_H_

#ifdef i686

#define syscall(x) __asm__ volatile("syscall %0" ::"r"(x));

#define sysret __asm__ volatile ("sysret");

#define sysenter __asm__ volatile("sysenter");

#define sysexit __asm__ volatile("sysexit");

#endif /* INCLUDE_SYSTEMK_ARCH_I686_FASTSYSCALL_H_ */
