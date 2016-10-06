#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
using namespace std;

const int MAXN = 1e6 + 111;

int main()
{
	char c;
	int d = 0, s = 0;
	while (~scanf("%c",&c))
	{
		if (c == '\"')
		{
			++d;
			if (d % 2)
			{
				printf("``");
			}
			else printf("''");
		}
		else if (c == '\'')
		{
			++s;
			if (s % 2)
			{
				printf("`");
			}
			else printf("'");
		}
		else 
			printf("%c", c);
	}
	return 0;
}

