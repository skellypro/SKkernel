/*
 *
 */

#include <stdint.h>
#include <stddef.h>

#include <systemk/segmemmap/segmemmap.h>

namespace sk::segmemmap {
    segmemmap::segmemmap() {}

    segmemmap::~segmemmap() {}

    void* segmemmap::alloc(size_t) {
        return NULL;
    }

    void* segmemmap::realloc(void*, size_t) {
        return NULL;
    }

    void segmemmap::free(void * p) {
        return NULL;
    }
}