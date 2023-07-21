#pragma once

#if defined(__GNUC__)
// clang, gcc
int ls1b(unsigned int n) {
	return __builtin_ctz(n);
}

#elif defined(_MSC_VER)
// MSVC
#include <intrin.h>

int ls1b(unsigned int n) {
	unsigned long index;
	_BitScanForward(&index, n);
	return index;
}

#else
// default implementation
int ls1b(unsigned int n) {
	int count = 0;

	while ((number & 1) == 0) {
		count++;
		number >>= 1;
	}

	return count;
}

#endif