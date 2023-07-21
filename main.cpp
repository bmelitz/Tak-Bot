// try shorts instead of ints for performance

#include <iostream>

#if __SIZEOF_POINTER__ != 8
#error "requires a 64 bit system"
#endif

// use -DBOARD_SIZE (size), default size = 5
#ifndef BOARD_SIZE
#define BOARD_SIZE 5
#define bitboard unsigned int
#elif BOARD_SIZE < 3 || BOARD_SIZE > 8
#error "board size must be between 3 and 8 (inclusive)"
#elif BOARD_SIZE < 6
#define bitboard unsigned int
#else
#define bitboard unsigned long
#endif

#include <movegen.h>

using std::cout;
using std::endl;

int main() {
}