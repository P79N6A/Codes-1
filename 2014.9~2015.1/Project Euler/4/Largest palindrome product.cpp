#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main(void)
{
	int sum=0;
	char a[100];
	for (int i=100; i < 1000; i++)
	{
		for (int j = 100; j < 1000; j++)
		{
			int k = 1, lenth, flag = 1;
			sum = i*j;
			//printf("i=%d,j=%d,sum=%d\n",i,j, sum);
			for (;;)
			{
				if (sum-pow(10.0,k)>=0)
					k++;
				else break;
				//printf("i am here\n");
			}
			//printf("k=%d\n", k); system("pause");
			lenth = k;
			//printf("lenth=%d\n", lenth);
			for (int j = 0; j < lenth; j++)
			{
				a[j] =sum /(int) pow(10.0, lenth - 1 - j)+48;
				//printf("char=%c,sum/int=%d\n", a[j],(int)pow(10.0,lenth-1-j));
				sum -= (a[j]-48) * (int)pow(10.0, lenth - 1 - j);
				//printf("sum=%d\n", sum); system("pause");
			}
			for (int j = 0; j <lenth / 2; j++)
			{
				if (a[j] != a[lenth - 1 - j])
					flag = 0;
			}
			if (flag)
			{
				//printf("i=%d,j=%d,sum=%d\n", i, j, sum);
				for (int i = 0; i < lenth; i++)
					printf("%c", a[i]);
				printf("\n");
				//system("pause");
			}
		}
	}
	return 0;
}