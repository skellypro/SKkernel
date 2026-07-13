/*
 *
 */
#pragma once

#include "pagetable.h"

typedef struct alignas(4096) pd_t {
	volatile pt_t entries[512];
} pagedir;