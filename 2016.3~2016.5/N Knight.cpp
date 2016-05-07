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
const int MAXN = 1e3 + 111;
const int mod = 20090818;

ll c[MAXN][MAXN];
ll f[MAXN];

void init() {
    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }

    f[0] = 1;
    f[1] = 0;
    for (int i = 2; i <= 1000; ++i) {
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
        f[i] %= mod;
    }
}

int main()
{
    int n, m;
    init();
    while (~scanf("%d%d", &n, &m)) {
        ll ans = 0;
        for (int i = 0; i <= m; ++i) {
            ans += c[n][i] * f[n - i];
            ans %= mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
