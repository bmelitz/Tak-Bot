#include <iostream>

#include <array>
#include <vector>

using std::cout;
using std::endl;
using std::array;
using std::vector;

int board_size = 8;

struct stack_drop_hash_entry {
	unsigned int stack_drop;
	int length;
};

void print_bb(unsigned int bb) {
	for (int i = 0; i < board_size * board_size; ++i) {
		cout << (bb & (1u << i) ? '1' : '.') << ' ';
		if (i % board_size == (board_size - 1)) {
			cout << endl;
		}
	}
}

int calc_length(int sq, int dir) {
	int row = sq / board_size;
	int col = sq % board_size;
	if (dir == 0) {
		return row; 
	} else if (dir == 2) {
		return board_size - row - 1;
	} else if (dir == 3) {
		return col;
	} else {
		return board_size - col - 1;
	}
	return 0;
}

constexpr array<array<stack_drop_hash_entry, 4>, 3> STACK_DROP_HASH = {{
	{{ // 1
		{17, 1}
	}},
	{{ // 2
		{529, 2},
		{34, 1}
	}},
	{{ // 3
		{12561, 3},
		{786, 2},
		{801, 2},
		{51, 1}
	}}
}};

int main() {
	/*
	unsigned int bb = 0b0000100001000010000111111;
	print_bb(bb);
	*/

	for (const auto &x : STACK_DROP_HASH) {
		for (const auto &s : x) {
			cout << s.stack_drop << ", " << s.length << endl;
		}
	}

	/*
	for (int i = 0; i < 2; ++i) {
		if (i != 0) {
			cout << "		";
		}
		cout << "{}," << endl;
	}
	*/
}