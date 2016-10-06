#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e6 + 111;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll t, n, l, r; cin >> t;
    ll dp[22][22][22];
    dp[1][1][1] = 1;
    for (int i = 2; i <= 20; ++i)
        for (int j = 1; j <= i; ++j)
            for (int k = 1; k <= i; ++k)
            {
                if (i - 1 >= j || i - 1 >= k)
                    dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2);
            }
    while (t --)
    {
        cin >> n >> l >> r;
        cout << dp[n][l][r] << '\n';
    }
    return 0;
}
