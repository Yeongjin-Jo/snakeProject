#include "SnakeGame.h"

void SnakeGame::handleNextPiece(SnakePiece next)
{
	if (apple != NULL)
	{
		switch (board.getCharAt(next.getY(), next.getX()))
		{
		case 'A':
			eatApple();
			break;

		case 'P':
			eatPoison();
			board.add(Empty(snake.tail().getY(), snake.tail().getX()));
			snake.removePiece();
			break;

		case ' ':
		{
			int emptyRow = snake.tail().getY();
			int emptyCol = snake.tail().getX();
			board.add(Empty(emptyRow, emptyCol));
			snake.removePiece();
			break;
		}

		// gate에 도달했을 때의 코드 만들기
		case 'G':
		{
			board.time += snake.prev_pieces.size();	// 스네이크의 길이만큼 시간을 추가함으로써 gate가 유지되게끔 한다.
			gateScore += 100;
			scoreboard.updateGateScore(gateScore);
			if (next.getY() == (*gate1).getY() && next.getX() == (*gate1).getX())
			{
				next = passGate(gate2);
				int emptyRow = snake.tail().getY();
				int emptyCol = snake.tail().getX();
				board.add(Empty(emptyRow, emptyCol));
				snake.removePiece();
			}

			else if (next.getY() == (*gate2).getY() && next.getX() == (*gate2).getX())
			{
				next = passGate(gate1);
				int emptyRow = snake.tail().getY();
				int emptyCol = snake.tail().getX();
				board.add(Empty(emptyRow, emptyCol));
				snake.removePiece();
			}

			break;
		}

		case '1':	// 벽에 부딪힌 경우 게임오버
		case '#':	// 자기 몸에 닿아도 게임오버
			game_over = true;
			break;
		}
	}
	
	board.time -= 1;
	board.add(next);
	snake.addPiece(next);
	scoreboard.updateLength(snake.prev_pieces.size());
}

void SnakeGame::createApple()
{
	int y, x;
	board.getEmptyCoordinates(y, x);
	apple = new Apple(y, x);
	board.add(*apple);
}

void SnakeGame::eatApple()
{
	currentLength++;
	delete apple;
	apple = NULL;
	growthScore += 100;
	scoreboard.updateGrowthScore(growthScore);
}

void SnakeGame::deleteApple()
{
	board.add(Drawable(apple->getY(), apple->getX(), ' '));
	delete apple;
	apple = NULL;
}

void SnakeGame::createPoison()
{
	int y, x;
	board.getEmptyCoordinates(y, x);
	poison = new Poison(y, x);
	board.add(*poison);
}

void SnakeGame::eatPoison()
{
	currentLength--;
	poisonScore += 100;
	delete poison;
	poison = NULL;
	board.add(Empty(snake.head().getY(), snake.head().getX()));
	snake.removeBackPiece();
	scoreboard.updatePoisonScore(poisonScore);
}

// void SnakeGame::deletePoison()
void SnakeGame::deletePoison()
{
	board.add(Drawable(poison->getY(), poison->getX(), ' '));
	delete poison;
	poison = NULL;
}

void SnakeGame::createGate()
{
	int y, x;
	board.getOneCoordinates(y, x);
	gate1 = new Gate(y, x);
	board.add(*gate1);

	board.getOneCoordinates(y, x);
	gate2 = new Gate(y, x);
	board.add(*gate2);
}

void SnakeGame::deleteGate()
{
	// 기존 gate 좌표의 값을 1로 수정
	board.add(Drawable((*gate1).getY(), (*gate1).getX(), '1'));
	board.add(Drawable((*gate2).getY(), (*gate2).getX(), '1'));

	delete gate1;
	delete gate2;
	gate1 = NULL;
	gate2 = NULL;
}

