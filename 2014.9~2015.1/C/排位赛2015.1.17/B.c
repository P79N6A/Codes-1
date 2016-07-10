#include<stdio.h>
#include<string.h>
//#include<stdlib.h>
#pragma warning(disable:4996)

void showline()
{
	for (int i = 0; i < 80; i++)
		printf("-");
	putchar('\n');
}

char words[1000][90];
char passage[90000];

int main()
{
	//system("mode 120");
	char c;
	int i = 0,flag=0,wordcount=0,lword,lineflag=0;
	int linelenth = 0;
	while ((c=getchar()) != EOF)
	{
		passage[i] = c;
		i++;
	}
	for (int j = 0; j < i; j++)
	{
		lword = 0;
		for (; passage[j] != ' '&&passage[j] != '\n'&&passage[j] != '\t';j++)
		{
			flag = 1;
			words[wordcount][lword++] = passage[j];
		}
		if (flag)
			wordcount++;
		flag = 0;
	}
	for (int j = 0; j < wordcount; j++)
	{
		if (strcmp("<br>", words[j]) == 0)
		{
			lineflag = 1;
			putchar('\n');
			linelenth = 0;
		}
		else if (strcmp("<hr>", words[j]) == 0)
		{
			if (lineflag == 0)
			{
				putchar('\n');
			}
			showline();
			linelenth = 0;
			lineflag=1;
		}
		else
		{
			linelenth += strlen(words[j]);
			if (linelenth < 81)
			{
				if (linelenth < 80)
				{
					printf("%s ", words[j]);
					linelenth++;
					lineflag = 0;
				}
				else printf("%s", words[j]);
			}
			else 
			{
				putchar('\n');
				linelenth = 0;
				lineflag = 1;
				j--;
			}
		}
	}
	putchar('\n');
	return 0;
}