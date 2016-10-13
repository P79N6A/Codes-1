#include<stdio.h>
int main()
{
    int month,year;
    scanf("%d,%d",&year,&month);
    switch(month){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:printf("day is 31");break;
    case 4:
    case 6:
    case 9:
    case 11:printf("day is 30");break;
    }
    if(year%4==0&&year%100!=0||year%400==0)
        printf("day is 29");
    else
        printf("day is 28");
    return 0;
}
