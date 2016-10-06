#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e2 + 11;
vector<int> v[MAXN];
vector<int> ans;
int son[MAXN];
int n, m;

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	while (cin >> n >> m && (m || n))
	{
		memset(son, 0, sizeof son);
		ans.clear();
		for (int i = 1; i <= n; ++i)
		{
			v[i].clear();
		}
		int a, b;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			v[a].push_back(b);
			++son[b];
		}
		queue<int> q;
		for (int i = 1; i <= n; ++i) if (!son[i]) q.push(i); //入度为0就push 
		while (!q.empty())
		{
			int t = q.front(); q.pop();
			ans.push_back(t);
			for (int i = 0; i < v[t].size(); ++i)
			{
				if(--son[v[t][i]] == 0)
					q.push(v[t][i]);
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (i)
				cout << ' ';
			cout << ans[i];
		}
		cout << '\n';
	}
	return 0;
}

