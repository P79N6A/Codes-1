#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 211;

int h[MAXN], sum[MAXN];
int dp[40100][2];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, a, b;
    while (cin >> n >> a >> b) {
        if (a < b) swap(a, b);
        memset(dp, 0x3f, sizeof dp);
        h[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> h[i];
            sum[i] = h[i] + sum[i - 1];
        }

        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = a; j >= 0; --j) {
                int t = dp[j][0];
                if (j >= h[i] && j + b >= sum[i])
                    dp[j][0] = min(dp[j - h[i]][0], dp[j - h[i]][1] + min(h[i], h[i - 1]));
                else dp[j][0] = INF;
                if (j + b >= sum[i] && sum[i] >= j + h[i])
                    dp[j][1] = min(dp[j][1], t + min(h[i], h[i - 1]));
                else dp[j][1] = INF;
            }
        }

        int ans = INF;
        for (int i = 1; i <= a; ++i) {
            ans = min(ans, dp[i][0]);
            ans = min(ans, dp[i][1]);
        }
        if (ans == INF) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}
