#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x7f7f7f7f, MAXN = 1e3 + 111;
int w[MAXN], a[MAXN], b[MAXN], dp[3000];

int main()
{
    int t, m, n; scanf("%d", &t);
    while (t --)
    {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < n; ++i) scanf("%d%d%d", &w[i], &a[i], &b[i]);
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i)
        {
            for (int j = m; j >= w[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + a[i] + b[i]);
            }
            for (int j = w[i]; j <= m; ++j)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + a[i]);
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
