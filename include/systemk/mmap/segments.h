
#pragma once

#include <stdint.h>
#include <stddef.h>

#include "bit.h"
#include "blocks.h"

#ifndef BLOCKS_PER_SEG
	#define BLOCKS_PER_SEG 256
#endif //BLOCKS_PER_SEG

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

class alignas(16384) segment {
public:
	virtual segment() = 0;
	virtual  ~segment() = 0;
};

class alignas(segment) metaSegment : segment{
public:
	 metaSegment() {
		bitMaps[0].ThisSegment = this;
		bitMaps[0].freeFLAGS[0].n = 1;
	}

	 ~metaSegment() {
		for (register uint8_t i = BLOCKS_PER_SEG - 1; 1 <= i; i--)
			bitMaps[i].~metaBlock();
		bitMaps[0].ThisSegment = NULL;
		bitMaps[0].~metaBlock();
	}
	metaBlock bitMaps[BLOCKS_PER_SEG] = {};
};

class alignas(segment) dataSegment : segment {
public:
	 dataSegment() {
		for (register uint8_t i = BLOCKS_PER_SEG - 1; i; i--)
			memBlock[i].n = BLOCKPOISON;
	};

	 ~dataSegment() {
		for (register uint8_t i = BLOCKS_PER_SEG - 1; i; i--)
			memBlock[i].n = BLOCKPOISON;
	}
	dataBlock memBlock[BLOCKS_PER_SEG] = {};
};