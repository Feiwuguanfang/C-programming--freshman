#include<stdio.h>
	typedef struct student
	{
		char name[21];
		int sex;
		int birth;
		float height;
		int c;
		int math;
	}student;
	
int main()
{
    int n;
	student studentss[20];
	scanf_s("%d",&n);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%s%d%d%f%d%d", studentss[i].name, 21, &studentss[i].sex, &studentss[i].birth, &studentss[i].height, &studentss[i].c, &studentss[i].math);
	}
	int all_c=0, all_math=0, C_average, Calculus_average,C_higest,Calculus_higest,C_lowest,Calculus_lowest;
	for (int i = 0; i < n; i++)
	{
		all_c += studentss[i].c;
	}
	C_average = all_c / n;
	for (int i = 0; i < n; i++)
	{
		all_math += studentss[i].math;
	}
	Calculus_average = all_math / n;
	C_higest = studentss[0].c;
	Calculus_higest = studentss[0].math;
	C_lowest = studentss[0].c;
	Calculus_lowest = studentss[0].math;
	for (int i = 0; i < n - 1; i++)
	{

		if (studentss[i + 1].c > studentss[i].c)
		{
		
			C_higest = studentss[i + 1].c;
		
		}
	}
	for (int i = 0; i < n - 1; i++)
	{

		if (studentss[i + 1].math > studentss[i].math)
		{

			Calculus_higest = studentss[i + 1].math;

		}
	}
	for (int i = 0; i < n - 1; i++)
	{

		if (studentss[i + 1].math < studentss[i].math)
		{

			Calculus_lowest = studentss[i + 1].math;

		}
	}
	for (int i = 0; i < n - 1; i++)
	{

		if (studentss[i + 1].c < studentss[i].c)
		{

			C_lowest = studentss[i + 1].c;

		}
	}
	printf("C_average:%d\nC_max:%d\n", C_average, C_higest);
	
	for (int i = 0; i < n; i++)
	{
		if (studentss[i].c == C_higest)
			
		{
			printf("%s %d %d %.2f %d %d\n", studentss[i].name, studentss[i].sex, studentss[i].birth, studentss[i].height, studentss[i].c, studentss[i].math);
		}
	}
	printf("C_min:%d\nCalculus_average:%d\nCalculus_max:%d\n",C_lowest, Calculus_average, Calculus_higest);



	for (int i = 0; i < n; i++)
	{
		if (studentss[i].math == Calculus_higest)
		{
			printf("%s %d %d %.2f %d %d\n", studentss[i].name, studentss[i].sex, studentss[i].birth, studentss[i].height, studentss[i].c, studentss[i].math);
		}
	}
	printf("Calculus_min:%d\n",Calculus_lowest );
	return 0;

}





//int chosehigest(int nall, student num[20], int subject)//报错该这里
//{
//	if (subject == c)
//	{
//		int higest = num[0].c;
//		for (int i = 0; i < nall - 1; i++)
//		{
//
//			if (num[i + 1].c > num[i].c)
//			{
//				higest = num[i + 1].c;
//			}
//		}
//		return higest;
//
//	}