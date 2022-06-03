#pragma once
#include <curses.h>
#include "Drawable.h"

class Poison : public Drawable
{
public:
	Poison(int y, int x);
};