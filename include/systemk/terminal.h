/*
 * terminal.h
 *
 *  Created on: Apr 16, 2023
 *      Author: sean
 */

#ifndef INCLUDE_TERMINAL_H_
#define INCLUDE_TERMINAL_H_

#include<stddef.h>

#include<systemk/basic_terminal.h>
#include<systemk/vga_out.h>
#include<systemk/in.h>

namespace sk {

	//TODO
	class Terminal : basic_terminal{
	public:
		Terminal();
		basic_out& out;
		In in;
	private:
	};

}
#endif /* INCLUDE_TERMINAL_H_ */
