#pragma once

#include <cstdint>

#include <systemk/pagetable/pte_flags.h>

typedef struct pte_t {
	union {
#ifdef x86 || i686 || i586 || i486 || i386
		uint32_t value;
		struct {
			unsigned present : 1;				// present in memory
			unsigned rw : 1;					// read/write
			unsigned user : 1;					// user/superuser
			unsigned write_through : 1;			// write-through caching
			unsigned cache_disable : 1;			// cache disable
			unsigned accessed : 1;				// accessed
			unsigned dirty : 1;					// dirty bit
			unsigned pat : 1;					// page attribute table
			unsigned global : 1;				// global page
			unsigned available : 3;				// available for system programmer's use
			unsigned page_frame_number : 20;	// page frame number (shifted right 12 bits)
		};
#elifdef x86_64 || amd64 || AMD64
		uint64_t value;
		struct {
			unsigned present : 1;				// present in memory
			unsigned rw : 1;					// read/write
			unsigned user : 1;					// user/superuser
			unsigned write_through : 1;			// write-through caching
			unsigned cache_disable : 1;			// cache disable
			unsigned accessed : 1;				// accessed
			unsigned dirty : 1;					// dirty bit
			unsigned pat : 1;					// page attribute table
			unsigned global : 1;				// global page
			unsigned available : 3;				// available for system programmer's use
			unsigned page_frame_number : 40;	// page frame number (shifted right 12 bits)
		};
#endif
	}[[gnu::packed]] [[msvc::__packed]];
} pte;