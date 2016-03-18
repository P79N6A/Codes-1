#include"stdafx.h"


void showinformation();
void shownumber(int *a, int lenth);
void Myjudge(char *a, int lenth);  //judge if it is a binary number
void change(int *a, int lenth);   //change to the opposite
/*This is a program that converts the true code into ones-complement code and complemental code.*/


int main(void)
{
	char a[100], judge = 'Y';   //to judge if the user want to continue
	int i, lenth, flag = 0, b[100], ai[100]; //Ones-complement code->ai[]   Complemental code->b[]
	showinformation();
	while (judge == 'Y')
	{
		printf("True code£º");
		gets(a);
		lenth = strlen(a);
		Myjudge(a, lenth);
		for (i = 0; i < lenth; i++) ai[i] = b[i] = a[i] - '0';    //I thought it was troublesome to use strcpy(),so i change the data type.
		if (ai[0] == 0) //if it is positive
		{
			printf("Ones-complement code:");
			shownumber(ai, lenth);
			printf("Complemental code:");
			shownumber(ai, lenth);
			printf("\n");
		}
		else if (ai[0] == 1)    //negative
		{
			change(ai, lenth);
			printf("Ones-complement code:");
			shownumber(ai, lenth);
			printf("Complemental code:");
			for (i = lenth; i > 0; i--)
			{
				if (b[i] == 1)
				{
					flag = i; break;
				}
			}
			change(b, flag);
			shownumber(b, lenth);
			printf("\n");
		}
		printf("Do you want to continue?(Y/N)\n");
		scanf("%c", &judge);
		judge = toupper(judge);  //let user can also use 'y' to continue
		getchar();    //get the '\n'
	}
	printf("Thanks for using.\n");
	return 0;
	system("pause");
}
