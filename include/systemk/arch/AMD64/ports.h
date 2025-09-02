/*
 * ports.h
 *
 *  Created on: Jan 19, 2024
 *      Author: sean
 */

#ifndef INCLUDE_ARCH_AMD64_PORTS_H_
#define INCLUDE_ARCH_AMD64_PORTS_H_

#define	MASTER_PIC_CONTROL	0X20
#define	MASTER_PIC_MASK		0X21

#define	SLAVE_PIC_CONTROL	0XA0
#define	SLAVE_PIC_MASK		0XA1

#define	KEYBOARD_DATA		0X60
#define	KEYBOARD_COMMAND	0X64

#define	SYSTEM_CONTROL_A	0X92

#endif /* INCLUDE_ARCH_AMD64_PORTS_H_ */
