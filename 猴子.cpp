#include<iostream>
using namespace std;

int dp[60];

int main()
{
    int n;
    dp[1] = dp[2] = 1, dp[3] = 2;
    for (int i = 4; i <= 55; ++i)
    {
        dp[i] = dp[i - 3] + dp[i - 1];
    }

    while (cin >> n)
    {
        cout << dp[n] << '\n';
    }
    return 0;
}
