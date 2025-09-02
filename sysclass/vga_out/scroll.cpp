/*
 * scroll.cpp
 *
 *  Created on: Feb 7, 2024
 *      Author: sean
 * Last Change: Mar 24, 2025
 */

#include<systemk/vga_out.h>

namespace sk {

	//TODO double check this to make sure that touch call is right
	void vga_out::scroll(void) {
		const register position CONDITION = position(pos.Width() - 1, pos.Height() - 2);
		for(register position i = position();
				i < CONDITION;
				i++) {
			touch(i.i, BUFFER[position(i.X(), i.Y() + 1).i].uc);
			//buffer[i.toIndex(width)] = buffer[i.i];
		}

		deleteLastLine();
	}

}
