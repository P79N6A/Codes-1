#include <cstdio>
#include <iostream>

double dp[10100];
int a[10100];
double b[10100];

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) && n + m)
    {
        for (int i = 0; i <= n; ++i)
            dp[i] = 1;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %lf", &a[i], &b[i]);
            b[i] = 1.0 - b[i];
        }
        for (int i = 0; i < m; ++i)
            for (int j = n; j >= a[i]; --j)
                dp[j] = std::min(dp[j], dp[j - a[i]] * b[i]);
        printf("%.1f%%\n", (1.0 - dp[n]) * 100.0);
    }
    return 0;
}