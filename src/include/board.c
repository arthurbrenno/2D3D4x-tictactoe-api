#include "board.h"

char b_check_win(Board board) {
	//TODO
	
	// =-=-= Check row wins =-=-=
	for (uint32 row = 0; row < BOARD_SIZE; ++row) {
		
		uint32 letter_counter = 1;				//count the equal letters in the row
		char first_letter = board.arr[row][0];	//take the first letter of curr row
		for (uint32 col = 1; col < BOARD_SIZE; ++col) {
			if (board.arr[row][col] != FILL && board.arr[row][col] == first_letter) {
				++letter_counter;				//increment when found occurency
			}
		}

		//example: [XXX] <-- BOARD_SIZE 3 && letter_counter = 3
		if (letter_counter == BOARD_SIZE) {
			return first_letter;
		}
	}
	

	// =-=-= Check col wins =-=-=
	for (uint32 col = 0; col < BOARD_SIZE; ++col) {
		uint32 letter_counter = 1;					//count the equal letters in the row
		char first_letter = board.arr[0][col];		//take the first letter of curr row
		for (uint32 row = 1; row < BOARD_SIZE; ++row) {
			if (board.arr[row][col] != FILL && board.arr[row][col] == first_letter) {
				++letter_counter;
			}
		}

		if (letter_counter == BOARD_SIZE) {
			return first_letter;
		}
	}
	
	// =-=-= Check main diag wins =-=-=
	uint32 main_letter_counter = 1;				//started by [0][0]. first occurrence found
	for (uint32 i = 1; i < BOARD_SIZE; ++i) {
		char first_letter = board.arr[0][0];
		if (board.arr[i][i] != FILL && board.arr[i][i] == first_letter) {
			++main_letter_counter;
		}

		if ((i == BOARD_SIZE - 1) && (main_letter_counter == BOARD_SIZE)) {
			return first_letter;
		}
	}
	
	
	// =-=-= Check secondary diag wins =-=-=
	uint32 sec_letter_counter = 0;
	uint32 s_col = 0;
	for (uint32 row = BOARD_SIZE - 1; row >= 0 && s_col < BOARD_SIZE; --row) {
		char first_letter = board.arr[BOARD_SIZE - 1][0];
		if (board.arr[row][s_col] != FILL && board.arr[row][s_col] == first_letter) {
			++sec_letter_counter;
		}
		++s_col;

		//check last iteration
		if (row == 0 && sec_letter_counter == BOARD_SIZE) {
			return first_letter;
		}

	}

	return 0;
}

char b_4d_crossboard_check_win(Board boards[NUMBER_OF_BOARDS]) {
	
	//check by row
	for (uint32 row = 0; row < BOARD_SIZE; ++row) {
		char first_letter = boards[0].arr[row][0];
		uint32 letter_counter = 1;
		for (uint32 col = 1; col < BOARD_SIZE; ++col) {
			if (boards[col].arr[row][col] == first_letter && boards[col].arr[row][col] != FILL) {
				++letter_counter;
			} else { break; } //next row, skip unness iterations
		}
		if (letter_counter == BOARD_SIZE) {
			return first_letter;
		}
	}

	//check by column
	uint32 col = 0;
	while (col < BOARD_SIZE) {
		char first_letter = boards[0].arr[0][col];
		uint32 letter_counter = 1;
		for (uint32 i = 1; i < BOARD_SIZE; ++i) {
			if (boards[i].arr[i][col] == first_letter && boards[i].arr[i][col] != FILL) {
				++letter_counter;
			} else { break; } // next col, skip unnessessary iterations.
		}
		if (letter_counter == BOARD_SIZE) {
			return first_letter;
		}
		++col;
	}

	//check by main diagonal
	uint32 mdiag_letter_counter = 1;
	for (uint32 i = 1; i < BOARD_SIZE; ++i) {
		char first_letter = boards[0].arr[0][0];
		if (boards[i].arr[i][i] == first_letter && boards[i].arr[i][i] != FILL) {
			++mdiag_letter_counter;
		} else { break; }
		
		if (mdiag_letter_counter == BOARD_SIZE) {
			return first_letter;
		}
	}

	//check by sec diagonal
	{
		uint32 sd_row = BOARD_SIZE - 1;
		char sdfirst_letter = boards[0].arr[sd_row][0];
		uint32 sdiag_letter_counter = 1;
		for (uint32 i = 1; i < BOARD_SIZE; ++i) {
			if (boards[i].arr[--sd_row][i] == sdfirst_letter && boards[i].arr[sd_row][i] != FILL) {
				++sdiag_letter_counter;
			}
		}

		if (sdiag_letter_counter == BOARD_SIZE) {
			return sdfirst_letter;
		}
	}

	return 0;
}

void b_print(Board board) {
	if (BOARD_SIZE == 3) {
		
		printf("      |     |     \n");
		printf("  %c   |  %c  |  %c \n", board.arr[0][0], board.arr[0][1], board.arr[0][2]);
		printf("      |     |     \n");
		printf("--------------------\n");
		printf("      |     |     \n");
		printf("  %c   |  %c  |  %c \n", board.arr[1][0], board.arr[1][1], board.arr[1][2]);
		printf("      |     |     \n");
		printf("--------------------\n");
		printf("      |     |     \n");
		printf("  %c   |  %c  |  %c \n", board.arr[2][0], board.arr[2][1], board.arr[2][2]);
		printf("      |     |     \n");

	}
	/*else {
		for (uint32 i = 0; i < BOARD_SIZE; ++i) {
			for (uint32 j = 0; j < BOARD_SIZE; ++j) {
				printf("%c  ", board.arr[i][j]);
			}
			printf("\n\n");
		}
	}*/
}

int b_check_full(Board board) {
	for (uint32 i = 0; i < BOARD_SIZE; ++i) {
		for (uint32 j = 0; j < BOARD_SIZE; ++j) {
			if (board.arr[i][j] != X && board.arr[i][j] != O) {
				return 0;
			}
		} 
	}
	
	return 1;
}

int b_write(Board* board, ubyte value, uint16 xpos, uint16 ypos) {

	if ((value != X && 
		value != O) ||
		xpos >= BOARD_SIZE ||
		ypos >= BOARD_SIZE ||
		b_pos_is_occupied(*board, xpos, ypos)) {
		
		return 0; 
	}
	board->arr[xpos][ypos] = value;
	return 1;
}

int b_pos_is_occupied(Board board, uint16 xpos, uint16 ypos) {
	if (xpos >= BOARD_SIZE || ypos >= BOARD_SIZE) {
		return 0;
	}

	return board.arr[xpos][ypos] == X || board.arr[xpos][ypos] == O;
}
