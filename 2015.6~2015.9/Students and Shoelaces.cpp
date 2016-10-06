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
vector<int> v[200];
bool vis[200];
int cap[200];

int main()
{
#ifdef LOCAL
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		++cap[a], ++cap[b];
	}
	int ans = 0;
	while( 1 )
	{
		bool flag = 0;
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; ++i)
		{
			if (!vis[i] && cap[i] == 1)
			{
				flag = 1;
				int node = v[i][0];
				vector<int>::iterator it;
				for (it = v[node].begin(); it != v[node].end(); ++it)
				{
					if (*it == i)
						break;
				}
				v[node].erase(it);
				vis[node] = 1;
				--cap[node];
				--cap[i];
			}
		}
		if( !flag )
			break;
		else ++ans;
	}
	cout << ans << '\n';
	return 0;
}