SnakePiece SnakeGame::passGate(Gate* g)
{
	int tempPosX = (*g).getX();
	int tempPosY = (*g).getY();

	bool possibleLeft = false;
	bool possibleRight = false;
	bool possibleUp = false;
	bool possibleDown = false;

	Direction direction = snake.getDirection();

	if (board.getCharAt(tempPosY + 1, tempPosX) == ' ')
	{
		possibleDown = true;
	}
	if (board.getCharAt(tempPosY, tempPosX + 1) == ' ')
	{
		possibleRight = true;
	}
	if (board.getCharAt(tempPosY - 1, tempPosX) == ' ')
	{
		possibleUp = true;
	}
	if (board.getCharAt(tempPosY, tempPosX - 1) == ' ')
	{
		possibleLeft = true;
	}

	//진입방향과 일치하는 경우
	if (possibleLeft && direction == left)
	{
		tempPosX -= 1;
	}
	else if (possibleRight && direction == right)

	{
		tempPosX += 1;
	}
	else if (possibleUp && direction == up)
	{
		tempPosY -= 1;
	}
	else if (possibleDown && direction == down)
	{
		tempPosY += 1;
	}

	//snake의 direction을 바꿔야하는 경우 
	else if (direction == up || direction == down)
	{
		if (possibleLeft)
		{
			tempPosX -= 1;
			snake.setDirection(left);
		}
		else if (possibleRight)
		{
			tempPosX += 1;
			snake.setDirection(right);
		}
		else if (possibleUp)
		{
			tempPosY -= 1;
			snake.setDirection(up);
		}
		else if (possibleDown)
		{
			tempPosY += 1;
			snake.setDirection(down);
		}
	}

	else if (direction == left || direction == right)
	{
		if (possibleDown)
		{
			tempPosY += 1;
			snake.setDirection(down);
		}
		else if (possibleUp)
		{
			tempPosY -= 1;
			snake.setDirection(up);
		}
		else if (possibleLeft)
		{
			tempPosX -= 1;
			snake.setDirection(left);
		}
		else if (possibleRight)
		{
			tempPosX += 1;
			snake.setDirection(right);
		}
	}
	return SnakePiece(tempPosY, tempPosX);
}

SnakeGame::SnakeGame(int height, int width, int speed = 300)
{
	board = Board(height, width, speed);
	int sb_row = board.getStartRow();
	int sb_col = board.getStartCol();
	scoreboard = Scoreboard(width, sb_row, sb_col);
	missionboard = Missionboard(width, sb_row, sb_col);
	snakepic = SnakePic();
	initialize1();	// map1 실행
}

SnakeGame::~SnakeGame()
{
	delete apple;
	delete poison;
	delete gate1;
	delete gate2;
}

void SnakeGame::initialize1()
{
	std::deque<SnakePiece> empty;
	std::swap(snake.prev_pieces, empty);
	apple = NULL;
	poison = NULL;
	gate1 = NULL;
	gate2 = NULL;
	board.makeMap1();
	growthScore = 0;
	poisonScore = 0;
	maxLength = 30;
	gateScore = 0;
	trGrowthScore = 300; trPoisonScore = 0; trGateScore = 100, trLength = 5;
	scoreboard.initialize(maxLength);
	missionboard.initialize(trGrowthScore, trPoisonScore, trGateScore, trLength);
	snakepic.initialize();

	game_over = false;
	srand(time(NULL));

	snake.setDirection(down);

	handleNextPiece(SnakePiece(1, 1));
	handleNextPiece(snake.nexthead());
	handleNextPiece(snake.nexthead());
	snake.setDirection(right);
	handleNextPiece(snake.nexthead());
	scoreboard.updateLength(snake.prev_pieces.size());

	// create apple
	if (apple == NULL)
	{
		createApple();
	}

	if (poison == NULL)
	{
		createPoison();
	}

	// create gate
	if (gate1 == NULL || gate2 == NULL)
	{
		createGate();
	}
}

