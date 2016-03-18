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
const int MAXN = 1e5 + 111;
int p[MAXN], q[MAXN];

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int t; scanf("%d", &t);
	for(int kase = 1; kase <= t; ++kase)
	{
		int n; scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", p + i);
		for(int i = 0; i < n; ++i)
			scanf("%d", q + i);
		bool can = 0;
		for(int i = 0; i < n; ++i)
		{
			bool flag = 1;
			int sum = 0;
			for(int j = i; j < i + n; ++j)
			{
				int now = j % n;
				sum += p[now] - q[now];
				if( sum < 0)
				{
					flag = 0;
					sum = 0;
					i = max(i, j);
					break;
				}
			}
			if(flag)
			{
				can = 1;
				printf("Case %d: Possible from station %d\n", kase, i + 1);
				break;
			}
		}
		if(!can)
			printf("Case %d: Not possible\n", kase);
	} 
	return 0;
}

