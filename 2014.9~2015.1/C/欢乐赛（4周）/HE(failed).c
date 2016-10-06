#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int main(void)
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		getchar();
		int flag = 1,l,sum1=0,sum2=0;
		char number[55];
		gets(number);
		l = strlen(number);
		//printf("%c\n", number[l - 2]);
		if (number[l - 2] != '4' && number[l - 2] != '7')
			flag = 0;
		for (int i = 0; i < n/2; i++)
		{
			sum1 += number[i];
			sum2 += number[i + n / 2];
		}
		if (sum1 != sum2)
			flag = 0;
		if (flag)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}