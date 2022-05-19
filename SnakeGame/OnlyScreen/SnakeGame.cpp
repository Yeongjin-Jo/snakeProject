#pragma once
#include <curses.h>
#include "Board.h"
#include "SnakeGame.h"

SnakeGame::SnakeGame(int height, int width) {
		board = Board(height, width);
		board.initialize();	// 윈도우 생성
		game_over = false;
	}

void SnakeGame::processInput(){chtype input = board.getInput();}
void SnakeGame::updateState() { ; }

void SnakeGame::redraw(){board.refresh();}

bool SnakeGame::isOver(){return game_over;}
