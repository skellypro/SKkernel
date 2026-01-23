/*
 * vga_out.cpp
 *
 *  Created on: Oct 30, 2023
 *      Author: sean
 * Last Change: Mar 24, 2025
 */

#include<stddef.h>

//#include<basic_out.h>
#include<systemk/vga_out.h>

namespace sk {

	vga_out::vga_out(register uint8_t	newFG = VGA_COLOR_LIGHT_GREY,
					register uint8_t		newBG = VGA_COLOR_BLACK)
	: pos(position()) {
		initialize((vga_color)newFG, (vga_color)newBG);
	}

	vga_out::~vga_out() {
		clear();
	}

	void vga_out::puts(register const char *	s) {
		writestring(s);
	}

	void vga_out::backSpace(void) {
		deleteIndex(--pos);
	}

	//TODO rewrite this so it works.
	void vga_out::clear(void) {
		register const position CONDITION = position(pos.Width() - 1, pos.Height() - 1);
		for(register position i = pos = position();
				i < CONDITION;
				i++)
			deleteIndex(i);
		pos = position(VGA_WIDTH, VGA_HEIGHT);
	}

	void vga_out::initialize(register vga_color newFG, register vga_color newBG) {
		fg = newFG;
		bg = newBG;
		const register position CONDITION = position(pos.Width() - 1, pos.Width() - 1);
		for(register position i = position();
				i < CONDITION;
				i++){
			BUFFER[i].color = color;
			BUFFER[i].uc = '\0';
		}
		pos = position();
	}

	//TODO
	void vga_out::carriageReturn(void) {
		if(pos.Y() == pos.Height() - 1){
			scroll();
		}else
			pos.setY(pos.Y() + 1);
			//pos.y++;

		//pos.x = 0;
		pos.setX(0);
	}

	//TODO
	bool vga_out::isNewLine(register char	c) {
		if(c == '\n'){
			touch(pos.i, c);
			carriageReturn();
			return true;
		}
		return false;
	}

	void vga_out::deleteLastLine(void) {
		const register position CONDITION = position(pos.Width() - 1, pos.Height() - 1);
		for(register position i = position(0, pos.height - 1);
				i < CONDITION;
				i++)
			deleteIndex(i);
	}

	void vga_out::deleteIndex(register const position &	p) {
		touch(p.i, '\0');
	}

	void vga_out::touch(register size_t	i,
						register char	entry) {
		BUFFER[i].uc = (unsigned char)entry;
	}

	
	void vga_out::refresh() {
		const position CONDITION = position(pos.Width() - 1, pos.Height() - 1);
		for(position i = position();
				i < CONDITION;
				i++) {
			BUFFER[i].color = color;
		}
		
		for(size_t i = 0; TTY_BUFFER_SIZE> i; i++)
			this.putchar(characterBuffer[i]);
	}
}
