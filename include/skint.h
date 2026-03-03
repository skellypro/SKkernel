/*
 * skint.h
 *
 *  Created on: Jan 14, 2023
 *      Author: sean
 */

#pragma once


namespace sk {
	#include<stdint.h>

	typedef unsigned int uint;
	typedef intmax_t intmax;
	typedef uintmax_t uintmax;
	typedef int8_t int8;
	typedef uint8_t uint8;
	typedef int16_t int16;
	typedef uint16_t uint16;
	typedef int32_t int32;
	typedef uint32_t uint32;
	typedef int64_t int64;
	typedef uint64_t uint64;

	typedef int_least8_t least8;
	typedef uint_least8_t uleast8;
	typedef int_least16_t least16;
	typedef uint_least16_t uleast16;
	typedef int_least32_t least32;
	typedef uint_least32_t uleast32;
	typedef int_least64_t least64;
	typedef uint_least64_t uleast64;

	typedef int_fast8_t fast8;
	typedef uint_fast8_t ufast8;
	typedef int_fast16_t fast16;
	typedef uint_fast16_t ufast16;
	typedef int_fast32_t fast32;
	typedef uint_fast32_t ufast32;
	typedef int_fast64_t fast64;
	typedef uint_fast64_t ufast64;
}