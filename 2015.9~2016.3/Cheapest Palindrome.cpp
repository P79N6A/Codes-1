#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;

const int MAXN = 2e3 + 111;

ll dp[MAXN][MAXN];
char sh[MAXN];
int s[MAXN];
ll ad[30], del[30];

int main()
{
    int n, m; scanf("%d%d%s", &n, &m, sh);
    for (int i = 0; i < m; ++i) s[i] = sh[i] - 'a';
    char c[2];
    int a, b;
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d", c, &a, &b);
        ad[c[0] - 'a'] = a;
        del[c[0] - 'a'] = b;
    }

    for (int i = m - 1; i >= 0; --i) {
        for (int j = i + 1; j < m; ++j) {
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
            else {
                dp[i][j] = min(dp[i + 1][j] + min(ad[s[i]], del[s[i]]),
                               dp[i][j - 1] + min(ad[s[j]], del[s[j]]));
            }
        }
    }
    printf("%lld\n", dp[0][m - 1]);
    return 0;
}
