#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e4 + 111;
int dp[MAXN], a[60];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kk, n, t;
    cin >> kk;
    for (int kase = 1; kase <= kk; ++kase)
    {
        cin >> n >> t;
        t -= 1;
        for (int i = 0; i < n; ++i) cin >> a[i];
        memset(dp, -0x3f, sizeof dp);
        dp[0] = 0;
        int mx = 0, time = 0;
        for (int i = 0; i < n; ++i)
            for (int j = t; j >= a[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - a[i]] + 1);
                mx = max(dp[j], mx);
            }
        for (int i = 0; i <= t; ++i)
        {
            if (dp[i] == mx)
            {
                time = i;
            }
        }
        printf("Case %d: %d %d\n", kase, dp[time] + 1, time + 678);
    }
    return 0;
}
