/*
 *
 */

#include <stdint.h>
#include <stddef.h>

#include <systemk/mmap.h>

mmap::mmap(){}

mmap::~mmap(){}

void * mmap::alloc(size_t) {
    return NULL;
}

void * mmap::realloc(void *, size_t) {
    return NULL;
}

void * mmap::free(void *) {
    return NULL;
}