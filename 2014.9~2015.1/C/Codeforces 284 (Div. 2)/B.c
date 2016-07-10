#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int main(void)
{
	int n, m;
	char a[3005][11], b[3005][11],c[3005][11],co[3005][11];
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (int i = 0; i < m; i++)
			scanf("%s%s", a[i], b[i]);
		for (int i = 0; i < n; i++)
			scanf("%s", c[i]);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				if (strcmp(c[i], a[j]) == 0)
				{
					if (strlen(a[j])>strlen(b[j]))
						strcpy(co[i], b[j]);
					else strcpy(co[i], a[j]);
				}
			}
		}
		for (int i = 0; i < n - 1; i++)
			printf("%s ", co[i]);
		printf("%s\n", co[n - 1]);
	}
	return 0;
}