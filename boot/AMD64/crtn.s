/*
 * crtn.s
 *
 *  Created on: Nov 3, 2023
 *      Author: sean
 */

 .section .init
 	popl %rbp
 	ret

 .section .fini
 	popl %rbp
 	ret
