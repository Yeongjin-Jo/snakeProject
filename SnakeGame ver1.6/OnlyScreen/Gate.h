#pragma once

// Gate�� Board.h, SnakeGame.h�� ������.

#include <curses.h>
#include "Drawable.h"

class Gate : public Drawable
{
public:
	Gate(int y, int x);
};