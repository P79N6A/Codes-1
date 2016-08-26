/*This is a program that can tell how long have you been 
lived in this wonderful world!   
                  Made In China.      Author: Seven */

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>    //To use the function "Sleep()"
#pragma warning(disable:4996)

int sort(int year);   //sort out the loop year

int main(void)
{
	printf("||             来算算你们活了几天吧！               ||\n\n");
	int i,Days;
	int day, month, year, y_day, y_month, y_year, leap = 0, normal_year=0;   //use "leap" to count the total number of leap year

	printf("What's the date today?(day/month/year)\n"); 
	scanf("%d/%d/%d/", &day,&month,&year);
	printf("What's the date of your birthday?(day/month/year)\n");
	scanf("%d/%d/%d/", &y_day, &y_month, &y_year);
	normal_year = year - y_year - 1;        //count the number of normal year between year and y_year
	for (i = y_year + 1; i < year; i++)
	{
		if (sort(i) == 1)
		{
			normal_year--;
			leap++;
		}
	}
	Days = 365 * normal_year + 366 * leap;
	if (sort(y_year) == 1)                 //roughly count how many days you have lived in 'y_year'
	{
		switch(y_month)
		{
		case 12:Days = Days + 31; break;
		case 11:Days = Days + 61; break;
		case 10:Days = Days + 92; break;
		case 9:Days = Days + 122; break;
		case 8:Days = Days + 153; break;
		case 7:Days = Days + 184; break;
		case 6:Days = Days + 214; break;
		case 5:Days = Days + 245; break;
		case 4:Days = Days + 275; break;
		case 3:Days = Days + 306; break;
		case 2:Days = Days + 335; break;
		case 1:Days = Days + 366; break;
		}
	}
	else
	{
		switch (y_month)
		{
		case 12:Days = Days + 31; break;
		case 11:Days = Days + 61; break;
		case 10:Days = Days + 92; break;
		case 9:Days = Days + 122; break;
		case 8:Days = Days + 153; break;
		case 7:Days = Days + 184; break;
		case 6:Days = Days + 214; break;
		case 5:Days = Days + 245; break;
		case 4:Days = Days + 275; break;
		case 3:Days = Days + 306; break;
		case 2:Days = Days + 334; break;
		case 1:Days = Days + 365; break;
		}
	}
	if (sort(year)==1)                    //roughly count how many days you have lived in 'year'
	{
		switch (month)
		{
		case 12:Days = Days + 366; break;
		case 11:Days = Days + 335; break;
		case 10:Days = Days + 305; break;
		case 9:Days = Days + 274; break;
		case 8:Days = Days + 244; break;
		case 7:Days = Days + 213; break;
		case 6:Days = Days + 182; break;
		case 5:Days = Days + 152; break;
		case 4:Days = Days + 121; break;
		case 3:Days = Days + 91; break;
		case 2:Days = Days + 60; break;
		case 1:Days = Days + 31; break;
		}
	}
	else
	{
		switch (month)
		{
		case 12:Days = Days + 365; break;
		case 11:Days = Days + 334; break;
		case 10:Days = Days + 304; break;
		case 9:Days = Days + 273; break;
		case 8:Days = Days + 243; break;
		case 7:Days = Days + 212; break;
		case 6:Days = Days + 181; break;
		case 5:Days = Days + 151; break;
		case 4:Days = Days + 120; break;
		case 3:Days = Days + 90; break;
		case 2:Days = Days + 59; break;
		case 1:Days = Days + 31; break;
		}
	}
	Days = Days - day - y_day;
	printf("\n\nHaw-haw!Guess what!\n");
	Sleep(1000);
	printf("You have lived in this world for %d days!\n",Days);
	system("pause");
	return 0;
}

int sort(int year)     //sort out the loop year
{
	if ((year%4 == 0 && year%100 != 0)||year%400==0)
		return 1;
	else return 0;
}