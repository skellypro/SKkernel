/*
 * systemcall.h
 * @author: Sean Kelly
 * Date Created: 17FEB2026
 * 
 * WARNING::
 * This file is intended to be included only in COODOS,
 * and will not behave properly in user space. This header is in
 * no way portable.
 */

#pragma once

/*
 * Only use integers for the template parameters.
 */

[[always_inline]]
template <class T>
inline T systemcall(T ra, T rb, T rc, T rd, void * rs, void * rD) {
	auto result;

#ifdef (__GNU__ || __clang__ || __MINGW64__ || __GNUC__) && \
	(AMD64 || x86_64 || x86 || PENTIUM2 || K6)
	asm volatile (
		"syscall"
		: "=a" (result)
		: "a" (ra), "b" (rb), "c" (rc), "d" (rd), "S" (rs), "D" (rD)
		: "memory"
		);
#elifdef (__GNU__ || __clang__ || __MINGW32__ || __GNUC__) && \
	(i686 || i586 || i486 || i386 || i286 || i8086 || i8088 || i8080) // a few of these will stay
	asm volatile (
		"int $0x80"
		: "=a" (result)
		: "a" (ra), "b" (rb), "c" (rc), "d" (rd), "S" (rs), "D" (rD)
		: "memory"
		);
#endif

	return result;
}
