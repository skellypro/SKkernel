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

	[[fastcall]]
	void vga_out::putchar(char c) {
		if(!isNewLine(c))
			putentry(c);
	}

	[[fastcall]]
	void vga_out::putentry(char c) {
		touch(pos.i, c);
		pos++;
	}

	[[fastcall]]
	void vga_out::write(const char* data, size_t size) {
		for (size_t i = 0; i < size; i++)
			this.putchar(data[i]);
	}

	[[fastcall]]
	void vga_out::writestring(const char* data) {
		write(data, strlen(data));
	}

}
