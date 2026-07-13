#include <mmap.h>

extern "C" {
    void * malloc(size_t n) {
        return NULL;
    }
}