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
	int time = 50;

	// ������
	Board();
	Board(int height, int width, int speed);


	// �Լ�
	void initialize();	// ������ ����     initialize() -> clear() -> addBorder() -> refresh()


	void addBorder();	// �׵θ� �����

	void add(Drawable drawable);

	void addAt(int y, int x, chtype ch);

	chtype getInput();

	void getEmptyCoordinates(int& y, int& x);	// �� ��ǥ ã�� �Լ�

	void getOneCoordinates(int& y, int& x);	// 1�� ��ǥ ã�� �Լ� (Gate ����� �뵵)


	chtype getCharAt(int y, int x);

	void clear();	// ������ Ŭ���� �� �׵θ� ����
	

	void refresh();	// ������ ȭ�� ������Ʈ (addAt�Լ� ���� ���� ������ �����ؾ� �ݿ���)

	void setTimeout(int timeout);
	
	int getStartRow();

	int getStartCol();

private:
	WINDOW* board_win;
	//WINDOW* score_win;
	int height, width, start_row, start_col;

	void construct(int height, int width, int speed);
};