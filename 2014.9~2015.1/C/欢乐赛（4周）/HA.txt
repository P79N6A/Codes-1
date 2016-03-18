#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int main(void)
{
	char s[10];
	while(gets(s))
	{
		char temp;
		for (int j = 0; j < 2; j++)
		{
			int min = j;
			for (int i = j; i < 3; i++)
			{
				if (s[min]>s[i])
					min = i;
			}
			temp = s[min];
			s[min] = s[j];
			s[j] = temp;
		}
		for (int i = 0; i < 2; i++)
			printf("%c ", s[i]);
		printf("%c\n", s[2]);
	}
	return 0;
}