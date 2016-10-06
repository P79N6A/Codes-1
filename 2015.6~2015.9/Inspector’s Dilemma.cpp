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
const int MAXN = 1e3 + 111;
vector<int> to[MAXN];
bool vis[MAXN];
int v, e, t;

void init()
{
	int a, b;
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= v; ++i)
		to[i].clear();
	for (int i = 0; i < e; ++i)
	{
		cin >> a >> b;
		to[a].push_back(b);
		to[b].push_back(a);
	}
}

int dfs(int n)
{
	vis[n] = 1;
	int cnt = 0;
	cnt += to[n].size() % 2; //双向图，所以这样即可判断是否为奇度数 
	for (int i = 0; i < to[n].size(); ++i)
		if (!vis[to[n][i]])
			cnt += dfs(to[n][i]);
	return cnt;
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int kase = 0;
	while (cin >> v >> e >> t && (v || e || t))
	{
		init();
		int res = 0;
		for (int i = 1; i <= v; ++i)
		{
			if (!vis[i] && !to[i].empty())
				res += max(dfs(i),2);  //如果是回路，自动添加两条边，变成奇数点 
		}
		printf("Case %d: %d\n", ++kase, t * (max((res - 2) / 2 + e, e))); //res / 2将所有奇数点连接。 -2代表空出开头与结尾 
	}
	return 0;
}

