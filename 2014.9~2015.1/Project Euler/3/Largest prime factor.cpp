#include <stdio.h>
#include <math.h>
#define N 600851475143
int main()
{
	int i,k,flag=0,max;
	for (i=1;i<=N;i++)
		if (N%i==0)
		{
			flag=0;
			for (k=2;k<=sqrt(i);k++)
				if (i%k==0)
					flag=1;
				if (flag!=1)
					max=i;
		}
	printf("%d\n",max);
	return 0;
}
