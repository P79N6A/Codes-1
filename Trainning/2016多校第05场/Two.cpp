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
const int MOD = 1000000007;

int a[MAXN], b[MAXN];
ll dp[MAXN][MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
                if (a[i] == b[j]) dp[i][j] += dp[i - 1][j - 1] + 1;
                dp[i][j] = (dp[i][j] % MOD + MOD) % MOD;
                //printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
            }
        }
        printf("%lld\n", dp[n][m]);
    }
    return 0;
}
