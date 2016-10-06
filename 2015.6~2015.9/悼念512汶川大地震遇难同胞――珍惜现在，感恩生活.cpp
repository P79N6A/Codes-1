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

const int MAXN = 111;

int v[MAXN], w[MAXN], num[MAXN];
int dp[MAXN];

int main()
{
	int c;
	scanf("%d", &c);
	while (c --)
	{
		memset(dp, 0, sizeof dp);
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i < m; ++i)
			scanf("%d%d%d", v + i, w + i, num + i);
		for (int i = 0; i < m; ++i)
		{
			if (num[i] * v[i] >= n)
			{
				for (int j = v[i]; j <= n; ++j)
					dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
			}
			else
			{
				int k = 1;
				while (k < num[i])
				{
					for (int j = n; j >= k * v[i]; --j)
						dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
					num[i] -= k;
					k <<= 1; 
				}
				for (int j = n; j >= num[i] * v[i]; --j)
						dp[j] = max(dp[j], dp[j - num[i] * v[i]] + num[i] * w[i]);
			}
		}
		int mx = 0;
		for (int i = 0; i <= n; ++i)
			mx = max(mx, dp[i]);
		printf("%d\n", mx);
	}
	return 0;
}

