#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e6 + 111;

int main()
{
	int n;
	int cnt = 0;
	while( cin >> n )
	{
		if(cnt++) putchar('\n');
		printf("2 %d %d\n", n, n);
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if( i < 26)
					printf("%c", 'A' + i);
				else printf("%c", 'a' + i - 26);
			}
			putchar('\n');
		}
		putchar('\n');
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if( j < 26)
					printf("%c", 'A' + j);
				else printf("%c", 'a' + j - 26);
			}
			putchar('\n');
		}
	}
	return 0;
}

