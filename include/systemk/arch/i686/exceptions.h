#pragma once

#include "i686.h"

#define _DE 0X0				// Division Error
#define _DB 0X1				// Debug
#define _NONMASKINT 0X2		// Non-maskable Interrupt
#define _BP 0X3				// Breakpoint
#define _OF 0X4				// Overflow
#define _BR 0x5				// Bound Range Exceeded
#define _UD 0x6				// Invalid Opcode
#define _NM 0x7				// Device Not Available
#define _DF 0X8				// Double Fault
#define _COPRSEGOV 0X9		// Coprocessor Segment Overrun (older machines)
#define _TS 0XA				// Invalid TSS
#define _NP 0XB				// Segment Not Present
#define _SS 0XC				// Stack-Segment Fault
#define _GP 0XD				// General Protection Fault
#define _PF 0XE				// Page Fault
#define _MF 0X10			// x87 Floating-Point Exception
#define _AC 0X11			// Alignment Check
#define _MC 0X12			// Machine Check
#define _XM 0X13			// SIMD Floating-Point Exception
#define _XF XM				// see _XM
#define _CP 0X15			// Control Protection Exception
#define _HV 0X1C			// Hypervisor Injection Exception
#define _VC 0X1D			// VMM Communication Exception
#define _SX 0X1E			// Security Exception


typedef struct alignas(sizeof(unsigned long long)) _page_fault_error_code_struct {
	union {
		struct {
			unsigned p : 1;
			unsigned w : 1;
			unsigned u : 1;
			unsigned resrvedwrite : 1;
			unsigned i : 1;
			unsigned pk : 1;
			unsigned ss : 1;
			unsigned : 7;
			unsigned sgx : 1;
		};
		unsigned long long value;

	};
} page_fault_code;

typedef struct alignas(sizeof(unsigned long long)) _selector_error_code_s_ {
	union {
		unsigned long long;
		struct {
			unsigned e : 1;
			unsigned tbl : 2;
			unsigned index : 13;
		};
	};
} selector_error_code;