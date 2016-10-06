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
string s[8];
int flag;

bool in(int x, int y)
{
	return ( x >= 0 && x < 8 && y >= 0 && y < 8 );
}

void dfs(int x, int y, int dep)
{
	if (flag || dep >= 8 || x <= dep)
	{
		flag = 1;
		return;
	}
	for (int i = -1; i <= 1; ++i)
		for (int j = -1; j <= 1; ++j)
		{
			int nx = x + i, ny = y + j;
			//nx - dep 石块相当于没走路，每次M被上移 
			if (in(nx, ny) && s[nx - dep][ny] != 'S' && (nx <= dep || s[nx - 1 - dep][ny] != 'S'))
			{
				dfs(nx, ny, dep + 1);
			}
		}
	return;
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	for (int i = 0; i < 8; ++i)
	{
		cin >> s[i];
	}
	flag = 0;
	dfs(7, 0, 0);
	if ( flag ) cout << "WIN\n";
	else cout << "LOSE\n";
	return 0;
}
