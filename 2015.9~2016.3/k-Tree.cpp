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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 111;
const int MOD = 1e9 + 7;

ll dp[MAXN], dpp[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k, d;
    while (cin >> n >> k >> d)
    {
        memset(dp, 0, sizeof dp);
        memset(dpp, 0, sizeof dpp);
        dp[0] = dpp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            int up = min(i, k);
            for (int j = 1; j <= up; ++j)
            {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
            dp[i] %= MOD;
        }
        for (int i = 1; i <= n; ++i)
        {
            int up = min(i, d - 1);
            for (int j = 1; j <= up; ++j)
            {
                dpp[i] = (dpp[i] + dpp[i - j]) % MOD;
            }
        }
        //cout << dp[n] << ' ' << dpp[n] << '\n';
        cout << (dp[n] - dpp[n] + MOD) % MOD << '\n';
    }
    return 0;
}
