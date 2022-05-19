#pragma once

#include <curses.h>

class ScoreBoard
{
public:
	// ������
	Board()
	{
		construct(0, 0);
	}

	Board(int height, int width)
	{
		construct(height, width);
	}


	// �Լ�
	void initialize()	// ������ ����     initialize() -> clear() -> addBorder() -> refresh()
	{
		clear();
		refresh();
	}

	void addBorder()	// �׵θ� �����
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

	void clear()	// ������ Ŭ���� �� �׵θ� ����
	{
		wclear(score_win);
		addBorder();
	}

	void refresh()	// ������ ȭ�� ������Ʈ (addAt�Լ� ���� ���� ������ �����ؾ� �ݿ���)
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