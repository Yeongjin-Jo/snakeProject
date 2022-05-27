#pragma once
#include <curses.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include "Apple.h"
#include "Poison.h"
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
	Poison* poison;
	Snake snake;
	Gate* gate1;
	Gate* gate2;
	int currentLength;
	int maxLength;
	int usingApple;
	int usingPoison;

	Scoreboard scoreboard;
	int score;

	// handleNextPiece()
	void handleNextPiece(SnakePiece next);

	// createApple()
	void createApple();

	// eatApple()
	void eatApple();

	// deleteApple()
	void deleteApple();

	//createPoison()
	void createPoison();

	// eatPoison()
	void eatPoison();

	// deletePoison()
	void deletePoison();

	// createGate()
	void createGate();

	// deleteGate()
	void deleteGate();	// 기존 gate 좌표의 값을 1로 수정

	// passGate()
	SnakePiece passGate(Gate* gate);	// gate1을 지나면 매개변수에 gate2를 넣는다.

public:
	SnakeGame(int height, int width, int speed);

	~SnakeGame();

	void initialize();

	void processInput();

	void updateState();

	void redraw();

	bool isOver();

	int getScore();

	// snake 현재 길이
	int getCurrentLength();

	// snake 최대 길이
	int getMaxLength();

	// Apple 사용 횟수
	int getUsingApple();

	//Poison 사용 횟수
	int getUsingPoison();
};