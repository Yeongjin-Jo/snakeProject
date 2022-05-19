#pragma once

#include "Drawable.h"
#include <curses.h>
#include <string>
#include <vector>
#include <time.h>

#define	BOARD_DIM 20
#define	BOARD_ROWS BOARD_DIM * 1.5	// ������ ���� = 30
#define	BOARD_COLS BOARD_DIM * 3	// ������ ���� = 40

class Board {
public:
	Board();
	Board(int height, int width);
	void initialize();	// ������ ����     initialize() -> clear() -> addBorder() -> refresh()
	void addBorder();	// �׵θ� �����
	void add(Drawable drawable);
	void addAt(int y, int x, chtype ch);
	chtype getInput();
	void clear();	// ������ Ŭ���� �� �׵θ� ����

	void refresh();	// ������ ȭ�� ������Ʈ (addAt�Լ� ���� ���� ������ �����ؾ� �ݿ���)

private:
	WINDOW* board_win;
	WINDOW* score_win;

	void construct(int height, int width);
};