#include<stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	int n,i;
	while (scanf("%d", &n) == 1)
	{
		getchar();
		int height[105],l,max=0,min;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &height[i]);
		}
		l = i;
		/*for (int i = 0; i < n; i++)
		{
			printf("%d", height[i]);
		}*/
		//printf("l=%d\n", l);
		min = l-1;
		for (int i = 0; i < l; i++)
		{
			if (height[max] < height[i]) max = i;
			//printf("max=%d\n", max);
		}
		//printf("max=%d\n", max);
		for (int i = l-1; i>-1; i--)
		{
			if (height[min]>height[i]) min = i;
		}
		//printf("min=%d\n", min);
		if (max>min)
			printf("%d\n", max + l - min - 2);
		else printf("%d\n", max + l - min-1);
	}
	return 0;
}