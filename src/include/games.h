#ifndef GAMES_H
#define GAMES_H

#include <conio.h>
#include "board.h"
#include "ttt_types.h"


#ifdef __linux__ 
#define clear() system("clear")
#elif _WIN32
#define clear() system("cls")
#endif




/**
 * Plays a normal Tic-Tac-Toe game.
 * @param 1. void.
 * @return character of the player who won (x|o).
 */
char g_2DGame(void);

/**
 * Plays a 3D 4x4x4 Qubic Tic-Tac-Toe game.
 * @param 1. void.
 * @return character of the player who won (x|o).
 */
char g_3D4xGame(void);

#endif
