#include "Scoreboard.h"

Scoreboard::Scoreboard(){}

Scoreboard::Scoreboard(int width, int y, int x)
{
	score_win = newwin(15, width+3, y, x+5);
}

void Scoreboard::initialize(int maxLength)
{
	clear();
	box(score_win, '|', '-');
	addAt(0, 0, '*');
	addAt(0, 42, '*');
	addAt(14, 0, '*');
	addAt(14, 42, '*');


	mvwprintw(score_win, 1, 1, "Scoreboard:");
	mvwprintw(score_win, 3, 1, "B : (0) / (%d)", maxLength);
	mvwprintw(score_win, 4, 1, "+ : 0");
	mvwprintw(score_win, 5, 1, "- : 0");
	mvwprintw(score_win, 6, 1, "G : 0");
	
	wrefresh(score_win);
	refresh();
}
void Scoreboard::wdelwin() {
	delwin(score_win);
};
void Scoreboard::addAt(int y, int x, chtype ch)
{
	mvwaddch(score_win, y, x, ch);
}

void Scoreboard::updateGrowthScore(int growthScore)
{
	mvwprintw(score_win, 4, 1, "+ : %d", growthScore);
}
void Scoreboard::updatePoisonScore(int poisonScore)
{
	mvwprintw(score_win, 5, 1, "- : %d", poisonScore);
}
void Scoreboard::updateGateScore(int gateScore)
{
	mvwprintw(score_win, 6, 1, "G : %d", gateScore);
}
void Scoreboard::updateLength(int currLength)
{
	mvwprintw(score_win, 3, 1, "B : (%d)", currLength);
}

void Scoreboard::clear()
{
	wclear(score_win);
}

void Scoreboard::refresh()
{
	wrefresh(score_win);
}