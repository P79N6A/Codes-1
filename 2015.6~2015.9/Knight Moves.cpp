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
const int MAXN = 100;
int dir[8][2] = {-1, -2, -2, -1, -2, 1, -1, 2, 1, -2, 2, -1, 2, 1, 1, 2};
bool vis[10][10];
struct N{
	int x, y, ans;
	bool operator == (const N& t)const
	{
		return (x == t.x && y == t.y);
	}
}node;

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	char a[2], b[2];
	while (~scanf("%s %s", a, b))
	{
		memset(vis, 0, sizeof vis);
		N begin;
		begin.y = a[0] - 'a', begin.x = a[1] - '1', begin.ans = 0;
		N end;
		end.y = b[0] - 'a', end.x = b[1] - '1';
		
		queue<N> q;
		q.push(begin);
		int ans = 0;
		while (!q.empty())
		{
			N now = q.front(); q.pop();
			//cout << now.x << ',' << now.y << ',' << now.ans << endl;
			if (now == end)
			{
				ans = now.ans;
				break;
			}
			for (int i = 0; i < 8; ++i)
			{
				int nx = now.x + dir[i][0], ny = now.y + dir[i][1];
				if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !vis[nx][ny])
				{
					vis[nx][ny] = 1;
					N t; t.x = nx, t.y = ny, t.ans = now.ans + 1;
					q.push(t);
				}
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n", a, b, ans);
	}
	return 0;
}

