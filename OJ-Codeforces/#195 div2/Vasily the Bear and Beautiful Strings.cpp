/*
  1后面如果有东西的话，那么不管加什么都只会变成0。
  所以找到第一个1，后面就可以用组合数了。
  但是要注意1后面没有东西的情况。
 */
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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 11;
const int MOD = 1e9 + 7;

ll fac[MAXN];

ll quick_pow(ll base, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret = ret * base % MOD;
        base = base * base % MOD;
        p >>= 1LL;
    }
    return ret;
}

ll c(ll n, ll m) {
    if (n < m) return 0;
    ll ret = fac[n] * quick_pow(fac[n - m] * fac[m] % MOD, MOD - 2) % MOD;
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, g;
    fac[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    while (cin >> n >> m >> g) {
        ll ans = 0;
        if (n == 0 || m == 0) {
            if (!m) {
                if (n % 2 && !g) ++ans;
                else if (n % 2 == 0 && g) ++ans;
            }
            else {
                if (m == 1 && g) ++ans;
                else if (m > 1 && !g) ++ans;
            }
            cout << ans << '\n';
            continue;
        }
        for (int i = g; i <= n; i += 2) {
            if (n - i + m - 1 == 0) break;
            ans = (ans + c(n - i + m - 1, m - 1)) % MOD;
        }
        if (m == 1) {
            if (n % 2 && !g) ++ans;
            else if (n % 2 == 0 && g) ++ans;
        }
        cout << ans % MOD << '\n';
    }
    return 0;
}
