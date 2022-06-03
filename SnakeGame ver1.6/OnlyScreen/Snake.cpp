#include "Snake.h"

SnakePiece::SnakePiece()
{
	this->x = this->y = 0;
	this->icon = '#';
}

SnakePiece::SnakePiece(int y, int x)
{
	this->x = x;
	this->y = y;
	this->icon = '#';
}

SnakePiece::SnakePiece(int y, int x, chtype icon)
{
	this->x = x;
	this->y = y;
	this->icon = icon;
}

Snake::Snake()
{
	cur_direction = down;
}

void Snake::addPiece(SnakePiece piece)
{
	prev_pieces.push_back(piece);
}

void Snake::removePiece()
{
	prev_pieces.pop_front();
}

// eatPoison °æ¿ì
void Snake::removeBackPiece()
{
	prev_pieces.pop_back();
}

SnakePiece Snake::tail()
{
	return prev_pieces.front();
}

SnakePiece Snake::head()
{
	return prev_pieces.back();
}

Direction Snake::getDirection()
{
	return cur_direction;
}

void Snake::setDirection(Direction d)
{
	cur_direction = d;
}

SnakePiece Snake::nexthead()
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