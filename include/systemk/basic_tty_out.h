/*
 * basic_tty_out.h
 *
 * 	 Created on: 		Oct 29, 2024
 *     	 Author: 	sean
 *	Last Change: 	Feb 3, 2025
 */

#ifndef INCLUDE_BASIC_TTY_OUT_H_
#define INCLUDE_BASIC_TTY_OUT_H_

#include<stddef.h>
#include<stdint.h>

#include<systemk/basic_out.h>

namespace sk {

	class basic_tty_out : basic_out {
	public:

		// Character output
		virtual void putchar(char) = 0;
		virtual void putchar(unsigned char) = 0;

		// String output
		virtual void puts(const char *) = 0;

		virtual void backSpace(void) = 0;

		//buffer manipulation
		virtual void clear(void) = 0;	// clear output buffer, put position to top y and x
		
		size_t TTY_BUFFER_SIZE = 100;
		char characterBuffer[TTY_BUFFER_SIZE];
	private:
		virtual bool isNewLine(char	c) = 0;
	};

}

#endif /* INCLUDE_BASIC_TTY_OUT_H_ */
