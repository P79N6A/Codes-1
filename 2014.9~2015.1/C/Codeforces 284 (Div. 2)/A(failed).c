#include<stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	int n, x, l[100005], r[100005];
	while (scanf("%d%d", &n, &x) == 2)
	{
		int sum = 0, k = 0, stop;
		for (int i = 0; i < n; i++)
			scanf("%d%d", &l[i], &r[i]);
		stop = r[n - 1] / x;
		for (int i = 1; i <= stop; i++)
		{
			if (i*x >= l[k] && i*k <= r[k])
			{
				sum += r[k] - (i - 1)*x;
				k++;
			}
			else if (i*x > r[k]&&i*x<l[k+1])
			{
				sum += r[k+1] - (i - 1)*x;
				k++;
				i--;
			}
			if (k == n)
				break;
		}
		printf("%d\n", sum);
	}
	return 0;
}