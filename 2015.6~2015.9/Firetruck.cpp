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
bool vis[25];
vector<int> link[25];
vector<int> temp;
vector<int> path[100];
int ans, n, mxdep;

void init()
{
	int a, b;
	mxdep = 0;
	ans = 0;
	for( int i = 0; i <= 25; ++i) link[i].clear();
	for( int i = 0; i < 100; ++i) path[i].clear();
	memset( vis , 0 , sizeof vis );
	temp.clear();
	while( scanf("%d%d", &a, &b) && (a || b) )
	{
		if(!vis[a])
		{
			++mxdep; vis[a] = 1;
		}
		if(!vis[b])
		{
			++mxdep; vis[b] = 1;
		}
		link[a].push_back(b);
		link[b].push_back(a);
	}
	memset( vis , 0 , sizeof vis );
}

void dfs(int x, int dep)
{
	if (link[n].size() == 0) return ;
	if (x == n)
	{
		path[ans] = temp;
		++ans;
		return;
	}
	if ( dep >= mxdep ) return;
	for( int i = 0; i < link[x].size(); ++i)
	{
		int cur = link[x][i];
		if(!vis[cur])
		{
			vis[cur] = 1;
			temp.push_back(cur);
			dfs(cur, dep + 1);
			temp.pop_back();
			vis[cur] = 0;
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int kase = 0;
	while(~scanf("%d",&n))
	{
		init();
		temp.push_back(1);
		vis[1] = 1;
		dfs(1, 0);
		sort(path, path + ans);
		printf("CASE %d:\n", ++kase);
		for(int i = 0; i < ans; ++i)
		{
			printf("%d", path[i][0]);
			for( int j = 1; j < path[i].size(); ++j)
				printf(" %d", path[i][j]);
			putchar('\n');
		}
		printf("There are %d routes from the firestation to streetcorner %d.\n", ans, n);
	}
	return 0;
}

