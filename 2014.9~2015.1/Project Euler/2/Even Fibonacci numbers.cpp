#include <stdio.h>
#define N 4000000
int main()
{
	int a=1,b=2,sum=0;
	while (a<=N||b<=N)
	{
		if (a%2==0)
			sum+=a;
		if ((b<=N)&&(b%2==0))
			sum+=b;
		a=a+b;b=a+b;
	}
	printf("%d\n",sum);
	return 0;
}