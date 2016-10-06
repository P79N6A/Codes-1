#include <cstdio>
#include <cstring>

int v[100], amount[100], dp[200000];

int main()
{
    int n;
    while (scanf("%d", &n) && n >= 0)
    {
        int sum = 0;
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d",&v[i], &amount[i]);
            sum += v[i] * amount[i];
        }
        int half = sum / 2;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < amount[i]; ++j)
                for (int k = half; k >= v[i]; --k)
                    if (dp[k] < dp[k - v[i]] + v[i])
                        dp[k] = dp[k - v[i]] + v[i];
        printf("%d %d\n", sum - dp[half], dp[half]);
    }
    return 0;
}