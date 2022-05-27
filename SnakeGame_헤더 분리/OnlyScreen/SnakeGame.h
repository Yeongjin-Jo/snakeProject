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
	void deleteGate();	// ���� gate ��ǥ�� ���� 1�� ����

	// passGate()
	SnakePiece passGate(Gate* gate);	// gate1�� ������ �Ű������� gate2�� �ִ´�.

public:
	SnakeGame(int height, int width, int speed);

	~SnakeGame();

	void initialize();

	void processInput();

	void updateState();

	void redraw();

	bool isOver();

	int getScore();

	// snake ���� ����
	int getCurrentLength();

	// snake �ִ� ����
	int getMaxLength();

	// Apple ��� Ƚ��
	int getUsingApple();

	//Poison ��� Ƚ��
	int getUsingPoison();
};