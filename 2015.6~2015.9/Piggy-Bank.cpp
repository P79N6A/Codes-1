#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
using namespace std;

const int MAXN = 1e4 + 11;
int dp[MAXN];

int v[505], w[505];

int main()
{
	int t; cin >> t;
	while (t --)
	{
		int e, f; cin >> e >> f;
		int need = f - e;
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i] >> w[i];
		}
		memset(dp, 0x3f, sizeof dp);
		dp[0] = 0;
		for (int i = 0; i < n; ++i)
			for (int j = w[i]; j <= need; ++j)
				dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
		if (dp[need] != 0x3f3f3f3f)
			cout << "The minimum amount of money in the piggy-bank is " << dp[need] << ".\n";
		else
			cout << "This is impossible.\n";
	}
	return 0;
}

