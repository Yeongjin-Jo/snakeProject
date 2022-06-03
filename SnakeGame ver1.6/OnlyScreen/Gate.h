#pragma once

// Gate는 Board.h, SnakeGame.h에 관여함.

#include <curses.h>
#include "Drawable.h"

class Gate : public Drawable
{
public:
	Gate(int y, int x);
};