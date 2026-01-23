/*
 * basic_out.cpp
 *
 *  Created on: Feb 7, 2024
 *      Author: sean
 * Last Change: Mar 17, 2025
 */

#include<systemk/basic_out.h>
namespace sk {

	extern "C" {

		/*
		basic_position::basic_position(size_t	newHeight,
									size_t		newWidth,
									size_t		newx = 0,
									size_t		newy = 0)
			:height(newHeight), width(newWidth), x(newx), y(newy) {}
		*/

		/*
		basic_position::basic_position(const basic_position & p) {
			height = p.height;
			width = p.width;
			x = p.x;
			y = p.y;
		}
		*/

		/*
				void basic_out::nextPosition(basic_position &	p) {
					p.x = (p.x + 1) % width;//maybe this instead of the next line? maybe some variant of it?
					p.y = (p.x == 0 && p.y < height - 1) ? p.y + 1 : p.y;
					//p.x = p.x < width - 1 ? p.x + 1 : 0;
					//if(p.x == 0 && p.y < height - 1)
					//	p.y++;
				}

				void basic_out::lastPosition(basic_position &	p) {
					//p.x = (p.x - 1) % width;
					p.x = (p.x == 0) ? width - 1 : p.x - 1;
					if(p.x == width - 1)
						if(p.y == 0)
							p.x = 0;
						else
							p.y--;

				}
		*/

		/*basic_out::~basic_out() {
			width = height = 0;
			buffer = NULL;
		}*/

	}

}
