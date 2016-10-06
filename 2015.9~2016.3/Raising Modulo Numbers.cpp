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

int mod;

ll quick_pow(ll x, ll p) {
    ll base = x;
    ll ret = 1;
    while (p) {
        if (p & 1) ret = (ret * base) % mod;
        p >>= 1;
        base = (base * base) % mod;
    }
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase, n; scanf("%d", &kase);
    while (kase --) {
        scanf("%d%d", &mod, &n);
        int ans = 0, x, p;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x, &p);
            ans = (ans + quick_pow(x, p)) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}
