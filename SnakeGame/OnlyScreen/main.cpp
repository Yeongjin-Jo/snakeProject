
#include "Board.h"
#include "SnakeGame.h"
#include "Drawable.h"

#include <curses.h>
#include <string>
#include <vector>
#include <time.h>

#define	BOARD_DIM 20
#define	BOARD_ROWS BOARD_DIM * 1.5	// ������ ����
#define	BOARD_COLS BOARD_DIM * 3    // ������ ����

int main()
{
	initscr();
	refresh();
	
	noecho();	// getch�Լ� ���� �ÿ� ��� ���� �Է¹޾Ƶ� �����쿡 ��Ÿ���� ����.

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