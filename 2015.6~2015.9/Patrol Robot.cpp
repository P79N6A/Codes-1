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
const int MAXN = 25;
int mp[MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];
struct N{
	int x, y, dis, conti;
	N(int x, int y, int dis, int conti):x(x),y(y),dis(dis),conti(conti){}
};
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int t; cin >> t;
	while (t --)
	{
		int m, n, k;
		cin >> m >> n >> k;
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				cin >> mp[i][j];
		queue<N> q;
		q.push(N(0,0,0,0));
		vis[0][0][1] = 1;
		while (!q.empty())
		{
			N now = q.front();
			//cout << now.x << ',' << now.y << endl;
			if (now.x == m - 1 && now.y == n - 1)
			{
				break;
			}
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nx = now.x + dir[i][0], ny = now.y + dir[i][1], nc = now.conti + 1;
				if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny][nc])
				{
					if (mp[nx][ny] == 0)
					{
						q.push(N(nx, ny, now.dis + 1, 0));
						vis[nx][ny][nc] = 1;
					}
					else if (nc <= k)
					{
						q.push(N(nx, ny, now.dis + 1, nc));
						vis[nx][ny][nc] = 1;
					}
				}
			}
		}
		if (!q.empty())
		{
			cout << q.front().dis << '\n';
		}
		else cout << -1 << '\n';
	}
	return 0;
}

