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
const int MAXN = 2e3 + 111;

struct P {
    ll l, r;
    ll x, y;
    bool operator < (const P &t)const {
        return l > t.l;
    }
}f[MAXN];

ll x[2], y[2];

ll getdis(int a, int b) {
    ll xx = f[a].x - x[b];
    ll yy = f[a].y - y[b];
    return xx * xx + yy * yy;
}

bool cmp(P a, P b) {
    return a.r > b.r;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int n;
    cin >> n >> x[0] >> y[0] >> x[1] >> y[1];
    for (int i = 0; i < n; ++i) {
        cin >> f[i].x >> f[i].y;
        f[i].l = getdis(i, 0);
        f[i].r = getdis(i, 1);
    }

    sort(f, f + n);

    ll ans = 1e16;
    for (int i = 0; i < n; ++i) {
        ll mx = 0;
        for (int j = 0; j < i; ++j) {
            mx = max(mx, f[j].r);
        }
        ans = min(ans, mx + f[i].l);
    }

    sort(f, f + n, cmp);
    for (int i = 0; i < n; ++i) {
        ll mx = 0;
        for (int j = 0; j < i; ++j) {
            mx = max(mx, f[j].l);
        }
        ans = min(ans, mx + f[i].r);
    }

    cout << ans << '\n';
    return 0;
}
