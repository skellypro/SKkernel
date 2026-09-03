/*
 * vga_out.h
 *
 *  Created on: Oct 30, 2023
 *      Author: sean
 * Last Change: Mar 24, 2025
 */

#ifndef INCLUDE_VGA_OUT_H_
#define INCLUDE_VGA_OUT_H_

#include<stddef.h>

#include<systemk/basic_tty_out.h>
#include<systemk/asm/vga.h>

namespace sk{

	class vga_out : basic_tty_out {
	public:
		vga_out(uint8_t	newFG = VGA_COLOR_LIGHT_GREY,
				uint8_t		newBG = VGA_COLOR_BLACK);

		~vga_out();

		// Character output
		[[fastcall]] void putchar(char);
		[[fastcall]] void putchar(unsigned char);

		// String output
		[[fastcall]] void puts(const char *);

		// Data Manipulation
		[[fastcall]] void setColor(uint8_t	arg_d,
				uint8_t	newColor);

		void backSpace(void);

		//buffer manipulation
		void clear(void);	// clear output buffer, put position to top y and x
		void refresh_color();

		//position & nextPosition(position * p);
	private:
		//iterator to handle cursor position:
		// TODO:	Rewrite to incorporate protected data
		//			include the new constexpr toIndex() every time x and y is changed
		//			REWRITE TO INCLUDE height AND width
		//			REWRITE operator > AND <
		class position : basic_position{
			public:
				size_t i;

				position(size_t	newx = 0,
						size_t	newy = 0)
				: width(VGA_WIDTH), height(VGA_HEIGHT), x(newx), y(newy) {
					toIndex();
				}

				position(const position &	p)
				:width(VGA_WIDTH), height(VGA_HEIGHT), x(p.x), y(p.y) {
					toIndex();
				}

				~position() {
					x = y = i = width = height = 0;
				}

				[[always_inline]] void setX(size_t newX) {
					x = newX;
					toIndex();
				}

				[[always_inline]] void setY(size_t newY) {
					y = newY;
					toIndex();
				}

				[[always_inline]] void toIndex() {
					i = x * width + y;
				}

				position & operator ++(int incr = 1);
				position & operator --(int incr = 1);

				[[always_inline]] bool operator <(const basic_position & p) {
					return (sizeof(&p) == sizeof(position)) && i <  ((position &)p).i;
					//return (y < p.y && x < p.x);
				};

				[[always_inline]] bool operator >(const basic_position & p) {
					return (sizeof(&p) == sizeof(position)) && i > ((position &)p).i;
				}

			} pos;

		//TODO: implement this for vga entries
		const vga_entry_t * BUFFER = VGA_OUT;

		union {
			uint8_t color;
			struct {
				unsigned fg : 4,
					bg : 4;
			};
		}[[gnu::packed]];

		[[fastcall]] void initialize(vga_color newFG, vga_color newBG);

		[[fastcall]] bool isNewLine(char	c);

		void carriageReturn(void);

		void scroll(void);

		void deleteLastLine(void);

		[[fastcall]] void deleteIndex(const position &	p);

		[[fastcall]] void putentry(char c);

		[[fastcall]] void write(const char*	data,
				size_t	size);

		[[fastcall]] void writestring(const char *	data);

		[[fastcall]] void touch(size_t	i,
				char	entry);

		void refresh();
	};

}

#endif /* INCLUDE_vga_out_H_ */
