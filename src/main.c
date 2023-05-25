#include <stdio.h>
#include <string.h>
#include "include/board.h"
#include "include/games.h"


int main(void) {
	Board boards[NUMBER_OF_BOARDS];
	for (uint32 init = 0; init < NUMBER_OF_BOARDS; ++init) {
		memset(boards[init].arr, FILL, sizeof(boards[init].arr));
	}
	boards[0].arr[0][0] = X;
	boards[1].arr[1][1] = X;
	boards[2].arr[2][2] = X;
	boards[3].arr[3][3] = X;
	printf("%c", b_4d_crossboard_check_win(boards));

}

