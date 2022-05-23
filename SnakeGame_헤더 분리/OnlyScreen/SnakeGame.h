#pragma once
#include <curses.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include "Apple.h"
#include "Empty.h"
#include "Board.h"
#include "Drawable.h"
#include "Snake.h"
#include "Scoreboard.h"
#include "Gate.h"

class SnakeGame
{
	Board board;
	bool game_over;
	Apple* apple;
	Snake snake;
	Gate* gate1;
	Gate* gate2;

	Scoreboard scoreboard;
	int score;

	// handleNextPiece()
	void handleNextPiece(SnakePiece next);

	// createApple()
	void createApple();

	// eatApple()
	void eatApple();

	// createGate()
	void createGate();

	// deleteGate()
	void deleteGate();	// 기존 gate 좌표의 값을 1로 수정

public:
	SnakeGame(int height, int width, int speed);

	~SnakeGame();

	void initialize();

	void processInput();

	void updateState();

	void redraw();

	bool isOver();

	int getScore();
};