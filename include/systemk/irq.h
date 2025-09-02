/*
 * irq.h
 *
 *  Created on: Dec 27, 2023
 *      Author: sean
 */

#ifndef INCLUDE_IRQ_H_
#define INCLUDE_IRQ_H_

#define	IRQ0	0x08	//system timer
#define	IRQ1	0x09	//keyboard
#define	IRQ2	0x0A	//PC/XT: EGA vertical retrace or maybe available
						//PC/AT:
#define	IRQ3	0x0B	//COM2 or maybe available
#define	IRQ4	0x0C	//COM1
#define	IRQ5	0x0D	//PC/XT: hard disk drive
						//PC/AT: LPT2 or maybe available
#define	IRQ6	0x0E	//floppy disk drive
#define	IRQ7	0x0F	//LPT1
#define	IRQ8	0x70	//PC/AT: CMOS Real Time Clock
#define	IRQ9	0x71	//PC/AT:
#define	IRQ10	0x72	//PC/AT: probably available
#define	IRQ11	0x73	//PC/AT: probably available
#define	IRQ12	0x74	//PC/AT: probably available
						//PS/2: mouse
#define	IRQ13	0x75	//PC/AT: numeric coprocessor
#define	IRQ14	0x76	//PC/AT: hard disk drive
#define	IRQ15	0x77	//PC/AT:

#endif /* INCLUDE_IRQ_H_ */
