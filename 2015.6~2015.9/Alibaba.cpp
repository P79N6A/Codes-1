#include<iostream>
#include<cctype>
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
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e4 + 11;
int dp[MAXN][MAXN][2], p[MAXN], t[MAXN];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; ++i)
			cin >> p[i] >> t[i];
		int cur, ans;
		for (int i = n; i >= 1; --i)
			for (int j = i + 1; j <= n; ++j)
			{
				dp[i][j][0] = dp[i][j][1] = INF;
				cur = min(dp[i+1][j][0] + p[i+1] - p[i],
						  dp[i+1][j][1] + p[j] - p[i]);
				if (cur < t[i]) dp[i][j][0] = min(dp[i][j][0],cur);
				cur = min(dp[i][j-1][0] + p[j] - p[i],
						  dp[i][j-1][1] + p[j] - p[j -1]);
				if (cur < t[j]) dp[i][j][1] = min(dp[i][j][1],cur);
			}
		ans = min(dp[1][n][0],dp[1][n][1]);
		if (ans == INF) cout << "No solution\n";
		else cout << ans << '\n';
	}
	return 0;
}

