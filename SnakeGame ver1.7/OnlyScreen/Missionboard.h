#pragma once
#include <curses.h>

class Missionboard {
	WINDOW* mission_win;

public:
	Missionboard();

	Missionboard(int width, int y, int x);

	void initialize(int trGrowthScore, int trPoisonScore, int trGateScore, int trLength);
	void wdelwin();
	void addAt(int y, int x, chtype ch);

	void growthScoreCheck();
	void poisonScoreCheck();
	void gateScoreCheck();
	void lengthCheck();
	void growthScoreUnCheck();
	void poisonScoreUnCheck();
	void gateScoreUnCheck();
	void lengthUnCheck();

	void clear();
	void refresh();
};
