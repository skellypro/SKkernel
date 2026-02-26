/*
 *
 */

#include <systemk/paging/pte.h>
#include <systemk/paging/pagetable.h>
#include <systemk/paging/pagedir.h>
#include <systemk/faults.h>

extern "C" {
	pte_t virt2phys(pid_t process_id, void* addr) {
		unsigned * intAddr = reinterpret_cast<unsigned *>(addr);
		// deconstruct the address
		unsigned * pageOffcet = intAddr & 0xfff,
			ptOffset = intAddr & 0x1ff000 >> 12,
			pdOffset = intAddr & 0x3fe00000 >> 21,
			pdptOffset = intAddr & 0x7fc0000000 >> 30,
			pml4Offset = intAddr & 0xff8000000000 >> 39;
		// reconstruct the address as a pointer to the page table entry
		pte_t *pteAddr = reinterpret_cast<pte_t *>((&[process_id][pml4Offset][pdptOffset][pdOffset][ptOffset]));
		// TODO: See if the page is there, otherwise throw a fault code.
		if (!pteAddr->present)
			throw page_fault_exception(process_id, 1);

		// send a copy of the page table entry to the parent
		return *pteAddr;
	}
}