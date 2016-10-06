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
bool vis[20];
int n;
vector<int> ans;

bool isprime(int n)
{
	if (n == 1) return 1;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return 0;
	return 1;
}

void solve(int node, int dep)
{
	if (dep == n)
	{
		if (isprime(node + 1))
		{
			for (int i = 0; i < ans.size(); ++i)
			{
				if (i) cout << ' ';
				cout << ans[i];
			}
			cout << '\n';
			return;
		}
		else return;
	}
	for (int i = 2; i <= n; ++i)
	{
		if (!vis[i] && isprime(node + i))
		{
			ans.push_back(i);
			vis[i] = 1;
			solve(i, dep + 1);
			vis[i] = 0;
			ans.pop_back(); 
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int kase = 0;
	while (cin >> n)
	{
		if (kase)
			cout << '\n';
		memset(vis, 0, sizeof vis);
		ans.clear();
		cout << "Case " << ++kase << ":\n";
		ans.push_back(1);
		solve(1, 1);
	}
	return 0;
}

