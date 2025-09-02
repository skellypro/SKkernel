/*
 * stdlib.cpp
 *
 *  Created on: Nov 18, 2024
 *      Author: sean
 * Last Change:	Apr 28, 2025
 */

#include<stdlib.h>
#include<cstdlib>
#include<stdint.h>
#include<stddef.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<float.h>
#include<time.h>

using namespace std;

namespace skstdlib {
	static long long int skstrtoll(const char* str, char** endptr, int base);

	static union {
		long double nextRandNum = time(NULL) * .5;
		long long int randNum;
	};

	static long long int skrand(void);
	static void sksrand(unsigned long int seed);

	static void roll();
}
using namespace skstdlib;

extern "C" {

	//Integer math
	int abs(int n) {
		return n < 0 ? -n : n;
	}

	long int abs(long int n) {
		return labs(n);
	}

	long long int abs(long long int n) {
		return llabs(n);
	}

	long int labs (long int n) {
		return n < 0 ? -n : n;
	}

	long long int llabs (long long int n) {
		return n < 0 ? -n : n;
	}

	div_t div(int numer, int denom) {
		return ((div_t)(numer / denom));
	}

	ldiv_t div(long int numer, long int denom) {
		return ldiv(numer, denom);
	}

	lldiv_t div(long long int numer, long long int denom) {
		return lldiv(numer, denom);
	}

	ldiv_t ldiv(long int numer, long int denom) {
		return ((ldiv_t)(numer / denom));
	}

	lldiv_t lldiv(long long int numer, long long int denom) {
		return ((lldiv_t)(numer / denom));
	}

	int rand() {
		return (int)skrand();
	}

	long int rand(void) {
		return (long int)skrand();
	}

	long long int rand (void) {
		return skrand();
	}

	void srand(unsigned int seed) {
		return sksrand(seed);
	}

	//string conversion
	int atoi(const char *str) {
		return (int)skstrtoll(str, NULL, 10);
	}

	long int atol(const char *str) {
		return (long int)skstrtoll(str, NULL, 10);
	}

	long long int atoll(const char *str) {
		return skstrtoll(str, NULL, 10);
	}

	long int strtol(const char *str, char **endptr, int base) {
		return (long int)skstrtoll(str, endptr, base);
	}

	long long int strtoll(const char* str, char **endptr, int base) {
		return skstrtoll(str, endptr, base);
	}
}

namespace skstdlib {
	static long long int skstrtoll(const char* str, char** endptr, int base) {
		register long double n = 0;
		register size_t i = 0, sign = 0;

		for (register size_t stringlength = strlen(str);
			i < stringlength && (isspace(str[i]) && !isxdigit(str[i]));
			i++);

		if (!base) {
			for (register size_t top = i + 2; i < top; i++) {
				switch (str[i]) {
				case '-':
					sign++;
					break;
				case '0':
					switch (str[i + 1]) {
					case 'd':
					case 'D':
						base = 10;
						break;
					case 'b':
					case 'B':
						base = 2;
						break;
					case 'x':
					case 'X':
						base = 16;
						break;
					case 'o':
					case 'O':
						base = 8;
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}
			}
			if (!base)
				return 0;
		}

		while (isxdigit(str[i]) || str[i] == '-') {
			if (str[i] == '-') {
				sign++;
			}
			else {
				register long double number = isalpha(str[i]) ? toupper(str[i]) - 0x37 : str[i] - 0x30;
				if (number >= base && number < 0)
					goto skstrtollEND;
				n = (base * n) + number;
			}
			i++;
		}

	skstrtollEND:
		if (endptr)
			*endptr = (char*)str + i;

		if (sign && n)
			n = sign > 1 ? 0 : -n;

		return (long long int)n;
	}

	static void roll() {
		register clock_t c = clock();
		nextRandNum = ((RAND_MAX + randNum) * 1103515245 + 12345) * (c * CLOCKS_PER_SEC);
		randNum %= RAND_MAX;
	}

	static long long int skrand(void) {
		roll();
		register long long int a = randNum;
		roll();
		return (unsigned int)a;
	}

	static void sksrand(unsigned long int seed) {
		randNum = seed;
		roll();
	}
}
