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
const int MAXN = 1e6 + 111;
const int MOD = 1000003;

ll dp[MOD + 1];

int main()
{
    int t; cin >> t;
    ll n;
    /*1 2 3 4
    2 4 6 8
    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 8;
    dp[i] = 2 * i * dp[i - 1];
    dp[3] = 2 * 3 * 2 * 2 * 2 * 1 = 2 ^ 3 + 3!
    dp[i] = 2^i X i! */
    dp[1] = 2;
    for (int i = 2; i <= MOD; ++i) {
        dp[i] = 2 * i * dp[i - 1] % MOD;
    }
    while (t --) {
        cin >> n;
        if (n >= MOD) cout << 0 << '\n';
        else cout << dp[n] << endl;
    }
    return 0;
}
