#pragma once
#include <curses.h>

class SnakePic // �̼��� �Ϸ��� ������ ����� snake �׸� �Ϻθ� �׸� (�� ��������)
{
	WINDOW* snake_win;
public:
	SnakePic();

	void initialize();
	void wdelwin();
	void drawPart1();
	void drawPart2();
	void drawPart3();

	void clear();

	void refresh();
};