#include<stdio.h>

int main(void)
{
	int n,t,a[30005];
	while(scanf("%d%d",&n,&t)==2)
	{
		int sum=0,flag=0;
		for(int i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int k=1;k<t;k++)
		{
			sum=k+a[k];
			if(sum==t)
			{
				flag=1;
				break;
			}
			k=sum-1;
			sum=0;
		}
		if(flag)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}