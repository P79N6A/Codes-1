#include<stdio.h>

int main(void)
{
	int k,l,m,n,d,a[10005],num;
	while(scanf("%d\n%d\n%d\n%d\n%d",&k,&l,&m,&n,&d)==5)
	{
		num=0;
		//printf("%d%d%d%d%d\n",k,l,m,n,d);
		for(int i=0;i<d;i++)
		{
			a[i]=i+1;
			if(a[i]%k==0||a[i]%l==0||a[i]%m==0||a[i]%n==0)
				a[i]=0;
		}
		for(int i=0;i<d;i++)
		{
			if(!a[i])
				num++;
		}
		printf("%d\n",num);
	}
	return 0;
}
		
	
