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
struct N{
	int x, c;
	N(int x, int c):x(x),c(c){}
	N();
};
vector<N> v[MAXN];
vector<int> ans;
int edis[MAXN];
bool vis[MAXN];
int n, m;
int cnt = 0;
void init()
{
	int a, b, c;
	memset(edis, 0, sizeof edis);
	memset(vis, 0, sizeof 0);
	for (int i = 1; i <= n; ++i) v[i].clear();
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (a != b)
		{
			v[a].push_back(N(b,c));
			v[b].push_back(N(a,c));
		}
	}
	queue<int> q;
	q.push(n);
	vis[n] = 1;
	while (!q.empty())
	{
		int now = q.front(); q.pop();
		for (int i = 0; i < v[now].size(); ++i)
		{
			int nx = v[now][i].x;
			if (nx != n && edis[nx] == 0)
			{
				vis[nx] = 1;
				edis[nx] = edis[now] + 1;
				q.push(nx);
			}
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	while (~scanf("%d%d", &n, &m))
	{
		init();
		memset(vis, 0, sizeof vis);
		ans.clear();
		vector<int> bq, nxt; bq.push_back(1);
		for (int j = 1; j <= edis[1]; ++j)
		{
			int mi = 1e9;
			for (int i = 0; i < bq.size(); ++i)
			{
				int now = bq[i];
				for (int k = 0; k < v[now].size(); ++k)
				{
					int nx = v[now][k].x;
					int nc = v[now][k].c;
					if (!vis[nx] && edis[now] == edis[nx] + 1 && mi > nc)
						mi = nc;
				}
			}
			ans.push_back(mi);
			nxt.clear();
			for (int i = 0; i < bq.size(); ++i)
			{
				int now = bq[i];
				for (int k = 0; k < v[now].size(); ++k)
				{
					int nx = v[now][k].x;
					int nc = v[now][k].c;
					if (!vis[nx] && edis[now] == edis[nx] + 1 && nc == mi)
					{
						//cout << now << "->" << nx << endl;
						vis[nx] = 1;
						nxt.push_back(nx);
					}
				}
			}
			bq = nxt;
		}
		printf("%d\n", edis[1]);
		int len = ans.size();
		for (int i = 0; i < len; ++i)
		{
			if (i) printf(" ");
			printf("%d", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}

