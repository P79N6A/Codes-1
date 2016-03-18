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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int MAXN = 1e3 + 11;

ll dp[MAXN][MAXN][2];
struct P {
    ll x, b;
    bool operator < (const P &t)const {
        return x < t.x;
    }
}a[MAXN];

int n;
ll X, v, sum[MAXN];

ll dfs(ll l, ll r, int sta) {
    ll &ret = dp[l][r][sta];

    if (ret >= 0) return ret;
    if (l == r) return ret = abs((X - a[l].x)) * v * sum[n];

    if (sta == 0) {
        ll mul = sum[l] + sum[n] - sum[r];
        ret = min(dfs(l + 1, r, 0) + (a[l + 1].x - a[l].x) * v * mul,
                  dfs(l + 1, r, 1) + (a[r].x - a[l].x) * v * mul);
    }
    else {
        ll mul = sum[l - 1] + sum[n] - sum[r - 1];
        ret = min(dfs(l, r - 1, 1) + (a[r].x - a[r - 1].x) * v * mul,
                  dfs(l, r - 1, 0) + (a[r].x - a[l].x) * v * mul);
    }

    return ret;
}

int main()
{
    while (~scanf("%d%d%lld", &n, &v, &X)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%lld%lld", &a[i].x, &a[i].b);
        }
        sort(a + 1, a + n + 1);

        sum[0] = 0;
        for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i].b;
        memset(dp, -1, sizeof dp);
        printf("%lld\n", min(dfs(1, n, 0), dfs(1, n, 1)));
    }
    return 0;
}
