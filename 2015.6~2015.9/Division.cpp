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
const int MAXN = 10;
bool vis[MAXN];
bool lef[MAXN];
bool flag = 0;
int n;

void dfs(int dep, int sum)
{
	if (dep == 5)
	{
		//cout << sum << endl;
		int now = sum * n;
		if (now >= 100000)
			return;
		memset(lef, 0, sizeof lef);
		for (int i = 0; i <= 9; ++i)
			if (vis[i])
				lef[i] = 1;
		int tem = now;
		//cout << sum << ',' << now << endl;
		for (int i = 0; i < 5; ++i)
		{
			int t = tem % 10;
			if (!lef[t]) lef[t] = 1;
			else return;
			tem /= 10;
		}
		flag = 1;
		printf("%05d / %05d = %d\n", now, sum, n);
		return ;
	}
	for (int i = 0; i <= 9; ++i)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			dfs(dep + 1, sum + i * pow(10, 4 - dep));
			vis[i] = 0;
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int cnt = 0;
	while (cin >> n)
	{
		if (n == 0)
			break;
		if (cnt) cout << '\n';
		cnt = 1;
		memset(vis, 0, sizeof vis);
		flag = 0;
		for (int i = 0; i <= 9; ++i)
		{
			if (!vis[i])
			{
				vis[i] = 1;
				dfs(1, i * pow(10, 4));
				vis[i] = 0;
			}
		}
		if (!flag)
			cout << "There are no solutions for " << n << ".\n";
	}
	return 0;
}

