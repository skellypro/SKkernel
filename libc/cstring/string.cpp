/*
 * string.cpp
 *
 *  Created on: Oct 28, 2023
 *      Author: sean
 */

#include<stddef.h>
#include<stdint.h>
#include<string.h>

extern "C" {

	size_t strlen(const char* str)
	{
		register size_t len = 0;
		while (str[len])
			len++;
		return len + 1;
	}

	int strcmp(const char* a, const char* b) {
		if (a != b) {
			register int i = 0;
			do {
				if (a[i] != b[i])
					return false;
				i++;
			} while (a[i] & b[i]);
		}
		return true;
	}

	char* strcat(char* destination, const char* source) {
		register int i = strlen(destination), d = 0;
		/*
		do
			destination[i++] = source[d++];
		while(source[d]);
		*/
		for (destination[i] : c)
			i++;
		return destination;
	}

}
