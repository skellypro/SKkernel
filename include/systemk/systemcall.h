/*
 * systemcall.h
 * @author: Sean Kelly
 * Date Created: 17FEB2026
 * 
 * WARNING::
 * This file is intended to be included only in System K's kernel,
 * and will not behave properly in user space. This header uses
 * various inline assemblers for different compilers, and is in
 * no way portable.
 */

#pragma once

inline auto [[gnu::fastcall]] [[msvc::__fastcall]]
systemcall(auto rc, auto rd) {
/* 
 * I'm doing this until I figure out how to set up a macro
 * to get gnu compilers to not throw an error at the
 * register keyword within this file.
 */
/* leave this out for now
#ifdef (__GNU__ || __clang__ || __MINGW64__ || __GNUC__)
	auto [[no_unique_address]]result;
#elifdef __MSVC__
	//auto register result;
#endif
*/
/*
 * Given the nature of fastcall, do we need
 * mov (r)D(x), d ???
 * isn't d already in (r)D(x) given fastcall?
 * Does the compiler get what's going on, and fix the redundant
 * assembly?
 * I'll be safe for now until I can compile then disassemble.
 * Also save thse for later:
		mov result, rax
		mov result, eax
		mov result, ax
 */
#ifdef (__GNU__ || __clang__ || __MINGW64__ || __GNUC__) && (AMD64 || x86_64)
	asm volatile (
		"syscall"
		: //"=a" (result)
		: "a" (rc), "d" (rd)
		: "rcx", "r11", "memory"
		);
<<<<<<< HEAD
#elifdef (__GNU__ || __clang__ || __MINGW32__ || __GNUC__) && (x86 || PENTIUM2 || K6)
=======
#ifdef (__GNU__ || __clang__ || __MINGW32__ || __GNUC__) && (x86 || PENTIUM2 || K6)
>>>>>>> 379e53c28c0eb657ec47907114c55818461ab114
	asm volatile (
		"syscall"
		: //"=a" (result)
		: "a" (rc), "d" (rd)
		: "memory"
		);
#elifdef (__GNU__ || __clang__ || __MINGW32__ || __GNUC__) && \
(i686 || i586 || i486 || i386 || i286 || i8086 || i8088 || i8080)
	asm volatile (
		"int $0x80"
		: //"=a" (result)
		: "a" (rc), "d" (rd)
		: "memory"
		);
#elifdef __MSVC__ && (AMD64 || x86_64)
	__asm {
		mov rax, rc
		mov rdx, rd
		syscall
	}
#elifdef __MSVC__ && (x86 || PENTIUM2 || K6)
	__asm {
		mov eax, rc
		mov edx, rd
		syscall
	}
#elifdef __MSVC__ && (i686 || i586 || i486 || i386)
	__asm {
		mov eax, rc
		mov edx, rd
		int 0x80
	}
#elifdef __MSVC__ && (i286 || i8086)
	__asm {
		mov ax, rc
		mov dx, rd
		int 0x80
	}
#elifdef __MSVC__ && (i8088 || i8080)
	__asm {
		mov a, rc
		mov d, rd
		int 0x80
	}
#endif
	//return result;
}