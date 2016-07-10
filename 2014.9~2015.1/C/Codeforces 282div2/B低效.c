#include<stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	long a, b;
	while (scanf("%ld%ld", &a, &b) == 2)
	{
		int answer = 0;
		for (long i = b + 1; i < a; i++)
		{
			for (long j = 1; a - j*i>0; j++)
			{
				if (a - j*i == b)
					answer++;
			}
		}
		if (answer)
			printf("%d\n", answer);
		else printf("infinity\n");
	}
	return 0;
}