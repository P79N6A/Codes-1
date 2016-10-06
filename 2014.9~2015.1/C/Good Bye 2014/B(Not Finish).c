#include<stdio.h>

int main(void)
{
	int n,p[305];
	char a[305][305];
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		for(int i=1;i<=n;i++)
			gets(a[i]);
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(p[i]>p[j]&&a[i][j]=='1')
				{
					
		
	}
	return 0;
}