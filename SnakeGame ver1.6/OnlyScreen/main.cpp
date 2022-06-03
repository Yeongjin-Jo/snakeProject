#include <iostream>
#include "Board.h"
#include "SnakeGame.h"
#include "Drawable.h"

#include <curses.h>
#include <string>
#include <time.h>

#define	BOARD_DIM 20
#define	BOARD_ROWS BOARD_DIM * 1.5	// 세로의 길이
#define	BOARD_COLS BOARD_DIM * 2	// 가로의 길이

int main(int argc, char **argv)
{
	initscr();
	refresh();
	
	noecho();	// getch함수 실행 시에 어떠한 값을 입력받아도 윈도우에 나타나지 않음.
	curs_set(0);	// window창의 커서 제거

	SnakeGame game = SnakeGame(BOARD_ROWS, BOARD_COLS, 300);

	while (!game.isOver())
	{
		game.processInput();

		game.updateState();

		game.redraw();

	}
	if (game.isOver()) {
		game.gameOverInitializer();
	}

	endwin();

	return 0;
}