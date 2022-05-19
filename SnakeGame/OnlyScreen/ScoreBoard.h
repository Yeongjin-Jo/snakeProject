#pragma once

#include <curses.h>

class ScoreBoard
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
		

		box(score_win, 0, 0);
	}

	void add(Drawable drawable)
	{
		addAt(drawable.getX(), drawable.getY(), drawable.getIcon());
	}

	void addAt(int y, int x, chtype ch)
	{
		mvwaddch(score_win, y, x, ch);
	}

	chtype getInput()
	{
		return wgetch(score_win);
	}

	void clear()	// 윈도우 클리어 및 테두리 생성
	{
		wclear(score_win);
		addBorder();
	}

	void refresh()	// 윈도우 화면 업데이트 (addAt함수 쓰고 나서 무조건 실행해야 반영됨)
	{
		wrefresh(board_win);
		wrefresh(score_win);
	}

private:
	WINDOW* score_win;

	void construct(int height, int width)
	{
		
	}
};