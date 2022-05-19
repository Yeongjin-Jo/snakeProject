#pragma once

#include "Drawable.h"
#include "Board.h"
#include <curses.h>
#include <string>
#include <vector>
#include <time.h>

#define	BOARD_DIM 20
#define	BOARD_ROWS BOARD_DIM * 1.5
#define	BOARD_COLS BOARD_DIM * 3

Board::Board(){construct(0, 0);}
Board::Board(int height, int width){construct(height, width);}
void Board::initialize() {
		clear();
		refresh();
	}

void Board::addBorder() {
		box(board_win, '1', '1');
		addAt(0, 0, '2');
		addAt(0, BOARD_COLS - 1, '2');
		addAt(BOARD_ROWS - 1, 0, '2');
		addAt(BOARD_ROWS - 1, BOARD_COLS - 1, '2');
		box(score_win, 0, 0);
	}

void Board::add(Drawable drawable){addAt(drawable.getX(), drawable.getY(), drawable.getIcon());}

void Board::addAt(int y, int x, chtype ch){mvwaddch(board_win, y, x, ch);}

chtype Board::getInput() { return wgetch(board_win); }

void Board::clear()	{
		wclear(board_win);
		wclear(score_win);
		addBorder();
	}

void Board::refresh() {	
		wrefresh(board_win);
		wrefresh(score_win);
	}

void Board::construct(int height, int width) {
		int xMax, yMax;
		getmaxyx(stdscr, yMax, xMax);
		board_win = newwin(height, width, 0, 4);
		score_win = newwin(30, 40, 0, 75);
	}