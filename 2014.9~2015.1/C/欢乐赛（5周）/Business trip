#include<stdio.h>

int main(void)
{
	int k,a[12],max,t=0,sum,count,i;
	while(scanf("%d",&k)==1)
	{
		sum=0,count=-1;
		for(i=0;i<12;i++)
			scanf("%d",&a[i]);
		//for (i=0;i<12;i++) printf("%d:%d\n",i,a[i]);
		for(i=0;i<11;i++)
		{
			max=i;
			for(int j=i+1;j<12;j++)
			{
				if(a[max]<a[j])
					max=j;
			}
			t=a[i];
			a[i]=a[max];
			a[max]=t;
		}
		//for (i=0;i<12;i++) printf("%d:%d\n",i,a[i]);
		for(i=0;i<12;i++)
		{
			sum+=a[i];
			if(sum>=k)
			{
				count=i+1;
				goto aha;
			}
		}
aha:	if(k)
			printf("%d\n",count);
		else printf("0\n");
	}
	return 0;
}
		
	
