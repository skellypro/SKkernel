/*
 * vga.h
 *
 *  Created on: Jan 20, 2023
 *      Author: sean
 * Last Change: Sep 9, 2024
 */

#ifndef INCLUDE_ASM_VGA_H_
#define INCLUDE_ASM_VGA_H_

#include<stddef.h>
#include<stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

#define VGA_OUT  0x000B8000

enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

static inline uint8_t vga_entry_color(enum vga_color	fg,
									enum vga_color		bg) {
	return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char	uc,
									uint8_t		color) {
	return (uint16_t) uc | (uint16_t) color << 8;
}

//TODO: figure out how to put this into class vga_out
//		my god... what have I done?
union vga_entry_t {
	uint16_t v;
	struct {
		unsigned char uc;
		union {
			uint8_t color;
			struct {
				vga_color fg : 4, bg : 4;
			};
		}__attribute__((packed));
	};
}__attribute__((packed));

#endif /* INCLUDE_ASM_VGA_H_ */
