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

const int MAXN = 2e3 + 111;

int w[MAXN];
int dp[MAXN][MAXN];

int main() {
    int n, k;
    while (~scanf("%d %d",&n, &k))
    {
        memset(dp, 0x3f, sizeof dp);
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 0;
        for (int i = 1; i <= n; ++i)
            scanf("%d", w + i);
        sort(w + 1, w + 1 + n);
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j * 2 <= i; ++j)
                dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + (w[i] - w[i - 1]) * (w[i] - w[i - 1]));
        }
        printf("%d\n", dp[n][k]);
    }
    return 0;
}
