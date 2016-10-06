#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1e5 + 11;
const int INF = 0x3f3f3f3f;
int dp[MAXN];
int amount[110];
int val[110];

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) && (n != 0 || m != 0))
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", val + i);
        for (int i = 0; i < n; ++i)
            scanf("%d", amount + i);
        memset(dp, -0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < n; ++i)
        {
            if (val[i] * amount[i] >= m)
            {
                for (int j = val[i]; j <= m; ++j)
                    dp[j] = max(dp[j], dp[j - val[i]] + val[i]);
            }
            else {
                int k = 1;
                while (k < amount[i])
                {
                    for (int j = m; j >= k * val[i]; --j)
                        dp[j] = max(dp[j], dp[j - k * val[i]] + k * val[i]);
                    amount[i] -= k;
                    k *= 2;
                }
                for (int j = m; j >= amount[i] * val[i]; --j)
                    dp[j] = max(dp[j], dp[j - amount[i] * val[i]] + amount[i] * val[i]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i)
            if (dp[i] > 0)
                ++ans;
        printf("%d\n", ans);
    }
}