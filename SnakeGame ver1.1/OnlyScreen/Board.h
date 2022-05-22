#pragma once

#include "Drawable.h"
#include <curses.h>
#include <string>
#include <vector>
#include <time.h>

#define	BOARD_DIM 20
#define	BOARD_ROWS BOARD_DIM * 1.5	// 세로의 길이 = 30
#define	BOARD_COLS BOARD_DIM * 2	// 가로의 길이 = 40

class Board
{
public:
	int time = 0;

	// 생성자
	Board()
	{
		construct(0, 0, 300);
	}

	Board(int height, int width, int speed)
	{
		construct(height, width, speed);
	}


	// 함수
	void initialize()	// 윈도우 생성     initialize() -> clear() -> addBorder() -> refresh()
	{
		clear();
		refresh();
	}

	void addBorder()	// 테두리 만들기
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

	void getEmptyCoordinates(int& y, int& x)	// 빈 좌표 찾는 함수
	{
		while ((mvwinch(board_win, y = rand() % height, x = rand() % width)) != ' ')
			;
	}

	void getOneCoordinates(int& y, int& x)	// 1인 좌표 찾는 함수 (Gate 만들기 용도)
	{
		while ((mvwinch(board_win, y = rand() % height, x = rand() % width)) != '1')
			;
	}

	chtype getCharAt(int y, int x)
	{
		return mvwinch(board_win, y, x);
	}

	void clear()	// 윈도우 클리어 및 테두리 생성
	{
		wclear(board_win);
		//wclear(score_win);
		addBorder();
	}

	void refresh()	// 윈도우 화면 업데이트 (addAt함수 쓰고 나서 무조건 실행해야 반영됨)
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
		setTimeout(speed);	// 시간
		keypad(board_win, true); // 방향키를 게임에 적용가능
	}
};