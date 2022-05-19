#pragma once

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
	// 생성자
	Board()
	{
		construct(0, 0);
	}

	Board(int height, int width)
	{
		construct(height, width);
	}


	// 함수
	void initialize()	// 윈도우 생성     initialize() -> clear() -> addBorder() -> refresh()
	{
		clear();
		refresh();
	}

	void addBorder()	// 테두리 만들기
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

	void clear()	// 윈도우 클리어 및 테두리 생성
	{
		wclear(board_win);
		addBorder();
	}

	void refresh()	// 윈도우 화면 업데이트 (addAt함수 쓰고 나서 무조건 실행해야 반영됨)
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