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

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
const int MAXN = 5e5 + 111;
ll a[MAXN];
ll r[MAXN];


int main() {
    ll sum = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", a + i);
        sum += a[i];
    }
    if (sum % 3 != 0)
        cout << 0 << '\n';
    else{
        ll judge = sum / 3;
        ll cnt = 0, sum1 = 0, sum2 = 0;
        for (int i = n; i >= 1; --i)
        {
            sum2 += a[i];
            if (sum2 == judge)
                ++cnt;
            r[i] = cnt;
        }
        ll ans = 0;
        for (int i = 1; i <= n - 2; ++i)
        {
            sum1 += a[i];
            if (sum1 == judge)
                ans += r[i + 2];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
