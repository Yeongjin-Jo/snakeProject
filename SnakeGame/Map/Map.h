#pragma once

#include <curses.h>
#include <string>
#include <vector>
#include <time.h>

#define	BOARD_DIM 20
#define	BOARD_ROWS BOARD_DIM * 1.5	// ������ ���� = 30
#define	BOARD_COLS BOARD_DIM * 2	// ������ ���� = 40

class Board
{
public:
	// ������
	Board()
	{
		construct(0, 0);
	}

	Board(int height, int width)
	{
		construct(height, width);
	}


	// �Լ�
	void initialize()	// ������ ����     initialize() -> clear() -> addBorder() -> refresh()
	{
		clear();
		refresh();
	}

	void addBorder()	// �׵θ� �����
	{
		for (int i = 0; i < BOARD_ROWS; i++) {
			for (int j = 0; j < BOARD_COLS; j++) {
				addAt(0, j, '1');
				addAt(i, 0, '1');
				addAt(BOARD_ROWS - 1, j, '1');
				addAt(i, BOARD_COLS - 1, '1');
			}
		}

		addAt(0, 0, '2');
		addAt(0, BOARD_COLS - 1, '2');
		addAt(BOARD_ROWS - 1, 0, '2');
		addAt(BOARD_ROWS - 1, BOARD_COLS - 1, '2');
	}

	void addAt(int y, int x, chtype ch)
	{
		mvwaddch(board_win, y, x, ch);
	}

	chtype getInput()
	{
		return wgetch(board_win);
	}

	void clear()	// ������ Ŭ���� �� �׵θ� ����
	{
		wclear(board_win);
		addBorder();
	}

	void refresh()	// ������ ȭ�� ������Ʈ (addAt�Լ� ���� ���� ������ �����ؾ� �ݿ���)
	{
		wrefresh(board_win);
	}

private:
	WINDOW* board_win;

	void construct(int height, int width)
	{
		int xMax, yMax;
		getmaxyx(stdscr, yMax, xMax);

		board_win = newwin(height, width, (yMax / 2) - (height / 2), (xMax / 2) - (width / 2));
	}
};