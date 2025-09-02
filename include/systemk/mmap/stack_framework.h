
#pragma once

#include <stdint.h>
#include <stddef.h>

typedef struct alignas(16) {} stack_entry_t;

#ifdef AMD64
typedef struct /*alignas(6291456)*/ { stack_entry_t alignas(16) stack[393216] = {}; } stackSegment;
#elif #defined (i686)
typedef struct /*alignas(3145728)*/ { stack_entry_t alignas(16) stack[196608] = {}; } stackSegment;
#elif #defined (i80486)
typedef struct /*alignas(16384)*/ { stack_entry_t alignas(16) stack[1024] = {}; } stackSegment;
#endif