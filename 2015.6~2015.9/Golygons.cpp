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
int step, n, cnt;
vector<string> all;
int dir[2][4] = {{0, 0, 1, -1}, { 1, -1, 0, 0}};
bool have[300][300];
bool vis[300][300];
int sum[25];

void init()
{
	cnt = 0;
	int a, b;
	memset(have, 0, sizeof have);
	memset(vis, 0, sizeof vis);
	for( int i = 0 ; i < n; ++i ) { cin >> a >> b; a += 150, b += 150; have[a][b] = 1;}
	all.clear();
}

bool can(int x, int y, int nx, int ny)
{
	if (x > nx) swap(x, nx);
	if (y > ny) swap(y, ny);
	if (x == nx) 
	{
		//cout << "beginx:" << x << endl;
		for(int i = y; i <= ny; ++i) 
		{
			//cout << x << ',' << i << "   ";
			if(have[x + 150][i + 150])
			{
			 	//cout << endl; 
				return 0;
			}
		}
		//cout << endl;
	}
	if (y == ny)
	{
		//cout << "beginy:" << y << endl;
		for(int i = x; i <= nx; ++i) 
		{
			//cout << i << ',' << y <<"   ";
			if(have[i + 150][y + 150]) 
			{
			//	cout << endl;
				return 0;
			}
		}
		//cout << endl;
	}
	return 1;
}

void dfs(int x, int y, int dep, bool ver, string ans)
{
	if(dep == step + 1)
	{
		if( x == 0 && y == 0 )
		{
			//cout << "*************************" << endl;
			all.push_back(ans);
			return;
		}
		return;
	}
	if (vis[150][150])
		return;
	if (abs(x - 0) + abs(y - 0) > sum[step] - sum[dep - 1]) return;
	for( int i = 0; i < 2; ++i )
	{
		int nx = x + dep * dir[ver][i], ny = y + dep * dir[ver][i + 2];
		if (!vis[nx + 150][ny + 150] && can(x, y, nx, ny))
		{
			//cout << dep << " ====== " << nx << ',' << ny << '\n';
			vis[nx + 150][ny + 150] = 1;
			if(ver)
			{
				if (dir[ver][i] == -1)
					dfs(nx, ny, dep + 1, !ver, ans + "w");
				else dfs(nx, ny, dep + 1, !ver, ans + "e");
			}
			else
			{
				if (dir[ver][i + 2] == -1)
					dfs(nx, ny, dep + 1, !ver, ans + "s");
				else dfs(nx, ny, dep + 1, !ver, ans + "n");
			}
			vis[nx + 150][ny + 150] = 0;
		}
	}
	
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	//freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
#endif
	int t;
	for (int i = 1; i <= 20; ++i)
	{
		sum[i] = sum[i - 1] + i;
	}
	while(cin >> t)
	{
		while(t --)
		{
			cin >> step >> n;
			init();
			dfs(0, 0, 1, 1, ""); //´¹Ö± 
			dfs(0, 0, 1, 0, ""); //Ë®Æ½ 
			sort(all.begin(),all.end());
			for(int i = 0; i < all.size(); ++i)
			{
				cout << all[i] << '\n';
			}
			cout << "Found " << all.size() << " golygon(s).\n\n";
		}
	}
	return 0;
}

