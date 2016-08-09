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
const int MAXN = 1e6 + 111;
const int mod = 1000000007;

void pt(int n) {
    int fac[20];
    fac[0] = 1;
    for (int i = 1; i < 20; ++i) fac[i] = i * fac[i - 1];
    int m = 3;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            for (int k = j; k <= n; ++k) {
                ans += fac[k] / (fac[i] * fac[j - i] * fac[k - j]);
            }
        }
    }
    prln(ans)
}

ll quickPow(ll base, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret = ret * base % mod;
        base = base * base % mod;
        p /= 2;
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll n, m;
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%lld%lld", &n, &m);
        ll ans = (1 - quickPow(m, n + 1)) * quickPow(1 - m, mod - 2) % mod;
        printf("%lld\n", (ans + mod) % mod);
    }
    return 0;
}
