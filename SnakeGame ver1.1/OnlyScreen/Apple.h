#pragma once
#include <curses.h>
#include "Drawable.h"

class Apple : public Drawable
{
public:
	Apple(int y, int x)
	{
		this->y = y;
		this->x = x;
		this->icon = 'A';
	}
};