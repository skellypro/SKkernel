;/*
; * boot.s
; *
; *		 Created on:	Jan 27, 2023
; *			 Author:	sean
; *		Description:	Boot file for AMD64 cpu's
; */
 
;.include "include/asm/multiboot.inc"
; .include "include/multiboot.h"
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

jmp @_start

;fix this
.size 510 - ($ - $$)
.byte 0x55
.byte 0xAA
.word 0

.section .bss
.align 16
stack_bottom:
.skip 16384
stack_top:

.section .text
.type _start @function
	_start:
		;set up the stack
		movl	$stack_top, %rbp
		movl	%rbp, %rsp
		pushl	%rax
		pushl	%rbx
		pushl	%rcx
		pushl	%rdx
		;taking the cpu out of real mode
		movb	0x2, %al		;I might have to fix this...
		movb	0x92, %dl
		outb	%al, %dl

		;enable protection
		;movb	0x1, %al
		;movb	%al, %cr0
		
		popl	%rdx
		popl	%rcx
		popl	%rbx
		popl	%rax

		call	init

		call	kernel_main
		cli
		
	end: hlt
		jmp @end

.size _start, . -_start

