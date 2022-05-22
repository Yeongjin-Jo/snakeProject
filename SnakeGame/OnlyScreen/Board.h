#pragma once

#include "Drawable.h"
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
	int time = 0;

	// ������
	Board()
	{
		construct(0, 0, 300);
	}

	Board(int height, int width, int speed)
	{
		construct(height, width, speed);
	}


	// �Լ�
	void initialize()	// ������ ����     initialize() -> clear() -> addBorder() -> refresh()
	{
		clear();
		refresh();
	}

	void addBorder()	// �׵θ� �����
	{
		box(board_win, '1', '1');

		addAt(0, 0, '2');
		addAt(0, BOARD_COLS - 1, '2');
		addAt(BOARD_ROWS - 1, 0, '2');
		addAt(BOARD_ROWS - 1, BOARD_COLS - 1, '2');

		//box(score_win, 0, 0);
	}

	void add(Drawable drawable)
	{
		addAt(drawable.getY(), drawable.getX(), drawable.getIcon());
	}

	void addAt(int y, int x, chtype ch)
	{
		mvwaddch(board_win, y, x, ch);
	}

	chtype getInput()
	{
		return wgetch(board_win);
	}

	void getEmptyCoordinates(int& y, int& x)	// �� ��ǥ ã�� �Լ�
	{
		while ((mvwinch(board_win, y = rand() % height, x = rand() % width)) != ' ')
			;
	}

	void getOneCoordinates(int& y, int& x)	// 1�� ��ǥ ã�� �Լ� (Gate ����� �뵵)
	{
		while ((mvwinch(board_win, y = rand() % height, x = rand() % width)) != '1')
			;
	}

	chtype getCharAt(int y, int x)
	{
		return mvwinch(board_win, y, x);
	}

	void clear()	// ������ Ŭ���� �� �׵θ� ����
	{
		wclear(board_win);
		//wclear(score_win);
		addBorder();
	}

	void refresh()	// ������ ȭ�� ������Ʈ (addAt�Լ� ���� ���� ������ �����ؾ� �ݿ���)
	{
		wrefresh(board_win);
		//wrefresh(score_win);
	}

	void setTimeout(int timeout)
	{
		wtimeout(board_win, timeout);
	}


	int getStartRow()
	{
		return start_row;
	}

	int getStartCol()
	{
		return start_col;
	}

private:
	WINDOW* board_win;
	//WINDOW* score_win;
	int height, width, start_row, start_col;

	void construct(int height, int width, int speed)
	{
		int xMax, yMax;
		getmaxyx(stdscr, yMax, xMax);
		this->height = height;
		this->width = width;

		start_row = 0;
		start_col = 50;	

		board_win = newwin(height, width, 0, 4);	// (yMax / 2) - (height / 2)
		//score_win = newwin(15, 30, 0, 50);
		setTimeout(speed);	// �ð�
		keypad(board_win, true); // ����Ű�� ���ӿ� ���밡��
	}
};