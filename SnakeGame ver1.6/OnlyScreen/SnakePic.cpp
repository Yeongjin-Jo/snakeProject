#include "SnakePic.h"

SnakePic::SnakePic() {
    snake_win = newwin(30, 25, 0, 45);
}

void SnakePic::initialize() {
    clear();
	wrefresh(snake_win);
};
void SnakePic::wdelwin() {
    delwin(snake_win);
};
void SnakePic::drawPart1() {
	mvwprintw(snake_win, 19, 0, "           ----------");
	mvwprintw(snake_win, 20, 0, "            --      --");
	mvwprintw(snake_win, 21, 0, "           --      --");
	mvwprintw(snake_win, 22, 0, "          --      --");
	mvwprintw(snake_win, 23, 0, "         --      --");
	mvwprintw(snake_win, 24, 0, "        --      --");
	mvwprintw(snake_win, 25, 0, "       --      --");
	mvwprintw(snake_win, 26, 0, "        --      --");
	mvwprintw(snake_win, 27, 0, "         --     --");
	mvwprintw(snake_win, 28, 0, "            ----");
	wrefresh(snake_win);
};
void SnakePic::drawPart2() {
	mvwprintw(snake_win, 9, 0, "      ----------");
	mvwprintw(snake_win, 10, 0, "    --      --");
	mvwprintw(snake_win, 11, 0, "    --      --");
	mvwprintw(snake_win, 12, 0, "    --      --");
	mvwprintw(snake_win, 13, 0, "    --      --");
	mvwprintw(snake_win, 14, 0, "     --      --");
	mvwprintw(snake_win, 15, 0, "      --      --");
	mvwprintw(snake_win, 16, 0, "       --      --");
	mvwprintw(snake_win, 17, 0, "         --      --");
	mvwprintw(snake_win, 18, 0, "          --      --");
	wrefresh(snake_win);
};
void SnakePic::drawPart3() {
	mvwprintw(snake_win, 2, 0, "        |");
	mvwprintw(snake_win, 3, 0, "       -|----");
	mvwprintw(snake_win, 4, 0, "     ---|   0  --");
	mvwprintw(snake_win, 5, 0, "       --        --");
	mvwprintw(snake_win, 6, 0, "        --       --");
	mvwprintw(snake_win, 7, 0, "       --       --");
	mvwprintw(snake_win, 8, 0, "      --       --");
	wrefresh(snake_win);
};

void SnakePic::clear() {
    wclear(snake_win);
}

void SnakePic::refresh() {
    wrefresh(snake_win);
};