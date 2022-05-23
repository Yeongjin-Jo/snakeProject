#pragma once

#include "Drawable.h"
#include <queue>

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
	std::queue<SnakePiece> prev_pieces;

	Snake();

	void addPiece(SnakePiece piece);

	void removePiece();

	SnakePiece tail();

	SnakePiece head();

	// Add getDirection(), setDirection(), nexthead()
	Direction getDirection();

	void setDirection(Direction d);	// �ٲٷ��� �ϴ� ������ ������������� ���ݴ밡 �ƴ� ���, ������ �ٲ۴�.

	SnakePiece nexthead();
};