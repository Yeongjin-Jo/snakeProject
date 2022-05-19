#include "Map.h"
#include <iostream>
#include <curses.h>
#include <string>
#include <vector>
#include <time.h>

#define	BOARD_DIM 20
#define	BOARD_ROWS BOARD_DIM * 1.5	// 세로의 길이
#define	BOARD_COLS BOARD_DIM * 2	// 가로의 길이

int main()
{
	initscr();
	refresh();


	Board board(BOARD_ROWS, BOARD_COLS);	// Board 객체 생성
	board.initialize();

	getch();
	endwin();

	return 0;
}