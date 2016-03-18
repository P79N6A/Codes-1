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
const int MAXN = 1e5 + 111;
const int MOD = 1e9 + 7;

int dp[MAXN];

int main()
{
    int t, k, a, b; cin >> t >> k;
    for (int i = 0; i < k; ++i) dp[i] = 1;
    for (int i = k; i <= 1e5; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
    }
    dp[0] = 0;
    for (int i = 1; i <= 1e5; ++i)
    {
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }
    while (t --)
    {
        cin >> a >> b;
        cout << (dp[b] - dp[a - 1] + MOD) % MOD << '\n';
    }
    return 0;
}
