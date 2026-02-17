#pragma once

#include <cstdint>

#include <systemk/pagetable/pte_flags.h>

typedef struct pte_t {
	union {
#ifdef x86 || i686 || i586 || i486 || i386
		uint32_t value;
		struct {
		};
#elifdef x86_64 || amd64 || AMD64
		uint64_t value;
		struct {
		};
#endif
	}[[gnu::packed]] [[msvc::__packed]];
} pte;