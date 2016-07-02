#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1111;

int a[MAXN];
// 到第i个物品为止，前m个的选择情况为j
int dp[MAXN][2222];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (1 << m); ++j) {
            dp[i][(j << 1) % (1 << m)] = max(dp[i][(j << 1) % (1 << m)], dp[i - 1][j]);
            if (__builtin_popcount(j & ((1 << m - 1) - 1)) < q) { // 需要剔除i - 1选择与不选择的影响。
                dp[i][((j << 1) | 1) % (1 << m)] = max(dp[i][((j << 1) | 1) % (1 << m)], dp[i - 1][j] + a[i]);
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < (1 << m); ++j) {
        ans = max(ans, dp[n][j]);
    }
    cout << ans << '\n';
    return 0;
}
