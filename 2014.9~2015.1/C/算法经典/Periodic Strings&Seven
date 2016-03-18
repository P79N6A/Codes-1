//to judge if it is a periodic string(周期串)
//输出最小周期
//2014.12.17
#include<stdio.h>
#include<string.h>

int main(void)
{
	char s[88];
	while(gets(s))
	{
		int i=0,number[26]={0},flag=1,lenth,l=strlen(s);
		while(s[i++])  //count how many times the word comes up
		{
			//printf("%d\n",i);
			number[s[i-1]-'a']++;
		}
		for(i=0;i<26;i++)  //the loop's lenth
		{
			if(number[i])
			{
				lenth=number[i];
				//printf("lenth:%d\n",lenth);
				break;
			}
		}
		for(i=0;i<26;i++)
		{
			if(number[i]%lenth!=0)
			{
				flag=0;
			}
		}
		if(flag)
		{
			for(int j=0;j<lenth;j++)
			{
				for(i=1;i<l/lenth;i++)
				{
					if(s[j]!=s[j+i*lenth])
					{
						flag=0;
					}
				}
			}
			
		}
		if(flag)
		{
			printf("\"%s\" use %d as a loop.\n",s,lenth);
		}
		else printf("\"%s\" is not a periodic string.\n",s);
	}
	return 0;
}
