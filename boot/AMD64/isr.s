/*
 * isr.s
 *
 *  Created on: Dec 27, 2023
 *      Author: sean
 */

%macro	isr_err_stub 1
isr_stub_%+%1:
	call	exception_handler
	iretq
%endmacro

%macro	isr_no_err_stub 1
isr_stub_%+%1:
	call	exception_handler
	iretq
%endmacro

.extern	exception_handler
%define	isr_no_err_stub	0
%define	isr_no_err_stub	1
%define	isr_no_err_stub	2
%define	isr_no_err_stub	3
%define	isr_no_err_stub	4
%define	isr_no_err_stub	5
%define	isr_no_err_stub	6
%define	isr_no_err_stub	7
%define	isr_err_stub	8
%define	isr_no_err_stub	9
%define	isr_err_stub	10
%define	isr_err_stub	11
%define	isr_err_stub	12
%define	isr_err_stub	13
%define	isr_err_stub	14
%define	isr_no_err_stub	15
%define	isr_no_err_stub	16
%define	isr_err_stub	17
%define	isr_no_err_stub	18
%define	isr_no_err_stub	19
%define	isr_no_err_stub	20
%define	isr_no_err_stub	21
%define	isr_no_err_stub	22
%define	isr_no_err_stub	23
%define	isr_no_err_stub	24
%define	isr_no_err_stub	25
%define	isr_no_err_stub	26
%define	isr_no_err_stub	27
%define	isr_no_err_stub	28
%define	isr_no_err_stub	29
%define	isr_err_stub	30
%define	isr_no_err_stub	31

.global isr_stub_table
isr_stub_table:
%assign	i	0
%rep	32
	dq	isr_stub_%+i
%assign	i	i+1
%endrep
