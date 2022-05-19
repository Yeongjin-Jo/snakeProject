#pragma once

#include "Drawable.h"
#include <curses.h>
#include <string>
#include <vector>
#include <time.h>

#define	BOARD_DIM 20
#define	BOARD_ROWS BOARD_DIM * 1.5	// 세로의 길이 = 30
#define	BOARD_COLS BOARD_DIM * 3	// 가로의 길이 = 40

class Board {
public:
	Board();
	Board(int height, int width);
	void initialize();	// 윈도우 생성     initialize() -> clear() -> addBorder() -> refresh()
	void addBorder();	// 테두리 만들기
	void add(Drawable drawable);
	void addAt(int y, int x, chtype ch);
	chtype getInput();
	void clear();	// 윈도우 클리어 및 테두리 생성

	void refresh();	// 윈도우 화면 업데이트 (addAt함수 쓰고 나서 무조건 실행해야 반영됨)

private:
	WINDOW* board_win;
	WINDOW* score_win;

	void construct(int height, int width);
};