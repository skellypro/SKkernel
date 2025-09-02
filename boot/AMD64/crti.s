/*
 * crti.s
 *
 *  Created on: Nov 3, 2023
 *      Author: sean
 */

 .section .init
 .global .init
 .type _init, @function
 _init:
 	push %rbp
 	movl %rsp, %rbp

.section .fini
.global .fini
.type _fini, @function
_fini:
	push %rbp
	movl %rsp, %rbp
