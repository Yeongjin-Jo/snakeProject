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
#include "Missionboard.h"
#include "SnakePic.h"

class SnakeGame
{
	int stage = 1;
	int currentLength = 4;
	Board board;
	bool game_over;
	bool clear;
	Apple* apple;
	Poison* poison;
	Snake snake;
	Gate* gate1;
	Gate* gate2;

	Scoreboard scoreboard;
	Missionboard missionboard;
	SnakePic snakepic;
	// scorboard member
	int growthScore;
	int poisonScore;
	int gateScore;
	int maxLength;


	// mission member
	int trGrowthScore;
	int trPoisonScore;
	int trGateScore;
	int trLength;

	bool growthclear;
	bool poisonclear;
	bool gateclear;
	bool lengthclear;

	

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

	void initialize1();	// map1
	void initialize2();	// map2
	void initialize3();	// map3
	void initialize4();	// map4
	void allClearInitializer(); // ���� Ŭ���� ȭ��
	void gameOverInitializer(); // ���� ���� ȭ��

	void processInput();

	void updateState();

	void redraw();

	bool isOver();

	bool isClear();

	int getMaxLength();
};