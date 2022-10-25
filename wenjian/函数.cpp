

#include"test.h"


void paintGrid()

{
	for (int y = 0; y < 600; y += NODE_WIDTH)
	{
		line(0, y, 800, y);
	}
	for (int x = 0; x < 800; x += NODE_WIDTH)
	{
		line(x, 0, x, 600);
	}

}
void paintSnake(node* snake, int n)
{
	int left, top, right, bottom;
	for (int i = 0; i < n; i++)
	{
		left = snake[i].x * NODE_WIDTH;
		top = snake[i].y * NODE_WIDTH;
		right = (snake[i].x + 1) * NODE_WIDTH;
		bottom = (snake[i].y + 1) * NODE_WIDTH;
		solidrectangle(left, top, right, bottom);
	}

}

node snakemove(node* snake, int length, int direction)
{
	node tail = snake[length - 1];

	for (int i = length - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];
	}
	node newhead;
	newhead = snake[0];
	if (direction == eup)
	{
		newhead.y--;
	}
	else if (direction == edown)
	{
		newhead.y++;
	}
	else if (direction == eleft)
	{
		newhead.x--;
	}
	else
	{
		newhead.x++;
	}
	snake[0] = newhead;
	return tail;
}
void changedirection(enum direction* pD)
{
	if (_kbhit() != 0)
	{
		char c = _getch();
		switch (c)
		{
		case 'w':
			if (*pD != edown)
				*pD = eup;
			break;
		case 's':
			if (*pD != eup)
				*pD = edown;
			break;
		case 'a':
			if (*pD != eright)
				*pD = eleft;
			break;
		case 'd':
			if (*pD != eleft)
				*pD = eright;
			break;
		}
	}

}
void paintfood(node food)
{
	int left, top, right, bottom;
	left = food.x * NODE_WIDTH;
	top = food.y * NODE_WIDTH;
	right = (food.x + 1) * NODE_WIDTH;
	bottom = (food.y + 1) * NODE_WIDTH;
	setfillcolor(YELLOW);
	solidrectangle(left, top, right, bottom);
	setfillcolor(WHITE);

}

node creatfood(node* snake, int length)
{
	node food;
	while (1)
	{
		food.x = rand() % (800 / NODE_WIDTH);
		food.y = rand() % (600 / NODE_WIDTH);
		int i;
		for (i = 0; i < length; i++)
		{
			if (snake[i].x == food.x && snake[i].y == food.y)
			{
				break;
			}
		}
		if (i < length)
			continue;
		else
			break;
	}
	return food;
}

bool isgameover(node* snake, int length)
{
	if (snake[0].x < 0 || snake[0].x>800 / NODE_WIDTH)
		return true;
	if (snake[0].y < 0 || snake[0].y>600 / NODE_WIDTH)
		return true;
	for (int i = 1; i < length; i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
		{
			return true;
		}
	}
	return false;
}

void reset(node* snake, int* plength, enum direction* d)
{
	snake[0] = node{ 5,7 };
	snake[1] = node{ 4,7 };
	snake[2] = node{ 3,7 };
	snake[3] = node{ 2,7 };
	snake[4] = node{ 1,7 };
	*plength = 5;
	*d = eright;

}
