/*
 * setColor.cpp
 *
 *  Created on: Feb 7, 2024
 *      Author: sean
 * Last Change: Feb 3, 2025
 */

#include<systemk/vga_out.h>

namespace sk {

	/*
	 * void vga_out::refresh()
	 * This function takes no arguments
	 *
	 * This functions refreshes the color of the terminal
	 */
	void vga_out::refresh() {
		const register position CONDITION = position(pos.Width() - 1, pos.Height() - 1);
		for(register position i = position();
				i < CONDITION;
				i++) {
			BUFFER[i].color = color;
		}
	}

	/*
	 * void vga_out::setColor(uint8_t arg_d, uint_t newcolor)
	 * arg_d -		This will be an unsigned integer that tells where
	 * 		   the next argument will go
	 * 		   The conditions are as follows:
	 * 		   0 - change BUFFER[i].bg
	 * 		   1 - change BUFFER[i].fg
	 * 		   2 - change BUFFER[i].color
	 * newColor -	The new color to set
	 *
	 * After checking where the argument will go, change the color
	 * for the screen, but only to bg or fg based on the results
	 * of the test of arg_d.
	 *
	 * The function returns no value
	 */
	void vga_out::setColor(register uint8_t arg_d, register uint8_t newColor) {
		switch (arg_d) {
		case 0:
			bg = newColor;
			break;
		case 1:
			fg = newColor;
			break;
		case 2:
			color = newColor;
			break;
		default:
			break;
		}
		refresh();
	}

}