void SnakeGame::initialize2()
{
	std::deque<SnakePiece> empty;
	std::swap(snake.prev_pieces, empty);
	trGrowthScore = 800; trPoisonScore = 300; trGateScore = 300, trLength = 8;
	apple = NULL;
	poison = NULL;
	gate1 = NULL;
	gate2 = NULL;
	board.makeMap2();
	growthScore = 0;
	poisonScore = 0;
	maxLength = 30;
	gateScore = 0;
	scoreboard.initialize(maxLength);
	missionboard.initialize(trGrowthScore, trPoisonScore, trGateScore, trLength);
	snakepic.initialize();

	game_over = false;
	srand(time(NULL));

	snake.setDirection(down);

	handleNextPiece(SnakePiece(1, 1));
	handleNextPiece(snake.nexthead());
	handleNextPiece(snake.nexthead());
	snake.setDirection(right);
	handleNextPiece(snake.nexthead());
	scoreboard.updateLength(snake.prev_pieces.size());

	// create apple
	if (apple == NULL)
	{
		createApple();
	}

	if (poison == NULL)
	{
		createPoison();
	}

	// create gate
	if (gate1 == NULL || gate2 == NULL)
	{
		createGate();
	}
}

void SnakeGame::initialize3()
{
	std::deque<SnakePiece> empty;
	std::swap(snake.prev_pieces, empty);
	trGrowthScore = 1200; trPoisonScore = 500; trGateScore = 500, trLength = 10;
	apple = NULL;
	poison = NULL;
	gate1 = NULL;
	gate2 = NULL;
	board.makeMap3();
	growthScore = 0;
	poisonScore = 0;
	maxLength = 30;
	gateScore = 0;
	scoreboard.initialize(maxLength);
	missionboard.initialize(trGrowthScore, trPoisonScore, trGateScore, trLength);
	snakepic.initialize();

	game_over = false;
	srand(time(NULL));

	snake.setDirection(down);

	handleNextPiece(SnakePiece(1, 1));
	handleNextPiece(snake.nexthead());
	handleNextPiece(snake.nexthead());
	snake.setDirection(right);
	handleNextPiece(snake.nexthead());
	scoreboard.updateLength(snake.prev_pieces.size());

	// create apple
	if (apple == NULL)
	{
		createApple();
	}

	if (poison == NULL)
	{
		createPoison();
	}

	// create gate
	if (gate1 == NULL || gate2 == NULL)
	{
		createGate();
	}
}

void SnakeGame::initialize4()
{
	std::deque<SnakePiece> empty;
	std::swap(snake.prev_pieces, empty);
	trGrowthScore = 2000; trPoisonScore = 1000; trGateScore = 1000, trLength = 15;
	apple = NULL;
	poison = NULL;
	gate1 = NULL;
	gate2 = NULL;
	board.makeMap4();
	growthScore = 0;
	poisonScore = 0;
	maxLength = 30;
	gateScore = 0;
	scoreboard.initialize(maxLength);
	missionboard.initialize(trGrowthScore, trPoisonScore, trGateScore, trLength);
	snakepic.initialize();

	game_over = false;
	srand(time(NULL));

	snake.setDirection(down);

	handleNextPiece(SnakePiece(1, 1));
	handleNextPiece(snake.nexthead());
	handleNextPiece(snake.nexthead());
	snake.setDirection(right);
	handleNextPiece(snake.nexthead());
	scoreboard.updateLength(snake.prev_pieces.size());

	// create apple
	if (apple == NULL)
	{
		createApple();
	}

	if (poison == NULL)
	{
		createPoison();
	}

	// create gate
	if (gate1 == NULL || gate2 == NULL)
	{
		createGate();
	}
}

void SnakeGame::allClearInitializer() {
	growthScore = -100; poisonScore = -100; gateScore = -100; trLength = 999999;
	board.clear(); scoreboard.clear(); missionboard.clear(); snakepic.clear();
	board.wdelwin(); scoreboard.wdelwin(); missionboard.wdelwin(); snakepic.wdelwin();
	
	
	initscr();
	resize_term(26, 100);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	init_pair(2, COLOR_WHITE, COLOR_RED);
	//bkgd(COLOR_PAIR(1));
	border('*', '*', '*', '*', '*', '*', '*', '*');
	
	refresh();

	WINDOW* win1;
	win1 = newwin(13, 51, 6, 24);
	wbkgd(win1, COLOR_PAIR(2));
	wattron(win1, COLOR_PAIR(2));
	wborder(win1, '+', '+', '+', '+', '+', '+', '+', '+');
	mvwprintw(win1, 6, 22, "Clear!!");
	wrefresh(win1);
	getch();
	delwin(win1);
	endwin();
}

