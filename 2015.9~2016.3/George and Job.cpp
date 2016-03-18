#include<iostream>
#define ll long long
using namespace std;

const int MAXN = 5e3 + 11;

ll dp[MAXN][MAXN];
ll sum[MAXN];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }

    for (int i = m; i <= n; ++i)
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + sum[i] - sum[i - m]);
    }

    cout << dp[n][k] << '\n';

    return 0;
}
