#include"stdafx.h"

void showinformation()
{
	printf("|--------------------------------------------------|\n");
	printf("|         目前仅能支持原码转换为反码和补码.        |\n");
	printf("|--------------------------------------------------|\n");
	printf("|                 True code: 原 码                 |\n");
	printf("|      Ones-complement code: 反 码                 |\n");
	printf("|         Complemental code: 补 码                 |\n");
	printf("|--------------------------------------------------|\n\n");
}

void shownumber(int *a,int k)
{
	for (int i = 0; i < k; i++)
		printf("%d", a[i]);
	printf("\n");
}

void Myjudge(char *a,int lenth)
{
	for (int i = 0; i < lenth; i++)   //judge if it is a binary number
	{
		if (a[i] == '0' || a[i] == '1')
			continue;
		else
		{
			printf("This is not a binary number!\a\n");
			exit(0);
		}
	}
}

void change(int *a, int lenth)//change to the opposite
{
	for (int i = 1; i < lenth; i++)
	{
		if (a[i] == 0)
			a[i] = 1;
		else if (a[i] == 1)
			a[i] = 0;
	}
}