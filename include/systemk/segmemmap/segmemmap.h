#pragma once

#include <stdint.h>
#include <stddef.h>

#include <systemk/arch/interrupt.h>
#include <systemk/asm/getregister.h>

#include "bit.h"
#include "blocks.h"
#include "segments.h"

namespace sk::segmemmap {
	class alignas(segmemmap::mapdata) segmemmap {
	public:
		segmemmap();
		~segmemmap();

		void* alloc(size_t);
		void* realloc(void*, size_t);
		void free(void*);
	private:
		[[gnu::packed]] struct mapdata {
			volatile segment* start;
		};

		// TODO: implement based on new segment family
		[[always_inline]] inline size_t findFistFree(segment* seg, uint8_t i = 0) {
			seg = findFreeSeg(seg);
			while (/*seg->MetaBlock.freeFLAGS[i].n */)
				i++;
			return i;
		};

		// TODO: rewrite without recursion based on new segment class family
		[[always_inline]] segment* findFreeSeg(segment* seg) {
			if (FULLFLAGS == seg->MetaBlock.meta)
				if (NULL == seg->MetaBlock.next) {
					makeNewSeg(seg);
					seg = seg->MetaBlock.next;
				}
				else
					findFreeSeg(seg->MetaBlock.next);
			return seg;
		};

		// TODO: map out based on hardware
		inline void makeNewSeg(segment* seg) {
			seg->MetaBlock.next = seg;
			seg->MetaBlock.next++;
			*(seg->MetaBlock.next) = segment();
		};

		[[always_inline]] size_t getTotalRAM() {
			// put the interrupt to get the ram from the BIOS.
#ifdef PCBIOS
			return basic_interrupt(MEM_CHECK, 0, 0, 0, 0, get_si(), get_di());
			// future versions will use more modern approaches to getting the RAM.
#endif
		};
	};
}