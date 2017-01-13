﻿#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

char random_number[4];


void show_line(void)   //产生分界线
{
	int i;
	for (i = 0; i < 80; i++)
		putchar('=');
}

void creat(void)  //产生四位数
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 4; i++)
		random_number[i] = '0' + rand() % 9 + 1;
}

void warning(void)
{
	printf("Please enter 4 positive numbers.eg:1123,1234,9943.\n");
}

int judge(char s[4])     //判断是否是四位数
{
	int judge = 1,i;
	if (s[0] == '0')
		judge = 0;
	for (i = 0; i < 4; i++)
	{
		if (s[i]<'0' || s[i]>'9')
			judge = 0;
	}
	return judge;
}

int main(void)
{
	int JUDGE;
	char guessnumber[5];
	printf("Guess Number Game 2 [Version 0.6]\n"
		"Copyright <c> 2014  632 Technical Team. All Right Reserved.\n\n");
	show_line();
	printf("这是一个猜数字游戏，规则如下：\n""系统将随机产生一个四位数，请您进行猜测，我们会将"
		"您输入的数字进行匹配。\n");
	creat(); //产生四位数
	printf("Please enter four integer numbers:\n");
	printf("依次输入四位数的每一位数\n");
	/*下面用户自行输入数咯*/
	gets(guessnumber);
	JUDGE=judge(guessnumber);   //判断是否是四位数
	while (JUDGE == 1)
	{
		printf("The number you write is:\n");
		for (int i = 0; i < 4; i++)
			printf("%c", guessnumber[i]);
		int f = 0;
		while (f < 4)
		{
			if (random_number[f] == guessnumber[f])
			{
				printf("第%d位等\n", f + 1); 
			}
			else
			{
				printf("第%d位不等\n", f + 1);
			}
			f++;
		}
		show_line();
		printf("Please enter four integer numbers:\n");
		printf("依次输入四位数的每一位数\n");
		gets(guessnumber);
	}
	if (JUDGE==0) warning();
	return 0;
}