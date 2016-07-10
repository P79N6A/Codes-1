#include<stdio.h>

int main(void)
{
	int n;
	int f(int a,int b);
	while(scanf("%d",&n)==1)
	{
		printf("%d!=%d\n",n,f(n,1));
	}
	return 0;
}

int f(int a,int b)
{
	if(a==0)
		return 1;
	else if(a==1)
		return b;    //to put the result in the end
	else if(a>1)
	{
		return f(a-1,b*a);
	}
	else return 0;
}
