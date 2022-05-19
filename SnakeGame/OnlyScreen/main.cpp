
#include "Board.h"
#include "SnakeGame.h"
#include "Drawable.h"

#include <curses.h>
#include <string>
#include <vector>
#include <time.h>

#define	BOARD_DIM 20
#define	BOARD_ROWS BOARD_DIM * 1.5	// 세로의 길이
#define	BOARD_COLS BOARD_DIM * 3    // 가로의 길이

int main()
{
	initscr();
	refresh();
	
	noecho();	// getch함수 실행 시에 어떠한 값을 입력받아도 윈도우에 나타나지 않음.

	SnakeGame game = SnakeGame(BOARD_ROWS, BOARD_COLS);

	while (!game.isOver())
	{
		game.processInput();

		game.updateState();

		game.redraw();
	}

	getch();
	endwin();

	return 0;
}