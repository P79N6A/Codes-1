#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e6 + 111;
char mp[110][110];
int m, n;

void dfs(int x, int y)
{
	for (int i = -1; i <= 1; ++i)
		for (int j = -1; j <= 1; ++j)
		{
			if (i != 0 || j != 0)
			{
				//cout << x << ',' << y << endl;
				int nx = x + i, ny = y + j;
				//cout << nx << ' ' << ny << endl;
				if (nx >= 0 && nx < m && ny >= 0 && ny < n && mp[nx][ny] == '@')
				{
					mp[nx][ny] = '*';
					dfs(nx, ny);
				}
			}
		}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	while(scanf("%d%d", &m, &n) && m)
	{
		getchar();
		int ans = 0;
		for (int i = 0; i < m; ++i)
			gets(mp[i]);
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (mp[i][j] == '@')
				{
					//cout << i << ' ' << j << endl;
					mp[i][j] = '*';
					dfs(i, j);
					++ans;
				}
		cout << ans << '\n';
	} 
	return 0;
}

