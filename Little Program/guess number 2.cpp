«Ívÿÿ^1-51    e2*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

char random_number[4];


void show_line(void)   //äº§çåççº¿
{
	int i;
	for (i = 0; i < 80; i++)
		putchar('=');
}

void creat(void)  //äº§çåä½æ°
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 4; i++)
		random_number[i] = '0' + rand() % 9 + 1;
}

void warning(void)
{
	printf("Please enter 4 positive numbers.eg:1123,1234,9943.\n");
}

int judge(char s[4])     //å¤æ­æ¯å¦æ¯åä½æ°
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
	printf("è¿æ¯ä¸ä¸ªçæ°å­æ¸¸æï¼è§åå¦ä¸ï¼\n""ç³»ç»å°éæºäº§çä¸ä¸ªåä½æ°ï¼è¯·æ¨è¿è¡çæµï¼æä»¬ä¼å°"
		"æ¨è¾å¥çæ°å­è¿è¡å¹éã\n");
	creat(); //äº§çåä½æ°
	printf("Please enter four integer numbers:\n");
	printf("ä¾æ¬¡è¾å¥åä½æ°çæ¯ä¸ä½æ°\n");
	/*ä¸é¢ç¨æ·èªè¡è¾å¥æ°å¯*/
	gets(guessnumber);
	JUDGE=judge(guessnumber);   //å¤æ­æ¯å¦æ¯åä½æ°
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
				printf("ç¬¬%dä½ç­\n", f + 1); 
			}
			else
			{
				printf("ç¬¬%dä½ä¸ç­\n", f + 1);
			}
			f++;
		}
		show_line();
		printf("Please enter four integer numbers:\n");
		printf("ä¾æ¬¡è¾å¥åä½æ°çæ¯ä¸ä½æ°\n");
		gets(guessnumber);
	}
	if (JUDGE==0) warning();
	return 0;
}