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
const int MAXN = 1e3;
int num[MAXN];
bool vis[MAXN];
int ans, n;

bool cmp(int a, int b)
{
	return a > b;
}

bool dfs(int now, int lef, int lefsum)
{
	if( lefsum == ans ) return 1;
	if( lef == 0 )
	{
		lefsum -= ans;
		if( lefsum == 0 ) return 1;
		int i = 0;
		while(vis[i]) ++i;
		vis[i] = 1;
		if( dfs(i + 1, ans - num[i], lefsum) ) return 1;
		vis[i] = 0;
	}
	else
	{
		for( int i = now; i < n; ++i)
		{
			if(!vis[i] && lef >= num[i])
			{
				vis[i] = 1;
				if( dfs( i + 1, lef - num[i], lefsum) ) return 1;
				vis[i] = 0; 
				if( num[i] == lef )
					break;
				while(num[i] == num[i + 1] && i + 1 < n) ++i;
			}
		}
	}
	return 0;
}

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	while( scanf("%d", &n) && n )
	{
		int sum = 0, mx = 0;
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < n; ++i) 
		{
			scanf("%d", num + i); sum += num[i];
		}
		sort(num, num + n, cmp);
		bool flag = 1;
		for( ans = num[0]; ans + ans <= sum; ++ans )
		{
			if( sum % ans == 0 && dfs(0, ans, sum) )
			{
				flag = 0;
				printf("%d\n", ans);
				break;
			}
		}
		if(flag)
			printf("%d\n", sum);
	}
	return 0;
}

