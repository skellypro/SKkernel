/*
 * nextPosition.cpp
 *
 *  Created on: Feb 7, 2024
 *      Author: sean
 * Last Change: Mar 17, 2025
 */

#include<systemk/vga_out.h>

namespace sk {
	/*
	vga_out::position::position(register size_t	newx = 0,
								register size_t	newy = 0)
				: width(VGA_WIDTH), height(VGA_HEIGHT), x(newx), y(newy) {
		toIndex();
	}
	*/

	/*
	vga_out::position::~position() {
		x = y = i = width = height = 0;
	}
	*/

	/*
	void vga_out::position::setX(register size_t newX) {
		x = newX;
		toIndex();
	}

	void vga_out::position::setY(register size_t newY) {
		y = newY;
		toIndex();
	}
	*/

	vga_out::position & vga_out::position::operator ++(register int incr = 1){
		y = (x + incr <= height && y < height - 1) ? y + 1 : y;
		x = (x + incr) % width;//maybe this instead of the next line? maybe some variant of it?
		//p.x = p.x < width - 1 ? p.x + 1 : 0;
		toIndex();
		return (position&)this;
	}

	vga_out::position & vga_out::position::operator --(register int incr = 1){
		x = (x <= 0) ? (width - 1) - (x - incr) : x - incr;
		if(x == width - 1)
			if(y == 0)
				x = 0;
			else
				y--;
		toIndex();
		return (position&)this;
	}

/*
	void vga_out::nextPosition(position &	p) {
		basic_out::nextPosition((basic_position &)p);
		p.i = p.toIndex(width);
	}

	void vga_out::lastPosition(position &	p) {
		basic_out::lastPosition((basic_position &)p);
		p.i = p.toIndex(width);
	}
*/
}
