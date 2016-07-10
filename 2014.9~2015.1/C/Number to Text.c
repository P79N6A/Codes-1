//number to text.
//It is really a challenge to me. XD
//It takes me over 4h.
//This is the second version.The first version was failed.TAT

#include<stdio.h>
#include<string.h>
#include<math.h>
#pragma warning(disable:4996)
int judge_n(unsigned long long n, char(*a)[15], int m);

int k;

int main(void)
{
	unsigned long long number, flag;
	while (scanf("%llu", &number) == 1)
	{
		k = 0, flag = 0;
		if (number == 0) flag = 1;//判断是否为0
		
		unsigned long long now = 0;//当前的三位是什么
		int m, lenth = 0;
		char c_num[100][15];
		for (m = 0;; m++)  //计算有几个三位
		{
			if (number / (unsigned long long)pow((double)10,3 * m) == 0)
				break;
		}
		//printf("m=%d\n",m);
		for (int i = m - 1; i>-1; i--)
		{
			now = number / (unsigned long long)pow((double)10, 3 * i);
			lenth = judge_n(now, c_num, i);
			number -= (unsigned long long)pow((double)10, 3 * i)*now; //辗转相减，得到之后的三位
		}
		for (int i = 0; i<lenth; i++)
		{
			printf("%s ", c_num[i]);
		}
		if (flag)
			printf("zero");
		printf("\n");
	}
	return 0;
}

int judge_n(unsigned long long n, char(*a)[15], int m)
{
	//printf("n/100=%llu\n",n/100);
	switch (n / 100)
	{
	case 1:strcpy(a[k++], "one hundred"); break;
	case 2:strcpy(a[k++], "two hundred"); break;
	case 3:strcpy(a[k++], "three hundred"); break;
	case 4:strcpy(a[k++], "four hundred"); break;
	case 5:strcpy(a[k++], "five hundred"); break;
	case 6:strcpy(a[k++], "six hundred"); break;
	case 7:strcpy(a[k++], "seven hundred"); break;
	case 8:strcpy(a[k++], "eight hundred"); break;
	case 9:strcpy(a[k++], "nine hundred"); break;
	default:break;
	}
	if (n % 100 >= 20)
	{
		switch (n % 100 / 10)
		{
		case 2:strcpy(a[k++], "twenty"); break;
		case 3:strcpy(a[k++], "thirty"); break;
		case 4:strcpy(a[k++], "forty"); break;
		case 5:strcpy(a[k++], "fifty"); break;
		case 6:strcpy(a[k++], "sixty"); break;
		case 7:strcpy(a[k++], "seventy"); break;
		case 8:strcpy(a[k++], "eighty"); break;
		case 9:strcpy(a[k++], "ninety"); break;
		default:break;
		}
		switch (n % 10)
		{
		case 1:strcpy(a[k++], "one"); break;
		case 2:strcpy(a[k++], "two"); break;
		case 3:strcpy(a[k++], "three"); break;
		case 4:strcpy(a[k++], "four"); break;
		case 5:strcpy(a[k++], "five"); break;
		case 6:strcpy(a[k++], "six"); break;
		case 7:strcpy(a[k++], "seven"); break;
		case 8:strcpy(a[k++], "eight"); break;
		case 9:strcpy(a[k++], "nine"); break;
		default:break;
		}
	}
	else
	{
		switch (n % 100)
		{
		case 1:strcpy(a[k++], "one"); break;
		case 2:strcpy(a[k++], "two"); break;
		case 3:strcpy(a[k++], "three"); break;
		case 4:strcpy(a[k++], "four"); break;
		case 5:strcpy(a[k++], "five"); break;
		case 6:strcpy(a[k++], "six"); break;
		case 7:strcpy(a[k++], "seven"); break;
		case 8:strcpy(a[k++], "eight"); break;
		case 9:strcpy(a[k++], "nine"); break;
		case 10:strcpy(a[k++], "ten"); break;
		case 11:strcpy(a[k++], "eleven"); break;
		case 12:strcpy(a[k++], "twelve"); break;
		case 13:strcpy(a[k++], "thirteen"); break;
		case 14:strcpy(a[k++], "fourteen"); break;
		case 15:strcpy(a[k++], "fifteen"); break;
		case 16:strcpy(a[k++], "sisteen"); break;
		case 17:strcpy(a[k++], "seventeen"); break;
		case 18:strcpy(a[k++], "eighteen"); break;
		case 19:strcpy(a[k++], "nineteen"); break;
		default:break;
		}
	}
	if (n)//if 防止多次调用switch
	{
		switch (m)
		{
		case 1:strcpy(a[k++], "thounsand"); break;
		case 2:strcpy(a[k++], "million"); break;
		case 3:strcpy(a[k++], "billion"); break;
		case 4:strcpy(a[k++], "trillion"); break;
		default:break;
		}
	}
	return k;
}