void SnakeGame::gameOverInitializer() {
	growthScore = -100; poisonScore = -100; gateScore = -100; trLength = 999999;
	board.clear(); scoreboard.clear(); missionboard.clear();
	board.wdelwin(); scoreboard.wdelwin(); missionboard.wdelwin();

	initscr();
	resize_term(26, 100);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	init_pair(2, COLOR_WHITE, COLOR_RED);
	//bkgd(COLOR_PAIR(1));
	border('*', '*', '*', '*', '*', '*', '*', '*');

	refresh();

	WINDOW* win1;
	win1 = newwin(13, 51, 6, 24);
	wbkgd(win1, COLOR_PAIR(2));
	wattron(win1, COLOR_PAIR(2));
	wborder(win1, '-', '-', '-', '-', '-', '-', '-', '-');
	mvwprintw(win1, 6, 22, "GameOver...");
	wrefresh(win1);
	getch();
	delwin(win1);
	endwin();
}

void SnakeGame::processInput()
{
	// 조건?
	chtype input = board.getInput();	// 입력 

	switch (input)
	{
	case KEY_UP:
	case 'w':
		if (snake.getDirection() != down)
			snake.setDirection(up);
		else
			game_over = true;
		break;

	case KEY_DOWN:
	case 's':
		if (snake.getDirection() != up)
			snake.setDirection(down);
		else
			game_over = true;
		break;

	case KEY_LEFT:
	case 'a':
		if (snake.getDirection() != right)
			snake.setDirection(left);
		else
			game_over = true;
		break;

	case KEY_RIGHT:
	case 'd':
		if (snake.getDirection() != left)
			snake.setDirection(right);
		else
			game_over = true;
		break;

	case 'p':	// 일시정지
		board.setTimeout(-1);
		while (board.getInput() != 'p')
			;
		board.setTimeout(300);
		break;

	default:
		break;
	}
}

void SnakeGame::updateState()
{
	handleNextPiece(snake.nexthead());

	if (board.time == 0)	// 시간이 0가 되면 gate를 이동시키고 시간은 다시 50으로 세팅.
	{
		deleteApple();
		deletePoison();
		deleteGate();
		board.time = 50;
	}

	if (apple == NULL)
	{
		createApple();
	}

	if (poison == NULL)
	{
		createPoison();
	}

	if (gate1 == NULL || gate2 == NULL)
	{
		createGate();
	}
	if (growthScore >= trGrowthScore) { 
		growthclear = true; 
		missionboard.growthScoreCheck();
		snakepic.drawPart1();
	}
	else {
		growthclear = false;
		missionboard.growthScoreUnCheck();
	}
	if (poisonScore >= trPoisonScore) { 
		poisonclear = true; 
		missionboard.poisonScoreCheck();
	}
	else {
		poisonclear = false;
		missionboard.poisonScoreUnCheck();
	}
	if (gateScore >= trGateScore) { 
		gateclear = true;
		missionboard.gateScoreCheck();
		snakepic.drawPart3();
	}
	else {
		gateclear = false;
		missionboard.gateScoreUnCheck();
	}
	if (snake.prev_pieces.size() >= trLength) { 
		lengthclear = true; 
		missionboard.lengthCheck();
		snakepic.drawPart2();
	}
	else {
		lengthclear = false;
		missionboard.lengthUnCheck();
	}

	if (growthclear && poisonclear && gateclear && lengthclear)
		clear = true;

	if (clear == true && stage == 1) {
		stage++;
		clear = false;
		initialize2();
	}

	if (clear == true && stage == 2) {
		stage++;
		clear = false;
		initialize3();
	}

	if (clear == true && stage == 3) {
		stage++;
		clear = false;
		initialize4();
	}
	if (clear == true && stage == 4) {
		allClearInitializer();
	}

	if (currentLength < 3)
	{
		game_over = true;
	}
}

void SnakeGame::redraw()
{
	board.refresh();
	scoreboard.refresh();
}

bool SnakeGame::isOver()
{
	return game_over;
}

bool SnakeGame::isClear() {
	return clear;
}

int SnakeGame::getMaxLength() { return maxLength; }