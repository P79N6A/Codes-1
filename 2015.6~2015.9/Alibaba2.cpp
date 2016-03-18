#include<iostream>
#include<cstdio>
using namespace std;
const int INF = 0x7f7f7f7f, MAXN = 1e4 + 111;
int p[MAXN], t[MAXN], n, dp[MAXN][MAXN][2];

int main()
{
    while(~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &p[i], &t[i]);
        int ans, cur;
        for (int i = n; i >= 1; --i)
            for (int j = i + 1; j <= n; ++j)
            {
                dp[i][j][0] = min(dp[i + 1][j][0] + p[i + 1] - p[i],
                                  dp[i + 1][j][1] + p[j] - p[i]);
                if (dp[i][j][0] >= t[i]) dp[i][j][0] = INF;
                dp[i][j][1] = min(dp[i][j - 1][0] + p[j] - p[i],
                                  dp[i][j - 1][1] + p[j] - p[j - 1]);
                if (dp[i][j][1] >= t[j]) dp[i][j][1] = INF;
            }
        ans = min(dp[1][n][0], dp[1][n][1]);
        if (ans == INF) cout << "No solution\n";
        else cout << ans << '\n';
    }
    return 0;
}
