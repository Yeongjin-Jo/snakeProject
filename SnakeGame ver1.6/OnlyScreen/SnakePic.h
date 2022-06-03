#pragma once
#include <curses.h>

class SnakePic // 미션을 완료할 때마다 가운데에 snake 그림 일부를 그림 (더 재밌으라고)
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