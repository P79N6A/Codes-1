#include<iostream>
#include<cctype>
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
const int MAXN = 111;
int mp[MAXN][MAXN], dp[MAXN][MAXN], n, k;

int dfs(int x, int y)
{
	if (dp[x][y] > 0) return dp[x][y];
	int ret = 0;
	int s = max(0, x - k), e = min(x + k, n - 1);
	for (int i = s; i <= e; ++i)
	{
		if (mp[x][y] < mp[i][y])
		{
			ret = max(ret, dfs(i, y));
		}
	}
	s = max(0, y - k), e = min(n - 1, y + k);
	for (int i = s; i <= e; ++i)
	{
		if (mp[x][y] < mp[x][i])
		{
			ret = max(ret, dfs(x, i));
		}
	}
	return dp[x][y] = ret + mp[x][y];
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	while (scanf("%d%d", &n, &k))
	{
		if (n == -1 && k == -1) break;
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &mp[i][j]);
		printf("%d\n", dfs(0,0));
	}
	return 0;
}

