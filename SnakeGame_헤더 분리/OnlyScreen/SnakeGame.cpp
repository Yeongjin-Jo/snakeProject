#include "SnakeGame.h"

void SnakeGame::handleNextPiece(SnakePiece next)
{
	if (apple != NULL || poison != NULL)
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

		// gate�� �������� ���� �ڵ� �����
		case 'G':
		{
			board.time += snake.prev_pieces.size();	// ������ũ�� ���̸�ŭ �ð��� �߰������ν� gate�� �����ǰԲ� �Ѵ�.

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

		case '1':	// ���� �ε��� ��� ���ӿ���
		case '#':	// �ڱ� ���� ��Ƶ� ���ӿ���
			game_over = true;
			break;
		}
	}

	board.time -= 1;
	board.add(next);
	snake.addPiece(next);
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
	maxLength++;
	delete apple;
	apple = NULL;
	score += 100;
	scoreboard.updateScore(score);
}

// void SnakeGame::deleteApple()
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
	delete poison;
	poison = NULL;
	board.add(Empty(snake.head().getY(), snake.head().getX()));
	snake.removeBackPiece();
	score -= 100;
	scoreboard.updateScore(score);
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
	// ���� gate ��ǥ�� ���� 1�� ����
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

	//���Թ���� ��ġ�ϴ� ���
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

	//snake�� direction�� �ٲ���ϴ� ��� 
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
	initialize();	// ������ ����
}

SnakeGame::~SnakeGame()
{
	delete apple;
	delete poison;
	delete gate1;
	delete gate2;
}

void SnakeGame::initialize()
{
	apple = NULL;
	poison = NULL;
	gate1 = NULL;
	gate2 = NULL;
	currentLength = 4;
	maxLength = 4;
	usingApple = 0;
	usingPoison = 0;
	board.initialize();
	score = 0;
	scoreboard.initialize(score);
	game_over = false;
	srand(time(NULL));

	snake.setDirection(down);

	handleNextPiece(SnakePiece(1, 1));
	handleNextPiece(snake.nexthead());
	handleNextPiece(snake.nexthead());
	snake.setDirection(right);
	handleNextPiece(snake.nexthead());

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

void SnakeGame::processInput()
{
	chtype input = board.getInput();	// �Է�
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

		case 'p':	// �Ͻ�����
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

	if (board.time == 0)	// �ð��� 0�� �Ǹ� gate�� �̵���Ű�� �ð��� �ٽ� 50���� ����.
	{
		deleteApple();
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

int SnakeGame::getScore()
{
	return score;
}

int SnakeGame::getCurrentLength()
{
	return currentLength;
}

int SnakeGame::getMaxLength()
{
	return maxLength;
}

int SnakeGame::getUsingApple()
{
	return usingApple;
}

int SnakeGame::getUsingPoison()
{
	return usingPoison;
}
