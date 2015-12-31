#include<iostream>
using namespace std;

const int MAXN = 111;

int dp[MAXN][MAXN];

int main()
{
    int c, n;
    cin >> c;
    while (c --)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                cin >> dp[i][j];
            }
        }

        for (int i = n - 1; i >= 1; --i)
        {
            for (int j = 1; j <= i; ++j)
            {
                dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        cout << dp[1][1] << '\n';
    }
    return 0;
}
