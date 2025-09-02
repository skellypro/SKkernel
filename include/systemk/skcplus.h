/*
 * 		skcplus.h
 *
 *  Created on: Apr 3, 2023
 *      Author: sean
 * Description:	Header to set up a proper C++ environment at the Kernel level
 */

#ifndef INCLUDE_SKCPLUS_H_
#define INCLUDE_SKCPLUS_H_

// define the bool data type
#include<stdbool.h>

// size_t, NULL
#include<stddef.h>

/*	malloc() for operator new,
 * 	calloc() for operator new [],
 *	free() for operator delete and delete []
 */
#include<stdlib.h>
/*
inline void * operator new(size_t size) {
	return malloc(size);
}

inline void * operator new [](size_t num, size_t size) {
	return calloc(num, size);
}
inline void * operator new(size_t, void * obj) noexcept{
	return obj;
}

inline void * operator new [](size_t, void * array) noexcept{
	return array;
}

inline void operator delete(void * old) {
	free(old);
}

inline void operator delete [](void * old) {
	free(old);
}
*/
#endif /* INCLUDE_SKCPLUS_H_ */
