#include"test.h"

int main()
{
	initgraph(800, 600);
	setbkcolor(RGB(164, 225, 202));
	cleardevice();
	node snake[100] = { {5,7},{4,7},{3,7},{2,7},{1,7} };
	int length = 5;
	enum direction d = eright;

	srand(unsigned int(time(NULL)));
	node food = creatfood(snake, length);
	while (1)
	{
		cleardevice();
		paintGrid();
		paintSnake(snake, length);
		paintfood(food);
		Sleep(500);
		changedirection(&d);

		node lasttail = snakemove(snake, length, d);
		if (snake[0].x == food.x && snake[0].y == food.y)
		{
			if (length < 100)
			{
				snake[length] = lasttail;
				length++;
			}
			food = creatfood(snake, length);
		}
		if (isgameover(snake, length) == true)
		{
			reset(snake, &length, &d);
			food = creatfood(snake, length);
		}
	}
	getchar();
	closegraph();
	return 0;


}









