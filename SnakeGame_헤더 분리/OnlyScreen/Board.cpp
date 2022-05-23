#include "Board.h"

Board::Board()
{
	construct(0, 0, 300);
}

Board::Board(int height, int width, int speed)
{
	construct(height, width, speed);
}

void Board::initialize()
{
	clear();
	refresh();
}

void Board::addBorder()	// 테두리 만들기
{
	box(board_win, '1', '1');

	addAt(0, 0, '2');
	addAt(0, BOARD_COLS - 1, '2');
	addAt(BOARD_ROWS - 1, 0, '2');
	addAt(BOARD_ROWS - 1, BOARD_COLS - 1, '2');

	//box(score_win, 0, 0);
}

void Board::add(Drawable drawable)
{
	addAt(drawable.getY(), drawable.getX(), drawable.getIcon());
}

void Board::addAt(int y, int x, chtype ch)
{
	mvwaddch(board_win, y, x, ch);
}

chtype Board::getInput()
{
	return wgetch(board_win);
}

void Board::getEmptyCoordinates(int& y, int& x)	// 빈 좌표 찾는 함수
{
	while ((mvwinch(board_win, y = rand() % height, x = rand() % width)) != ' ')
		;
}

void Board::getOneCoordinates(int& y, int& x)
{
	while ((mvwinch(board_win, y = rand() % height, x = rand() % width)) != '1')
		;
}

chtype Board::getCharAt(int y, int x)
{
	return mvwinch(board_win, y, x);
}

void Board::clear()
{
	wclear(board_win);
	//wclear(score_win);
	addBorder();
}

void Board::refresh()
{
	wrefresh(board_win);
	//wrefresh(score_win);
}

void Board::setTimeout(int timeout)
{
	wtimeout(board_win, timeout);
}

int Board::getStartRow()
{
	return start_row;
}

int Board::getStartCol()
{
	return start_col;
}

void Board::construct(int height, int width, int speed)
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