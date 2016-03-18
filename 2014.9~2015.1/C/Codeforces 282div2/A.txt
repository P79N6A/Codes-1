#include<stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	int number;
	while (scanf("%d", &number) == 1)
	{
		int a = 0, b = 0;
		switch (number / 10){
		case 0:a = 2; break;
		case 1:a = 7; break;
		case 2:a = 2; break;
		case 3:a = 3; break;
		case 4:a = 3; break;
		case 5:a = 4; break;
		case 6:a = 2; break;
		case 7:a = 5; break;
		case 8:a = 1; break;
		case 9:a = 2; break;
		}
		switch (number % 10){
		case 0:b = 2; break;
		case 1:b = 7; break;
		case 2:b = 2; break;
		case 3:b = 3; break;
		case 4:b = 3; break;
		case 5:b = 4; break;
		case 6:b = 2; break;
		case 7:b = 5; break;
		case 8:b = 1; break;
		case 9:b = 2; break;
		}
		printf("%d\n", a*b);
	}
	return 0;
}