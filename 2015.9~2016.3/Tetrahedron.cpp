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
const int MOD = 1e9 + 7;

ll dp[10000009];

int main()
{
    int n;
    dp[0] = 1;
    dp[1] = 0;
    for (int i = 2; i <= 1e7; ++i) {
        dp[i] = (2 * dp[i - 1] + 3 * dp[i - 2]) % MOD;
    }
    while (cin >> n) {
        cout << dp[n] << '\n';
    }
    return 0;
}
