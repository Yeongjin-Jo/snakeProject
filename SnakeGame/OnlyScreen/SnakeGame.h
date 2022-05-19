#pragma once
#include <curses.h>
#include "Board.h"

class SnakeGame
{
public:
	SnakeGame(int height, int width);
	void processInput();
	void updateState();
	void redraw();
	bool isOver();

private:
	Board board;
	bool game_over;
};