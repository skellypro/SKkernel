/*
 * basic_out.h
 *
 *  Created on: Jan 10, 2024
 *      Author: sean
 * Last Change: Mar 24, 2025
 */

#ifndef INCLUDE_BASIC_OUT_H_
#define INCLUDE_BASIC_OUT_H_

#include<stddef.h>
#include<stdint.h>

namespace sk {

	extern "C" {

		class basic_position{
		public:

			constexpr basic_position(size_t	newHeight,
						size_t		newWidth,
						size_t		newx = 0,
						size_t		newy = 0)
			:height(newHeight), width(newWidth), x(newx), y(newy) {}

			constexpr basic_position(const basic_position & p)
			:height(p.height), width(p.width), x(p.x), y(p.y) {}

			constexpr size_t Height() {
				return height;
			}

			constexpr size_t Width() {
				return width;
			}

			constexpr size_t X() {
				return x;
			}

			constexpr size_t Y() {
				return y;
			}

			inline void setWidth(register size_t newWidth) {
				width = newWidth;
			}

			inline void setHeight(register size_t newHeight) {
				height = newHeight;
			}

			virtual void setX(register size_t newX) = 0;

			virtual void setY(register size_t newY) = 0;

			virtual basic_position & operator ++(register int incr = 1) = 0;

			virtual basic_position & operator --(register int incr = 1) = 0;

			virtual bool operator >(const basic_position &) = 0;

			virtual ~basic_position() = 0;

		private:
			size_t x, y,
				height, width;

		};

		class basic_out {
		public:
			//TODO
			basic_out() = 0;

			virtual ~basic_out() = 0;

			virtual void refresh() = 0;
		};

	}

}
#endif /* INCLUDE_BASIC_OUT_H_ */
