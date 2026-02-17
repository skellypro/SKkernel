#pragma once

#include <cstdint>

#ifdef x86 || i686 || i586 || i486 || i386
inline uint32_t [[gnu::fastcall]] [[msvc::__fastcall]]
systemcall(uint32_t c, uint32_t d) {
	int32_t [[no_unique_address]]result;
	asm volatile (
			"syscall"
		: "=a"(result) : "c"(c), "d"(d)
		)
	return result;
}
#elifdef x86_64 || amd64 || AMD64
inline uint64_t [[gnu::fastcall]] [[msvc::__fastcall]]
systemcall(uint64_t c, uint64_t d) {
	int64_t [[no_unique_address]]result;
	asm volatile (
			"syscall"
		: "=a"(result) : "c"(c), "d"(d)
		)
	return result;
}
#endif