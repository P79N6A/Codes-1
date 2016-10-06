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
char mp[10][10];
int vis[4][30];
int ans, cnt;
int m, n;

bool ok()
{
	for( int i = 0; i < n; ++i)
	{
		if(!vis[0][i])
		{
			for( int j = 0; j < m; ++j)
				if(mp[i][j] == 'X' && !vis[1][j] && !vis[2][i + j] && !vis[3][i - j + m])
					return 0;
		}
	}
	//cout << "ok" << endl;
	return 1;
}

bool dfs(int x, int dep)
{
	if(dep == ans)
	{
		return ok();
	}
	for( int p = x; p < m *n; ++p)
		{
			int i = p / m, j = p % m;
			vis[0][i]++, vis[1][j]++, vis[2][i + j]++, vis[3][i - j + m]++;
			if(dfs(p, dep + 1)) return 1;
			vis[0][i]--, vis[1][j]--, vis[2][i + j]--, vis[3][i - j + m]--;
		}
	return 0;
}

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int kase = 0;
	while(scanf("%d%d",&n, &m) == 2 && n && m)
	{
		for( int i = 0 ; i < n ; ++i )
			scanf("%s", mp[i]);
		for( ans = 0; ans < 5 ; ++ans)
		{
			memset(vis, 0, sizeof vis);
			if(dfs(0, 0)) break;
		}
		printf("Case %d: %d\n", ++kase, ans);
	}
	return 0;
}
