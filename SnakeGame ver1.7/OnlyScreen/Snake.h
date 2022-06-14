#pragma once

#include "Drawable.h"
#include <deque>

enum Direction
{
	up = -1,
	down = 1,
	left = -2,
	right = 2
};

class SnakePiece : public Drawable
{
public:
	SnakePiece();

	SnakePiece(int y, int x);

	SnakePiece(int y, int x, chtype icon);
};

class Snake
{
	
	Direction cur_direction;

public:
	std::deque<SnakePiece> prev_pieces;

	Snake();

	void addPiece(SnakePiece piece);

	void removePiece();

	void removeBackPiece();

	SnakePiece tail();

	SnakePiece head();

	// Add getDirection(), setDirection(), nexthead()
	Direction getDirection();

	void setDirection(Direction d);	// 바꾸려고 하는 방향이 현재진행방향의 정반대가 아닌 경우, 방향을 바꾼다.

	SnakePiece nexthead();
};