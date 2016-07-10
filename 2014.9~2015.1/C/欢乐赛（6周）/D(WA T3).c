#include<stdio.h>
#include<string.h>
#include<math.h>
#pragma warning(disable:4996)

int main(void)
{
	int n, d, t[1005];
	char name_l[1005][100], name_r[1005][100],namef_l[1005][100],namef_r[1005][100];
	while (scanf("%d%d", &n,&d) == 2)
	{
		int number = 0,flag;
		for (int i = 0; i < n; i++)
		{
			scanf("%s %s %d", name_l[i], name_r[i], &t[i]);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (strcmp(name_l[i], name_r[j]) == 0)
				{
					flag = 1;
					if (strcmp(name_r[i], name_l[j]) == 0 && abs(t[j] - t[i]) <= d)
					{
						for (int k = 0; k < number; k++)
						{
							if (strcmp(name_r[i], namef_l[k]) == 0 || strcmp(name_r[i], namef_r[k]) == 0)
								flag = 0;
						}
						if (flag)
						{
							strcpy(namef_l[number], name_l[i]);
							strcpy(namef_r[number], name_r[i]);
							strcpy(name_l[i], "\0");
							strcpy(name_r[i], "\0");
							number++;
						}
					}
				}
			}
		}
		printf("%d\n", number);
		for (int i = 0; i < number; i++)
		{
			printf("%s %s\n", namef_l[i], namef_r[i]);
		}
	}
	return 0;
}