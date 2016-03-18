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

const int MAXN = 2010;
const int MOD = 1e9 + 7;

int dp[MAXN][MAXN];

int main() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        dp[1][i] = 1;
    for (int i = 2; i <= k; ++i)
        for (int j = 1; j <= n; ++j)
        {
            for (int l = j; l <= n; l += j)
                dp[i][l] =(dp[i][l] + dp[i - 1][j])%MOD;
        }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += dp[k][i];
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}
