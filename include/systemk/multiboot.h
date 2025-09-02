/*
 * multiboot.h
 *
 *  Created on: Feb 16, 2023
 *      Author: sean
 * Description: Structure for the multiboot header
 */

#ifndef _INCLUDE_MULTIBOOT_H_
#define _INCLUDE_MULTIBOOT_H_

typedef unsigned int u32;

#define ALIGN				1 << 0
#define MEMINFO				1 << 1
#define MULTIBOOT_MAGIC		0x1BADB002
#define FLAGS				ALIGN | MEMINFO
#define CHECKSUM			-(MULTIBOOT_MAGIC + FLAGS)

extern "C" typedef struct multiboot{
	u32 magic = MULTIBOOT_MAGIC,
		flags = FLAGS,
		checksum = CHECKSUM,
		header_addr,
		load_addr,
		load_end_addr,
		bss_end_addr,
		entry_addr,
		mode_type,
		width,
		height,
		depth;
}multiboot_header;

#endif
