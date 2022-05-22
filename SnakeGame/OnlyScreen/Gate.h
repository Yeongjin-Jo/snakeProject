#pragma once

// Gate�� Board.h, SnakeGame.h�� ������.

#include <curses.h>
#include "Drawable.h"
class Gate : public Drawable
{
public:
	Gate(int y, int x)
	{
		this->y = y;
		this->x = x;
		this->icon = 'G';
	}
};