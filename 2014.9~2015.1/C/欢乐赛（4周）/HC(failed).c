#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

int main(void)
{
	int r1, r2, c1, c2, d1, d2;
	while (scanf("%d%d\n%d%d\n%d%d", &r1, &r2,&c1,&c2,&d1,&d2) == 6)
	{
		int n[4],flag=0;
		n[0] = (2 * c1 - c2 - d2 + 2 * d1 + 2 * r1 - r2);
		n[1] = (r2 - 2 * r1 - 2 * d1 + d2 + 4 * c1 + c2);
		n[2] = (4 * r1 + r2 - 2 * c1 + c2 + d2 - 2 * d1);
		n[3] = (4 * d1 - 2 * r1 + r2 + d2 + c2 - 2 * c1);
		for (int i = 0; i < 4; i++)
		{
			if (n[i] % 6==0)
				flag = 1;
		}
		if (n[0] / 6 + n[2] / 6 != r1) flag = 0;
		if (n[1] / 6 + n[3] / 6 != r2) flag = 0;
		if (n[0] / 6 + n[1] / 6 != c1) flag = 0;
		if (n[2] / 6 + n[3] / 6 != c2) flag = 0;
		if (n[0] / 6 + n[3] / 6 != d1) flag = 0;
		if (n[2] / 6 + n[1] / 6 != d2) flag = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (n[i] == n[j])
					flag = 0;
			}
		}
		if (flag==1)
		{
			printf("%d %d\n%d %d\n", n[0] / 6, n[2] / 6, n[1] / 6, n[3] / 6);
		}
		else printf("-1\n");
	}
	return 0;
}