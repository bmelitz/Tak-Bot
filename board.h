#pragma once

#include <array>

using std::array;

struct stack {
	int height;
	// colors of stack (0 = black, 1 = white)
	unsigned int colors;
};

class Tak_Board {
	// additional points to black's flat score
	const float komi;

	int white_piece_reserve_count;
	int black_piece_reserve_count;
	int white_capstone_reserve_count;
	int black_capstone_reserve_count;

	bool white_piece_reserved;
	bool black_piece_reserved;
	bool white_capstone_reserved;
	bool black_capstone_reserved;

	bool white_turn;

	bitboard white;
	bitboard black;
	bitboard empty;
	bitboard wall;
	bitboard capstone;

	array<stack, BOARD_SIZE * BOARD_SIZE> board = {};

public:
	Tak_Board(
		float _komi,
		int starting_piece_count,
		int starting_capstone_count) :

		komi(_komi),
		white_piece_reserve_count(starting_piece_count),
		black_piece_reserve_count(starting_piece_count),
		white_capstone_reserve_count(starting_capstone_count),
		black_capstone_reserve_count(starting_capstone_count),
		white_piece_reserved(true),
		black_piece_reserved(true),
		white_capstone_reserved(starting_capstone_count ? true : false),
		black_capstone_reserved(white_capstone_reserved),
		white_turn(true),
		white(0),
		black(0),
		// equivalent to (1u << size) - 1, but causes error because 1u << size too big
		empty((((1u << (size - 1)) - 1) << 1) + 1),
		wall(0),
		capstone(0),
	{}

	Tak_Board(
		float _komi,
		int _white_piece_reserve_count,
		int _black_piece_reserve_count,
		int _white_capstone_reserve_count,
		int _black_capstone_reserve_count,
		bool _white_turn,
		bitboard _white,
		bitboard _black,
		bitboard _wall,
		bitboard _capstone) :

		komi(_komi)
		white_piece_reserve_count(_white_piece_reserve_count),
		black_piece_reserve_count(_black_piece_reserve_count),
		white_capstone_reserve_count(_white_capstone_reserve_count),
		black_capstone_reserve_count(_black_capstone_reserve_count),
		white_piece_reserved(_white_piece_reserve_count ? true : false),
		black_piece_reserved(_black_piece_reserve_count ? true : false),
		white_capstone_reserved(_white_capstone_reserve_count ? true : false),
		black_capstone_reserved(_black_capstone_reserve_count ? true : false),
		white_turn(_white_turn),
		white(_white),
		black(_black),
		wall(_wall),
		capstone(_capstone)
	{}
};