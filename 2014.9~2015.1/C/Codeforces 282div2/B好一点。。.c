#include<stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	long a, b,temp;
	while (scanf("%ld%ld", &a, &b) == 2)
	{
		int answer = 0;
		if (a - b > 0)
		{
			answer++;
			temp = a - b;
		}
		else {
			printf("infinity\n");
			continue;
		}
		for (long i = b+1; i < temp; i++)
		{
			if (temp%i == 0)
				answer++;
			//printf("%d:%d\n", i, answer);
		}
		printf("%d\n", answer);
	}
	return 0;
}