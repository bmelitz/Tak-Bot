#pragma once

struct place_move {
	int sq;
	int type; // 0 = piece, 1 = wall, 2 = capstone
}

struct stack_move {
	int sq;
	int dir; // 0 = up, 1 = right, 2 = down, 3 = left
	int length; // length of stack move
	unsigned int stack_drops;
	// first 4 bits = num picked up
	// every 4 bits = num dropped
};