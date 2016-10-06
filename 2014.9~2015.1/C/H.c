#include<stdio.h>

#pragma warning(disable:4996)
int main(void)
{
	float a, x, y;
	int flag = 1, flag1 = 1;
	scanf("%f%f%f", &a, &x, &y);
	if (x < 0)
	{
		flag = 0; x = -1.0*x;
	}
	if (x < a / 2.0)
	{
		if (y < a&&y>0)
		{
			printf("1"); flag1 = 0;
		}
		else if (y>a&&y < 2.0 * a)
		{
			printf("2"); flag1 = 0;
		}
		else if (y>3.0 * a&&y < 4.0 * a)
		{
			printf("5"); flag1 = 0;
		}
		else if (y>2.0 * a&&y < 3.0 * a)
		{
			if (flag)
			{
				printf("4"); flag1 = 0;
			}
			else{
				printf("3"); flag1 = 0;
			}
		}
		else if (y>4.0 * a&&y < 5.0 * a)
		{
			if (flag)
			{
				printf("7"); flag1 = 0;
			}
			else {
				printf("6"); flag1 = 0;
			}
		}
	}
	else if (x < a)
	{
		if (y>2.0 * a&&y < 3.0 * a)
		{
			if (flag)
			{
				printf("4"); flag1 = 0;
			}
			else{
				printf("3"); flag1 = 0;
			}
		}
		else if (y>4.0 * a&&y < 5.0 * a)
		{
			if (flag)
			{
				printf("7"); flag1 = 0;
			}
			else {
				printf("6"); flag1 = 0;
			}
		}
	}
	if (flag1)
		printf("-1");
	return 0;
}