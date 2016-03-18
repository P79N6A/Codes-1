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
const int MAXN = 3e3 + 111;
vector<int> link[MAXN];
int ans[MAXN];
bool vis[MAXN];

bool isCircle(int node, int end, int dep)
{
	vis[node] = 1;
	for( int i = 0; i < link[node].size(); ++i )
	{
		int now = link[node][i];
		if( now == end && dep > 2)
			return 1;
		if( !vis[now] )
		{
			vis[now] = 1;
			if(isCircle(now, end, dep + 1))
				return 1;
			vis[now] = 0;
		}
	}
	return 0;
}

void update(int node)
{
	for( int i = 0; i < link[node].size(); ++i )
	{
		int now = link[node][i];
		if(!vis[now])
		{
			//cout << node << "->" << now << ":" << ans[now] << endl;
			vis[now] = 1;
			ans[now] += ans[node] + 1;
			update(now);
		}
	}
}

int main()
{
	int a, b, n; cin >> n;
	for( int i = 0; i < n; ++i )
	{
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);
	}
	for( int i = 1; i <= n; ++i)
	{
		memset(vis, 0, sizeof vis);
		if( link[i].size() > 1 && isCircle(i, i, 1) )
			break;
	}
	//for (int i = 1; i <= n; ++i) cout << vis[i] << ',' << outcircle[i] << endl;
	for( int i = 1; i <= n; ++i)
	{
		if (vis[i])
		{
			update(i);
		}
	}
	cout << ans[1];
	for (int i = 2; i <= n; ++i)
		cout << ' ' << ans[i];
	cout << '\n';
	return 0;
}

