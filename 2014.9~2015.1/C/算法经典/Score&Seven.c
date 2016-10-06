// 统计得分，根据O连续出现的次数
//不是O则置零

#include<stdio.h>
#pragma warning(disable:4996)
int main(void)
{
	char str[88];
	while (gets(str))
	{
		int i = 0,count=0,sum=0;
		while (str[i++])
		{
			//printf("%d\n", i);
			if (str[i-1] == 'O')
				count++;
			else count = 0;
			//printf("%d:%d\n", i - 1, count);
			sum += count;
		}
		printf("%d\n", sum);
	}
	return 0;
}