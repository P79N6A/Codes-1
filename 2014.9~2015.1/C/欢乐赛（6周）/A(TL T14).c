#include<stdio.h>
#pragma warning(disable:4996)
int a[100000], b[100000], l[100000] = { 0 }, r[100000] = { 0 };

int main(void)
{
	int n, m, x, y;
	while (scanf("%d%d%d%d", &n, &m, &x, &y) == 4)
	{
		int k = 0,j=0,position=0;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int j = 0; j < m; j++)
			scanf("%d", &b[j]);
		for (int i = 0; i < n; i++)
		{
			for (; j < m; j++)
			{
				if (a[i] - x <= b[j] && b[j] <= a[i] + y)
				{
					l[k] = i + 1;
					//printf("i=%d,k=%d,l[k]=%d\n",i, k, l[k]);
					r[k] = j + 1;
					k++;
					position = j;
					break;
				}
			}
			j = position+1;
		}
		printf("%d\n", k);
		for (int i = 0; i < k; i++)
			printf("%d %d\n", l[i], r[i]);
	}
	return 0;

}