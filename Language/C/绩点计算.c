#include<stdio.h>
#include<stdlib.h>

typedef struct subject{
    float xuefen;
    float grade;
}subject;
int main()
{
    subject kemu[100];
    int i=0;
    float sum=0,gpa=0;
    printf("请输入各个科目的成绩:(q作为结束)\n");
    while(scanf("%f%f",&kemu[i].xuefen,&kemu[i].grade)==2)
    {
        sum+=kemu[i].xuefen;
        if(kemu[i].grade>90)
            kemu[i].grade=90.0;
        if(kemu[i].grade<50)
            kemu[i].grade=50;
        i++;
    }
    for(int j=0;j<i;j++)
    {
        gpa+=kemu[j].xuefen/sum*(kemu[j].grade-50)/10;
    }
    printf("你的GPA为：%.3f\n",gpa);
    system("pause");
    return 0;
}