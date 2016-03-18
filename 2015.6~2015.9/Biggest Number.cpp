#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 15;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
bool vis[15][15];
char mp[15][15];
int r, c;
string ans;

void maxstring(string temp)
{
	if(ans.length() < temp.length())
	{
		ans = temp;
	}
	else if(ans.length() == temp.length())
	{
		ans = max(ans, temp);
	}
}

void dfs(int x, int y, string temp)
{
	for( int i = 0; i < 4; ++i )
	{
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if(nx >= 0 && nx < r && ny >= 0 && ny < c && !vis[nx][ny] && isdigit(mp[nx][ny]))
		{
			vis[nx][ny] = 1;
			dfs(nx, ny, temp + mp[nx][ny]);
			vis[nx][ny] = 0;
			maxstring(temp + mp[nx][ny]);
		}
	}
}

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	while( cin >> r >> c && (r || c))
	{
		ans.clear();
		for(int i = 0; i < r; ++i)
			cin >> mp[i];
		for( int i = 0; i < r; ++i)
			for( int j = 0; j < c; ++j)
				if(isdigit(mp[i][j]))
				{
					memset(vis, 0, sizeof vis);
					vis[i][j] = 1;
					dfs(i, j, "");
				}
		cout << ans << '\n';
	}
	return 0;
}

