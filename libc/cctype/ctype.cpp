/*
 * ctype.cpp
 *
 *  Created on: Nov 17, 2024
 *      Author: sean
 * Last Change: Nov 17, 2024
 * Description:	My implementation of ctype.h.
 *
 */

#include<ctype.h>
#include<cctype>

using namespace std;

extern "C" {

	int isalnum(int c) {
		return isdigit(c) || isalpha(c);
	}

	int isalpha(int c) {
		return isupper(c) || islower(c);
	}

	int isblank(int c) {
		return c == 0x09 || c == 0x20;
	}

	int iscntrl(int c) {
		return (c >= 0x00 && c <= 0x1F) || c == 0x7F;
	}

	int isdigit(int c) {
		return c >= 0x30 && c <= 0x39;
	}

	int isgraph(int c) {
		return isalnum(c) || ispunct(c);
	}

	int islower(int c) {
		return c >= 0x61 && c <= 0x7A;
	}

	int isprint(int c) {
		return c == 0x20 || isgraph(c);
	}

	int ispunct(int c) {
		return (c >= 0x21 && c <= 0x2F) || (c >= 0x3A && c <= 0x40) ||
				(c >= 0x5B && c <= 0x60) || (c >= 0x7B && c <= 0x7E);
	}

	int isspace(int c) {
		return (c >= 0x09 && c<= 0x0D) || c == 0x20;
	}

	int isupper(int c) {
		return c >= 0x41 && c <= 0x5A;
	}

	int isxdigit(int c) {
		return isdigit(c) || (c >= 0x41 && c <= 0x46) || (c >= 0x61 && c <= 0x66);
	}

	int tolower(int c) {
		return isupper(c) ? c - 0x20 : c;
	}

	int toupper(int c) {
		return islower(c) ? c + 0x20 : c;
	}

}
