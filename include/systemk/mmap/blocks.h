
#pragma once

#include <stdint.h>
#include <stddef.h>

#include "bit.h"
#include "segments.h"

#ifndef BLOCKS_PER_SEG
	#define BLOCKS_PER_SEG 256
#endif

#ifndef FULLFLAGS
	#define FULLFLAGS	UINT64_MAX + (UINT64_MAX << 64) + (UINT64_MAX << 128) + (UINT64_MAX << 192)
#endif

#ifndef MEMPOISON
#define MEMPOISON	0x8BADF00D//0xDEADD00D
#endif

//FIND A BETTER WAY TO DO THIS
#ifndef BLOCKPOISON
#define BLOCKPOISON	MEMPOISON + (MEMPOISON << 32) + (MEMPOISON << 64) + (MEMPOISON << 96)\
	 + (MEMPOISON << 128) + (MEMPOISON << 160) + (MEMPOISON << 192) + (MEMPOISON << 224)
#endif

class alignas(64) block {
public:
	constexpr block();
	virtual ~block() = 0;
};
class alignas(block) dataBlock : block {
public:
	unsigned n : 512;

	constexpr dataBlock();
	~dataBlock() {
		n = BLOCKPOISON;
	}
};

class alignas(block) metaBlock : block {
public:
	bit inUse;
	union alignas(32) {
		bit freeFLAGS[BLOCKS_PER_SEG];
		unsigned meta : BLOCKS_PER_SEG = 0;
	};
	segment* ThisSegment;
	segment* next;

	constexpr metaBlock()
		: ThisSegment(NULL), next(NULL), meta(0), inUse(bit(1)) {
	}
	constexpr metaBlock(segment* newSegment = NULL, segment* newNext = NULL)
		: ThisSegment(newSegment), next(newNext), meta(0), inUse(bit(1)) {
	}

	constexpr ~metaBlock() {
		if (NULL != ThisSegment)
			ThisSegment->~segment();
		if (NULL != next)
			next->~segment();
		ThisSegment = next = NULL;
		meta = BLOCKPOISON;
		inUse.n = 0;
	}
};