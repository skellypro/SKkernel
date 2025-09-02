/*
; * multiboot.inc
; *
; *  Created on: Mar 26, 2023
; *      Author: sean
; */

%ifndef INCLUDE_ASM_MULTIBOOT_INC_
%define INCLUDE_ASM_MULTIBOOT_INC_

.set MAGIC, 0x1BADB002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
	.long			MAGIC
	.long			FLAGS
	.long			CHECKSUM
/*	header_addr		db
;	load_addr		db
;	load_end_addr	db
;	bss_end_addr	db
;	entry_addr		db
;	mode_type		db
;	width			db
;	height			db
*/	depth			db

%endif ;INCLUDE_ASM_MULTIBOOT_INC_
