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
	int time = 50;

	// 생성자
	Board();
	Board(int height, int width, int speed);


	// 함수
	void initialize();	// 윈도우 생성     initialize() -> clear() -> addBorder() -> refresh()


	void addBorder();	// 테두리 만들기

	void add(Drawable drawable);

	void addAt(int y, int x, chtype ch);

	chtype getInput();

	void getEmptyCoordinates(int& y, int& x);	// 빈 좌표 찾는 함수

	void getOneCoordinates(int& y, int& x);	// 1인 좌표 찾는 함수 (Gate 만들기 용도)


	chtype getCharAt(int y, int x);

	void clear();	// 윈도우 클리어 및 테두리 생성
	

	void refresh();	// 윈도우 화면 업데이트 (addAt함수 쓰고 나서 무조건 실행해야 반영됨)

	void setTimeout(int timeout);
	
	int getStartRow();

	int getStartCol();

private:
	WINDOW* board_win;
	//WINDOW* score_win;
	int height, width, start_row, start_col;

	void construct(int height, int width, int speed);
};