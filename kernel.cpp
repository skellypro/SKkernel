/*
 * 	@Name:		System K : It's not UNIX, it's System K
 * 	@Author:	Sean Kelly
 * 	@Version:	0.0.0.1a
 */

#include<string.h>

#include<systemk/skcplus.h>
#include<skint.h>
#include<systemk/SKkernel.h>
#include<systemk/system.h>
#include<systemk/skversion.h>

using sk::System;

extern "C" {

	static System kernel;

	void kernel_main(void) {
		kernel.puts(VERSION_STRING_WELCOME);
		kernel.~System();
	}

	void init(){
		kernel.init();
	}
}
