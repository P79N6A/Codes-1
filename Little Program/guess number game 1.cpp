*This is a guess nuber game.Created by Hugh&Zero&Seven.
It is so hard to find a good way to identify 'guessNumber'
between number and character until we found the function
fflush(stdin).*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROUND 3       //set the round to make the game easier or more difficult
#define NUMBERS 20    //how many numbers exist
#define MIN_NUMBER 20
#pragma warning(disable:4996)

int main(void)
{
	char name[10];
	int guessTaken = 0, guessNumber;
	srand((unsigned)time(NULL));
	int number = rand() %NUMBERS+MIN_NUMBER;

	printf("Guess Number Game [Version 1.0 ]\n"
		"Copyright <c> 2014  632 Technical Team. All Right Reserved.\n\n");

	printf("====================================\n");
	printf("   What's your name?\n");
	printf("====================================\n");
	scanf("%s", name);
	printf("====================================\n");
	printf("   Hello!%s.I'm thinking about a\ninteger number between %d and %d.You"
		"\nonly have %d times to take a guess!\n", name,MIN_NUMBER,MIN_NUMBER+NUMBERS-1,ROUND);
	printf("====================================\n");
	while (guessTaken < ROUND)
	{
		if ((scanf("%d", &guessNumber)) == 1)
			{
			if (guessNumber > number)
					printf("  Your guess is too high.Try again!\n"
					"====================================\n");
			else if (guessNumber < number)
					printf("  Your guess is too low.Try again!\n"
					"====================================\n");
			else
			{
					printf("====================================\n");
					printf("  You win!The number I am thinking is %d.\n", number);
					printf("You just took %d times to guess it.Congratulations!\n", guessTaken + 1);
					break;
			}
		}
		else {
			printf("O_o!!\nEnter error.Please enter a number.\n"
				"====================================\n");
			fflush(stdin);
			continue;
		}
		guessTaken++;
	}
	if (guessTaken == ROUND)
	{
		printf("====================================\n"
			"  You fail..TAT\n  The number I am thinking about is %d.\n", number);
	}

	system("pause");
	return 0;
}