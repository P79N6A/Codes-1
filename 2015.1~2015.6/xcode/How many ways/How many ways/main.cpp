#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

const int MAXN = 110;
const int MOD = 1e4;

int a[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
    int t; scanf("%d", &t);
    while (t --)
    {
        memset(dp, 0, sizeof dp);
        int n, m; scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);
        dp[1][1] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                int r = min(i + a[i][j], n);
                for (int k = i; k <= r; ++k)
                {
                    int d = min(j + (a[i][j] - k + i), m);
                    for (int l = j; l <= d; ++l)
                    {
                        if (k != i || l != j)
                            dp[k][l] += dp[i][j] % MOD;
                    }
                }
            }
        printf("%d\n", dp[n][m] % MOD);
    }
    return 0;
}
