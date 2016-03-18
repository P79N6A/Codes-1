/*
 *输出倒三角形（inverted triangle)
 *
 */

#include<stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	int n;     //n lines
	while (scanf("%d", &n) == 1)    //测试数据80很好看呢~~
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
				printf(" ");
			for (int j =0; j<2*(n+1-i)-1; j++)
			{
				printf("#");
			}
			printf("\n");
		}
	}
	return 0;
}