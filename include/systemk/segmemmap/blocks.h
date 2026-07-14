
#pragma once

#include <stdint.h>
#include <stddef.h>

#include "bit.h"
#include "segments.h"

#ifndef BLOCKS_PER_SEG
	#define BLOCKS_PER_SEG 256
#endif

#ifndef FULLFLAGS
	#define FULLFLAGS	UINT64_MAX | (UINT64_MAX << 64) | (UINT64_MAX << 128) | (UINT64_MAX << 192)
#endif

#ifndef MEMPOISON
#define MEMPOISON	0x8BADF00D//0xDEADD00D
#endif

//FIND A BETTER WAY TO DO THIS
#ifndef BLOCKPOISON
#define BLOCKPOISON	MEMPOISON | (MEMPOISON << 32) | (MEMPOISON << 64) | (MEMPOISON << 96)\
	 | (MEMPOISON << 128) | (MEMPOISON << 160) | (MEMPOISON << 192) | (MEMPOISON << 224)
#endif

namespace sk {
	class alignas(64) block {
	public:
		block();
		virtual block(const block&) = 0;
		virtual block& operator=(const block&) = 0;
		virtual ~block() = 0;
	};

	class alignas(block) dataBlock : block {
	public:
		// splitting the data block so it can be further managed when allocated
		[[gnu::packed]] union {
			volatile unsigned n : 512;
			volatile uint64_t _64[8];
			volatile uint32_t _32[16];
			volatile uint16_t _16[32];
			volatile uint8_t _8[64];
		};

		dataBlock();
		dataBlock(const dataBlock&);
		dataBlock& operator=(const dataBlock&);
		~dataBlock();
	};

	[[gnu::packed]] class alignas(block) metaBlock : block {
	public:
		volatile bit inUse;
		[[gnu::packed]] union alignas(32) {
			volatile bit freeFLAGS[BLOCKS_PER_SEG];
			volatile unsigned meta : BLOCKS_PER_SEG = 0;
		};
		segment* ThisSegment;
		segment* next;

		metaBlock();
		metaBlock(segment* newSegment = NULL, segment* newNext = NULL);

		metaBlock(const metaBlock&);
		metaBlock& operator=(const metaBlock&);

		~metaBlock();
	};
}