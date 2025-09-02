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
		vga_out(register uint8_t	newFG = VGA_COLOR_LIGHT_GREY,
				register uint8_t		newBG = VGA_COLOR_BLACK);

		~vga_out();

		// Character output
		void putchar(register char);
		void putchar(register unsigned char);

		// String output
		void puts(register const char *);

		// Data Manipulation
		void setColor(register uint8_t	arg_d,
				register uint8_t	newColor);

		void backSpace(void);

		//buffer manipulation
		void clear(void);	// clear output buffer, put position to top y and x

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

				constexpr position(register size_t	newx = 0,
						register size_t	newy = 0)
				: width(VGA_WIDTH), height(VGA_HEIGHT), x(newx), y(newy) {
					toIndex();
				}

				constexpr position(const position &	p)
				:width(VGA_WIDTH), height(VGA_HEIGHT), x(p.x), y(p.y) {
					toIndex();
				}

				constexpr ~position() {
					x = y = i = width = height = 0;
				}

				constexpr void setX(register size_t newX) {
					x = newX;
					toIndex();
				}

				constexpr void setY(register size_t newY) {
					y = newY;
					toIndex();
				}

				constexpr void toIndex() {
					i = x * width + y;
				}

				position & operator ++(register int incr = 1);
				position & operator --(register int incr = 1);

				__attribute__((always_inline))
				inline bool operator <(const basic_position & p) {
					return (sizeof(&p) == sizeof(position)) && i <  ((position &)p).i;
					//return (y < p.y && x < p.x);
				};

				__attribute__((always_inline))
				inline bool operator >(const basic_position & p) {
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
		}__attribute__((packed));

		void initialize(register vga_color newFG, register vga_color newBG);

		bool isNewLine(register char	c);

		void carriageReturn(void);

		void scroll(void);

		void deleteLastLine(void);

		void deleteIndex(register const position &	p);

		void putentry(register char c);

		void write(register const char*	data,
				register size_t 			size);

		void writestring(register const char *	data);

		void touch(register size_t	i,
				register char		entry);

		void refresh();
	};

}

#endif /* INCLUDE_vga_out_H_ */
