#include<cstdio>
#include<iostream>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;
const int MOD = 1e6;

int dp[1011][MAXN];
int num[1011];

int main()
{
    int t, a, s, b, x;
    scanf("%d%d%d%d", &t, &a, &s, &b);
    for (int i = 0; i < a; ++i) {
        scanf("%d", &x);
        ++num[x];
    }

    for (int i = 0; i <= t; ++i) dp[i][0] = 1;

    for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= a; ++j) {
            if (j - 1 - num[i] >= 0) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1 - num[i]] + MOD) % MOD;
            }
            else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    //for (int i = 1; i <= t; ++i, cout << '\n') for (int k = 0; k <= a; ++k) cout << dp[i][k] << ' ';

    int ans = 0;
    for (int i = s; i <= b; ++i) {
        ans = (ans + dp[t][i]) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}
