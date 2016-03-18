#include<stdio.h>

int main(void)
{
	int n,a[1005],cha1[1000],cha2[1000],max,min;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n-1;i++)
		{
			cha1[i]=a[i+1]-a[i];
		}
		for(int i=0;i<n-2;i++)
		{
			cha2[i]=cha1[i]+cha1[i+1];
		}
		min=cha2[0];
		max=cha1[0];
		for(int i=0;i<n-1;i++)
		{
			if(cha1[i]>max)
			{
				max=cha1[i];
			}
			if(i<n-2)
			{
				if(cha2[i]<min)
			 {
				min=cha2[i];
			 }
			}
		}
		if(max>=min)
		{
			printf("%d\n",max);
		}
		else printf("%d\n",min);
	}
	return 0;
}
		