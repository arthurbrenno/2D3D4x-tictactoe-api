#include "games.h"

char g_2DGame(void) {
	Board board1;									//declaration of a board
	memset(board1.arr, FILL, sizeof(board1.arr));	//init board "uchar" arr.
	char turn = 'x';
	
	while (!b_check_full(board1) && !b_check_win(board1)) {
		clear();
		b_print(board1);
		char input = _getch();

		switch (input) {
		case '1':
			b_write(&board1, (turn == 'x') ? X : O, BOARD_SIZE - 1, 0); break;
		case '2':
			b_write(&board1, (turn == 'x') ? X : O, BOARD_SIZE - 1, 1); break;
		case '3':
			b_write(&board1, (turn == 'x') ? X : O, BOARD_SIZE - 1, 2); break;

		case '4':
			b_write(&board1, (turn == 'x') ? X : O, BOARD_SIZE - 2, 0); break;
		case '5':
			b_write(&board1, (turn == 'x') ? X : O, BOARD_SIZE - 2, 1); break;
		case '6':
			b_write(&board1, (turn == 'x') ? X : O, BOARD_SIZE - 2, 2); break;

		case '7':
			b_write(&board1, (turn == 'x') ? X : O, BOARD_SIZE - 3, 0); break;
		case '8':
			b_write(&board1, (turn == 'x') ? X : O, BOARD_SIZE - 3, 1); break;
		case '9':
			b_write(&board1, (turn == 'x') ? X : O, BOARD_SIZE - 3, 2); break;
		default:
			break;
		}

		//swap turns
		turn = (turn == 'x') ? 'o' : 'x';
	}
	clear();
	b_print(board1);
	return b_check_win(board1);
}

char g_3D4xGame(void) {
	Board boards[NUMBER_OF_BOARDS];
	for (uint32 init = 0; init < NUMBER_OF_BOARDS; ++init) {
		memset(boards[init].arr, FILL, sizeof(boards[init].arr));
	}

	do {
		b_3dprint(boards);
		char board_chosen = _getch();
		switch (board_chosen) {
		case 1:
			//your implementation here
		case 2:
			//your implementation here
		case 3:
			//your implementation here
		case 4:
			//your implementation here
		default:
			break;
		}
	} while (!b_3d_crossboard_check_win(boards) &&
		!b_check_full(boards[0]) &&
		!b_check_full(boards[1]) &&
		!b_check_full(boards[2]) &&
		!b_check_full(boards[3]) &&
		!b_check_win(boards[0]) &&
		!b_check_win(boards[1]) &&
		!b_check_win(boards[2]) &&
		!b_check_win(boards[3]));
}
