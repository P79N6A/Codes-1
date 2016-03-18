#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1010;
typedef long long ll;

ll a[MAXN], dp[MAXN]; //到第i个点的最大子序列和

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    while (cin >> n && n)
    {
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ll tem = 0;
            for (int j = 0; j < i; ++j)
            {
                if (a[i] > a[j])
                {
                    if (tem < dp[j])
                        tem = dp[j];
                }
            }
            dp[i] += tem + a[i];
            ans = max(ans, dp[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}