#pragma once
#include <curses.h>

class Scoreboard
{
	WINDOW *score_win;
public:
	Scoreboard();

	Scoreboard(int width, int y, int x);
	
	void initialize(int maxLength);
	void wdelwin();
	void addAt(int y, int x, chtype ch);

	void updateGrowthScore(int growthScore);
	void updatePoisonScore(int poisonScore);
	void updateGateScore(int gateScore);
	void updateLength(int currLength);

	void clear();

	void refresh();
};
