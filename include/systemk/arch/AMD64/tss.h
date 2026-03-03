#pragma once

#include "../i686/tss.h"

/************************************************************************
* Long mode task state segment 
************************************************************************/
typedef struct _lm_tss_s_ {
	union {
		unsigned : 832;
		struct {
			unsigned : 32;				// reserved
			// stack pointers
			void* rsp0l : 32,			// stack pointer 0, lower end
				* rsp0h : 32,			// stack pointer 0, high end
				* rsp1l : 32,			// stack pointer 1, lower end
				* rsp1h : 32,			// stack pointer 1, high end
				* rsp2l : 32,			// stack pointer 2, lower end
				* rsp2h : 32;			// stack pointer 2, high end
			unsigned : 32, : 32;		// reserved
			// interrupt stack table
			void* ist1l : 32,			// 
				ist1h : 32,				// 
				ist2l : 32,				// 
				ist2h : 32,				// 
				ist3l : 32,				// 
				ist3h : 32,				// 
				ist4l : 32,				// 
				ist4h : 32,				// 
				ist5l : 32,				// 
				ist5h : 32,				// 
				ist6l : 32,				// 
				ist6h : 32,				// 
				ist7l : 32,				// 
				ist7h : 32;				// 
			unsigned : 32, : 32, : 16;	// reserved
			void* iopb : 16;			// 
		};
	};
} lm_tss;