/*
 *
 */

#include <stdint.h>
#include <stddef.h>

#include <systemk/segmemmap/segmemmap.h>

namespace sk::segmemmap {
    /********************************************************************************************\
     * Public domain.
    \********************************************************************************************/
    segmemmap::segmemmap() {
		volatile size_t totalRAM = getTotalRAM();
    }

    segmemmap::~segmemmap() {}

    void* segmemmap::alloc(size_t allocSize) {
		volatile segment* seg = mapdata.start;
        volatile void * p = findFirstFree(seg);
        do 
            if (allocSize <= sizeof(*p))
			    return p;
			else
				p = findFirstFree(seg);
		while(nullptr != p);
        return NULL;
    }

    void* segmemmap::realloc(void*, size_t) {
        return NULL;
    }

    void segmemmap::free(void * p) {
        return NULL;
    }

    /********************************************************************************************\
     * Private domain.
    \********************************************************************************************/
    size_t segmemmap::findFistFree(segment** seg) {
        volatile uint8_t i = 0;
        volatile uint8_t j = i;
        *seg = findFreeSeg(*seg);
        while () {
            while(seg->)
            i++;
        }
        return i;
    }

    segment* segmemmap::findFreeSeg(segment* seg) {
        if (FULLFLAGS == seg->MetaBlock.meta)
            if (NULL == seg->MetaBlock.next) {
                makeNewSeg(seg);
                seg = seg->MetaBlock.next;
            }
            else
                findFreeSeg(seg->MetaBlock.next);
        return seg;
    }

    void segmemmap::makeNewSeg(segment* seg) {
        seg->MetaBlock.next = seg;
        seg->MetaBlock.next++;
        *(seg->MetaBlock.next) = segment();
    }

    size_t getTotalRAM() {
        // put the interrupt to get the ram from the BIOS.
#ifdef PCBIOS
        return basic_interrupt(MEM_CHECK, 0, 0, 0, 0, get_si(), get_di());
        // future versions will use more modern approaches to getting the RAM.
#endif
    }
}