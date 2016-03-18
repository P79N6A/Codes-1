#include<iostream>
#include<cstring>
using namespace std;

int dp[4011];

int main()
{
    int n, a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = a[i]; j <= n; ++j)
            dp[j] = max(dp[j], dp[j - a[i]] + 1);
    cout << dp[n] << '\n';
    return 0;
}