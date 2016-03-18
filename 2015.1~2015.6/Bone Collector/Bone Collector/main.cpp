#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1010;
int val[MAXN], weight[MAXN], dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    int t, n, total;
    cin >> t;
    while (t --)
    {
        cin >> n >> total;
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i) cin >> val[i];
        for (int i = 0; i < n; ++i) cin >> weight[i];
        for (int i = 0; i < n; ++i)
            for (int j = total; j >= weight[i]; --j)
                dp[j] = max(dp[j], dp[j - weight[i]] + val[i]);
        cout << dp[total] << '\n';
    }
    return 0;
}