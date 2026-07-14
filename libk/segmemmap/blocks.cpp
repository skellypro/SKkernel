#include <systemk/segmemmap/blocks.h>

namespace sk {

	dataBlock::~dataBlock() {
		n = BLOCKPOISON;
	}

	dataBlock(const dataBlock& other) {
		*this = other;
	}

	dataBlock& operator=(const dataBlock& other) {
		if (&this != &other) {
			n = other.n;
		}
		return *this;
	}

	metaBlock::metaBlock()
	: ThisSegment(NULL), next(NULL), meta(0), inUse({ 1 }) {}

	metaBlock::metaBlock(segment* newSegment = NULL, segment* newNext = NULL)
	: ThisSegment(newSegment), next(newNext), meta(0), inUse({ 1 }) {}


	metaBlock(const metaBlock& other) {
		*this = other;
	}

	metaBlock& operator=(const metaBlock& other) {
		if (&this != &other) {
			ThisSegment = other.ThisSegment;
			next = other.next;
			meta = other.meta;
			inUse = other.inUse;
		}
		return *this;
	}

	metaBlock::~metaBlock() {
		if (NULL != ThisSegment)
			ThisSegment->~segment();
		if (NULL != next)
			next->~segment();
		ThisSegment = next = NULL;
		meta = BLOCKPOISON;
		inUse.n = 0;
	}
}