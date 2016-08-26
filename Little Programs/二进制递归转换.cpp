/*use recursion to convert the decimal number into
binary number.(使用递归进行二进制转换）*/

#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void convert(unsigned long a) 
{
	unsigned long b = a % 2;
	if (a >= 2)
		convert(a / 2);
	printf("%lu", b);
}

int main(void)
{
	unsigned long decimal_number;
	char judge = 'y';
	while (judge == 'y')         //whether the user want to use this project again(用户是否愿意再次输入）
	{
		printf("Please enter a decimal number:");
		while ((scanf("%lu", &decimal_number)) == 1)
		{
			convert(decimal_number);
			putchar('\n');
			printf("Please enter a decimal number:");
		}
		while (getchar() != '\n')     //过滤输入不正确的字符，将回车代入getchar()，使后期赋值能正常进行
			continue;
		printf("Incorrect input!\n");
		printf("Do you want to enter again?(y/n)");
		judge = getchar();
	}
	system("pause");
	return 0;
}