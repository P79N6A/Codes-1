#include<stdio.h>

int main(void)
{
	int n,m;
	char grade[105][105];
	while(scanf("%d%d",&n,&m)==2)
	{
		getchar();
		int max,count=0,best[105]={0};
		for(int i=0;i<n;i++)
		{
			gets(grade[i]);
		}
		for(int i=0;i<m;i++)
		{
			max=grade[0][i];
			for(int j=1;j<n;j++)
			{
				if(max<grade[j][i])
				{
					max=grade[j][i];
				}
			}
			for(int j=0;j<n;j++)
			{
				if(max==grade[j][i])
				{
					best[j]=1;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(best[i])
			 count++;
		}
		printf("%d\n",count);	
	}
	return 0;
}
		
	
