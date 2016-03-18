#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#define l(u) (u<<1)
#define r(u) (u<<1|1)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
#define bug puts("I am bug")
#define xy(x, y) printf("(%d %d)\n", x, y)
typedef long long ll;
using namespace std;

int main() {
    ll n, m, k;
    while (~scanf("%lld %lld %lld", &n, &m, &k))
    {
        k /= 2;
        ll ans = 0;
        for (int i = 1; i <= m; ++i)
        {
            if (i < k)
            {
                ll mmi = min(n, k - i);
                ans += (m - i + 1) * (n + 1) * mmi - (m - i + 1) * ((1 + mmi) * mmi) / 2;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
