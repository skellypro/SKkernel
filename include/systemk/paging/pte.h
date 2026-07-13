/*
 *
 */
#pragma once

#include <cstdint>

#include <systemk/pagetable/pte_flags.h>

typedef struct pte_t {
	union {
#ifdef x86 || i686 || i586 || i486 || i386
		volatile uint32_t value;
		struct {
			volatile unsigned present : 1;				// present in memory
			volatile unsigned rw : 1;					// read/write
			volatile unsigned user : 1;					// user/superuser
			volatile unsigned write_through : 1;			// write-through caching
			volatile unsigned cache_disable : 1;			// cache disable
			volatile unsigned accessed : 1;				// accessed
			volatile unsigned dirty : 1;					// dirty bit
			volatile unsigned pat : 1;					// page attribute table
			volatile unsigned global : 1;				// global page
			volatile unsigned available : 3;				// available for system programmer's use
			volatile unsigned page_frame_number : 20;	// page frame number (shifted right 12 bits)
		};
#elifdef x86_64 || amd64 || AMD64
		volatile uint64_t value;
		struct {
			volatile unsigned present : 1;				// present in memory
			volatile unsigned rw : 1;					// read/write
			volatile unsigned user : 1;					// user/superuser
			volatile unsigned write_through : 1;			// write-through caching
			volatile unsigned cache_disable : 1;			// cache disable
			volatile unsigned accessed : 1;				// accessed
			volatile unsigned dirty : 1;					// dirty bit
			volatile unsigned pat : 1;					// page attribute table
			volatile unsigned global : 1;				// global page
			volatile unsigned available : 3;				// available for system programmer's use
			volatile unsigned page_frame_number : 40;	// page frame number (shifted right 12 bits)
		};
#endif
	}[[gnu::packed]] [[msvc::__packed]];
} pte;