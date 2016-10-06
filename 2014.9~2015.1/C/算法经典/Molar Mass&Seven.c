//计算化学式的分子量
//show the chemical formula's molecular weight
//只支持 C.H.O.N   Only support C.H.O.N
#include <stdio.h>

double judge(const char c)
{
	switch(c){
				case 'C':return (12.01);
				case 'H':return (1.008);
				case 'O':return (16.00);
				case 'N':return (14.01);
				default: return 0;
				}
}

int main( void )
{
	char s[100];
	while(gets(s))
	{
		int i=0;
		double sum=0.0,decade=0.0,hundreds=0.0,gewei=0.0;
		while(s[i])
		{
			switch(s[i]){
				case 'C':sum+=12.01;i++;break;
				case 'H':sum+=1.008;i++;break;
				case 'O':sum+=16.00;i++;break;
				case 'N':sum+=14.01;i++;break;
				default:{
					//printf("%c\n",s[i+2]);
					if(s[i+1]>='0'&&s[i+1]<='9')
					{
						if(s[i+2]>='0'&&s[i+2]<='9')
				   	{
						   //printf("进入判断\n");
						   hundreds=s[i]-'0';
			    		   decade=s[i+1]-'0';
					   	gewei=s[i+2]-'0';
				   		sum+=(hundreds*100+decade*10+gewei-1)*judge(s[i-1]);
				   		i+=3;
				    		break;
					   }
						decade=s[i]-'0';
						gewei=s[i+1]-'0';
						sum+=(decade*10+gewei-1)*judge(s[i-1]);
						i+=2;
						break;
					}
					gewei=s[i]-'0';
					sum+=(gewei-1)*judge(s[i-1]);
					i++;
					break;
				}
			}
			//printf("%d:%.3lf\n",i,sum);
		}
		printf("%.3lfg/mol\n",sum);
	}
	return 0;	
}
