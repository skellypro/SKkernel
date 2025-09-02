/*
 * system.h
 *
 *  Created on: Oct 28, 2023
 *      Author: sean
 */

#ifndef INCLUDE_SYSTEM_H_
#define INCLUDE_SYSTEM_H_

#include<systemk/arch/AMD64/idt.h>
#include<systemk/arch/AMD64/gdt.h>
#include<systemk/terminal.h>


extern "C"{
	namespace sk{
		class System{
		public:
			System();
			void init();

			void puts(const char * s) {
				tty.out.puts(s);
			};
			inline void * malloc(size_t size);
			inline void * calloc(size_t count, size_t eltsize);
			inline void free(void * ptr);

			inline ~System(){fini();};
		private:
			// Private members here
			Terminal tty[8];

			// Assembly functions go here

			// Destructor
			void fini();
		};
	}
}

#endif /* INCLUDE_SYSTEM_H_ */
