#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1010;
const int INF = 0x3f3f3f3f;

int a[30][MAXN], dp[30][MAXN];

int main() {
    int t; scanf("%d", &t);
    while (t --)
    {
        int m, n;
        scanf("%d %d", &m, &n);
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &a[i][j]);
        memset(dp, -INF, sizeof dp);
        dp[1][0] = dp[0][1] = 0;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j]);
                for (int k = 1; k < j; ++k)
                {
                    if (j % k == 0)
                        dp[i][j] = max(dp[i][k] + a[i][j], dp[i][j]);
                }
            }
        }
        printf("%d\n", dp[m][n]);
    }
    return 0;
}