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
		size_t findFistFree(segment* seg, uint8_t i = 0);

		// TODO: rewrite without recursion based on new segment class family
		segment* findFreeSeg(segment* seg);

		// TODO: map out based on hardware
		void makeNewSeg(segment* seg);

		size_t getTotalRAM();
	};
}