#include<stdio.h>
#pragma warning(disable:4996)

int main()
{
	int N, M;
	char field[100][100];
	while (scanf("%d%d", &N, &M) == 2)
	{
		for (int n = 0; n < N; n++)
			gets(field[n]);
	}
	return 0;
}