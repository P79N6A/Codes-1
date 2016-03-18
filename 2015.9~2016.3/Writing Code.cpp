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
const int MAXN = 511;

int mod;
int dp[2][MAXN][MAXN], a[MAXN];

int main()
{
    int n, m, b;
    while (cin >> n >> m >> b >> mod) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        memset(dp, 0, sizeof dp);
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            int p = i & 1;
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= b; ++k) {
                    dp[p][j][k] = dp[p ^ 1][j][k];
                    if (j && k >= a[i])
                        dp[p][j][k] = (dp[p][j][k] + dp[p][j - 1][k - a[i]]) % mod;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= b; ++i) {
            ans = (ans + dp[n & 1][m][i]) % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}
