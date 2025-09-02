/*
 * boot.s
 *
 *  Created on: May 6, 2024
 *      Author: sean
 */

 .global _start
.extern init, kernel_main

.set MAGIC, 0x1BADB002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bss
.align 16
stack_bottom:
.skip 16384
stack_top:

.section .text
.type _start @function
	_start:
		;taking the cpu out of real mode
		movb	0x2, %al		;I might have to fix this...
;		movb	0x92, %dl
		outb	%al, 0x92

		movl	$stack_top, %esp

		call	init

		call	kernel_main
		cli

	end: hlt
		jmp @end

.size _start, . -_start

