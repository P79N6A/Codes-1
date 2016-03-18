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

const int MAXN = 1e4 + 111;
int dp[10][MAXN];

int main()
{
	for (int i = 1; i <= 10000; ++i)
	{
		int now = i;
		while (now)
		{
			dp[now%10][i]++;
			now /= 10;
		}
		for (int j = 0; j <= 9; ++j)
		{
			dp[j][i] += dp[j][i - 1];
		}
	}
	int t; cin >> t;
	while (t --)
	{
		int n;
		cin >> n;
		cout << dp[0][n];
		for (int i = 1; i <= 9; ++i)
			cout << ' ' << dp[i][n];
		cout << '\n';
	}
	return 0;
}

