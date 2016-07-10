/*
 * 输入正整数a,b,c(enter integer a,b,c)
 * 输出a/b的小数形式(print a/b)
 * 精确到小数点后c位(calculate to 'c' decimal places)
 */

#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

int main(void)
{
	int a, b, c;
	double decimal;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		if (b == 0 || a == 0 && b == 0 && c == 0)
			break;
		decimal = (double)a / b;
		printf("%.*lf\n", c,decimal);
	}
	return 0;
}