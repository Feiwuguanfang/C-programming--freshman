#include<stdio.h>
int main()
{
	int head, feet;
	printf("快说，头和小黑脚各有多少！\n");
	scanf_s("%d %d", &head, &feet);
	
	int a=0, b;
	for (int a = 0; a <= head; a++)
	{
		b = head - a;
		if (a * 4 + b * 2 == feet)
		{
			printf("小兔子有%d 只，小黑子有%d 只", a, b);
			
		}
	
	}
	return 0;




}