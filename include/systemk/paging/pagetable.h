/*
 *
 */
#pragma once

#include "pte.h"


typedef struct alignas(4096) pt_t {
	volatile pte_t entries[512];
} pagetable;

typedef 