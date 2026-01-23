// bmpmalloc.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <stdint.h>
#include <stddef.h>

#include "bit.h"
#include "blocks.h"
#include "segments.h"

[[gnu::visibility(hidden)]] static class alignas(memmap::mapdata) memmap {
public:
	memmap();
	~memmap();

	void * alloc(size_t);
	void * realloc(void *, size_t);
	void * free(void *);
private:
	[[gnu::packed]] struct mapdata {
		segment* start;
	};

	// TODO: implement based on new segment family
	[[gnu::fastcall]] inline size_t findFistFree(segment* seg, uint8_t i = 0) {
		seg = findFreeSeg(seg);
		while (/*seg->MetaBlock.freeFLAGS[i].n */)
			i++;
		return i;
	};
	
	// TODO: rewrite without recursion based on new segment class family
	[[gnu::fastcall]] segment* findFreeSeg(segment* seg) {
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
} MemMap;