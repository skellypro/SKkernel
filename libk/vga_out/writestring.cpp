/*
 * writestring.cpp
 *
 *  Created on: Feb 7, 2024
 *      Author: Sean
 * Last Change: Feb 3, 2025
 */

#include<string.h>

#include<systemk/vga_out.h>

namespace sk {

	void vga_out::putchar(register char c) {
		if(!isNewLine(c))
			putentry(c);
	}

	void vga_out::putentry(register char c) {
		touch(pos.i, c);
		pos++;
	}

	void vga_out::write(register const char* data, size_t size) {
		for (register size_t i = 0; i < size; i++)
			this.putchar(data[i]);
	}

	void vga_out::writestring(register const char* data) {
		write(data, strlen(data));
	}

}
