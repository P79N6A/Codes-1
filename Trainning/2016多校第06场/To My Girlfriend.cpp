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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1111;
const int mod = 1e9+7;

// dp[i][j][s1][s2]:前i个物品必取s1个，必不取s2个，组成j的方案数
int dp[MAXN][MAXN][3][3];
int a[MAXN];

int add(int &x, int y) {
    return x = (x + y) % mod;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, s; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &s);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        memset(dp, 0, sizeof dp);
        dp[0][0][0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= s; ++j) {
                for (int s1 = 0; s1 <= 2; ++s1) {
                    for (int s2 = 0; s2 <= 2; ++s2) {
                        add(dp[i][j][s1][s2], dp[i - 1][j][s1][s2]);
                        if (j >= a[i])
                            add(dp[i][j][s1][s2], dp[i - 1][j - a[i]][s1][s2]);
                        if (s1 > 0 && j >= a[i])
                            add(dp[i][j][s1][s2], dp[i - 1][j - a[i]][s1 - 1][s2]);
                        if (s2 > 0)
                            add(dp[i][j][s1][s2], dp[i - 1][j][s1][s2 - 1]);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= s; ++i) add(ans, dp[n][i][2][2]);
        // 2 * 2 的取与不取物品组合
        printf("%I64d\n", ans * 4LL % mod);
    }
    return 0;
}
