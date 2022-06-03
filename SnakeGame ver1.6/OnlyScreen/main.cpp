#include <iostream>
#include "Board.h"
#include "SnakeGame.h"
#include "Drawable.h"

#include <curses.h>
#include <string>
#include <time.h>

#define	BOARD_DIM 20
#define	BOARD_ROWS BOARD_DIM * 1.5	// ������ ����
#define	BOARD_COLS BOARD_DIM * 2	// ������ ����

int main(int argc, char **argv)
{
	initscr();
	refresh();
	
	noecho();	// getch�Լ� ���� �ÿ� ��� ���� �Է¹޾Ƶ� �����쿡 ��Ÿ���� ����.
	curs_set(0);	// windowâ�� Ŀ�� ����

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