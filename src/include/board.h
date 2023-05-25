﻿#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include "ttt_types.h"



#define BOARD_SIZE 4
#define NUMBER_OF_BOARDS 4

/** @struct Board
 *  @brief This struct represents a BOARD_SIZE 2D board.
 */
typedef struct {
	ubyte arr[BOARD_SIZE][BOARD_SIZE]; 
}Board;


/**
 * Checks if somenone won.
 * @param 1. A board structure (pass-by-value).
 * @return [1] if someone won, [0] if nobody won yet.
 */
char b_check_win(Board board);

/**
 * Checks if somenone won across the boards.
 * @param 1. An array of board structs (pass-by-value).
 * @return [1] if someone won, [0] if nobody won yet.
 */
char b_3d_crossboard_check_win(Board boards[NUMBER_OF_BOARDS]);

/**
 * Prints ONE board into the console.
 * @param 1. A board structure (pass-by-value).
 * @return [void].
 */
void b_print(Board board);


/**
 * Check if the board is full.
 * @param 1. A board structure (pass-by-value).
 * @return [1] if it's full, [0] otherwise.
 */
int b_check_full(Board board);


/**
 * Writes a value in the board IF the position is not occupied.
 * @param 1. Board structure (pass-by-reference).
 * @param 2. uchar that must be in ('x', 'X', 'O', 'o')
 * @param 3. {row ∈ N | 0 <= row < BOARD_SIZE}
 * @param 4. {col ∈ N | 0 <= col < BOARD_SIZE}
 * @return [1] if write was succeded, [0] if not.
 */
int b_write(Board* board, ubyte value, uint16 xpos, uint16 ypos);

/**
 * Checks if a position is occupied.
 * @param 1. Board structure (pass-by-value).
 * @param 2. {row ∈ N | 0 <= row < BOARD_SIZE}
 * @param 3. {col ∈ N | 0 <= col < BOARD_SIZE}
 * @return [1] if write was succeded, [0] if not.
 */
int b_pos_is_occupied(Board board, uint16 xpos, uint16 ypos);

#endif


