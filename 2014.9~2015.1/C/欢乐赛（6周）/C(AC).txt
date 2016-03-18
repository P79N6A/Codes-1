#include<stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	int n,k,p[60];
	while (scanf("%d%d", &n,&k) == 2)
	{
		int numbers = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &p[i]);
		for (int i = 0; i < n; i++)
		{
			if (p[i] >= p[k - 1] && p[i]>0)
				numbers++;
		}
		printf("%d\n", numbers);
	}
	return 0;
}