#include<stdio.h>

int main(void)
{
	int n, m;
	char s[105][105];
	while (scanf("%d%d", &n, &m) == 2)
	{
		int k = 0,remove=0,flag=0;
		int co[105][105] = { 0 }, c[105] = { 0 };
		getchar();
		for (int i = 0; i < n; i++)
		{
			gets(s[i]);
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n-1; j++)
			{
				if (s[j][i] > s[j + 1][i])
				{
					c[i] = 1;
					//printf("hah\n");
				}
			}
		}
		for (int i = 0; i < m; i++)
		{
			if (c[i]==1)
			{
				k = i+1; remove = k; break;
			}
		}
		//printf("%d\n",remove);
		for (int i = 0; i < n; i++)
		{
			for (int j = k; j < m-1; j++)
			{
				if (s[i][j]>s[i][j + 1])
				{
					co[i][j] = 1;
				}
			}
		}
		for (int i = k; i < m-1; i++)
		{
			flag = 0;
			for (int j = 0; j < n; j++)
			{
				if (co[j][i])
				{
					flag = 1;
				}
			}
			if (flag)
			{
				remove++;
				printf("%d:%d\n",i,remove);
			}
		}
		printf("%d\n", remove);
	}
	return 0;
}
