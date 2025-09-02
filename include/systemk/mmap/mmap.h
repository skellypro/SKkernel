// bmpmalloc.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <stdint.h>
#include <stddef.h>

#include "bit.h"
#include "blocks.h"
#include "segments.h"

#ifndef fastcall
#define fastcall _fastcall
#endif

static class alignas(memmap::mapdata) memmap {
public:
	memmap();
	~memmap();
private:
	struct mapdata {
		segment* start;
	};

	inline size_t findFistFree(register segment* seg, register uint8_t i = 0) {
		seg = findFreeSeg(seg);
		while (/*seg->MetaBlock.freeFLAGS[i].n */)
			i++;
		return i;
	}
	
	constexpr segment* findFreeSeg(segment* seg) {
		if (FULLFLAGS == seg->MetaBlock.meta)
			if (NULL == seg->MetaBlock.next) {
				makeNewSeg(seg);
				seg = seg->MetaBlock.next;
			}
			else
				findFreeSeg(seg->MetaBlock.next);
		return seg;
	}

	inline void makeNewSeg(register segment* seg) {
		seg->MetaBlock.next = seg;
		seg->MetaBlock.next++;
		*(seg->MetaBlock.next) = segment();
	}
} MemMap;