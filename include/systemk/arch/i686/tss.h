#pragma once

#include "i686.h"

typedef struct _pm_tss_s_ {
	union {
		struct {
			_pm_tss_s_* link : 16;
			unsigned : 16;
			void* esp0 : 32,
				* ss0 : 16;
			unsigned : 16;
			void* esp1 : 32,
				* ss1 : 16;
			unsigned : 16;
			void* esp2 : 32,
				* ss2 : 16;
			unsigned : 16;
			unsigned cr3 : 32,
				eip : 32,
				eflags : 32,
				eax : 32,
				ebx : 32,
				ecx : 32,
				edx : 32;
			void* esp : 32,
				* ebp : 32,
				* esi : 32,
				* edi : 32,
				* es : 16;
			unsigned : 16;
			void* cs : 16;
			unsigned : 16;
			void* ss : 16;
			unsigned : 16;
			void* ds : 16;
			unsigned : 16;
			void* fs : 16;
			unsigned : 16;
			void* gs : 16;
			unsigned : 16;
			void* ldtr : 16;
			unsigned : 16,
				: 16;
			void* iobp  : 16,
				* ssp : 32;
		};
	};
} pm_tss;