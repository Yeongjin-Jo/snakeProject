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
	SnakePiece()
	{
		this->x = this->y = 0;
		this->icon = '#';
	}

	SnakePiece(int y, int x)
	{
		this->x = x;
		this->y = y;
		this->icon = '#';
	}

	SnakePiece(int y, int x, chtype icon)
	{
		this->x = x;
		this->y = y;
		this->icon = icon;
	}
};

class Snake
{
	
	Direction cur_direction;

public:
	std::queue<SnakePiece> prev_pieces;

	Snake()
	{
		cur_direction = down;
	}

	void addPiece(SnakePiece piece)
	{
		prev_pieces.push(piece);
	}

	void removePiece()
	{
		prev_pieces.pop();
	}

	SnakePiece tail()
	{
		return prev_pieces.front();
	}

	SnakePiece head()
	{
		return prev_pieces.back();
	}

	// Add getDirection(), setDirection(), nexthead()
	Direction getDirection()
	{
		return cur_direction;
	}

	void setDirection(Direction d) 
	{
		// 바꾸려고 하는 방향이 현재진행방향의 정반대가 아닌 경우, 방향을 바꾼다.
		if(cur_direction + d != 0)	
			cur_direction = d;
	}

	SnakePiece nexthead()
	{
		int row = head().getY();
		int col = head().getX();

		switch (cur_direction)
		{
			case down:
				row++;
				break;
			
			case up:
				row--;
				break;
			
			case left:
				col--;
				break;
			
			case right:
				col++;
				break; 
		}

		return SnakePiece(row, col);
	}


};