#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 50;
const int INF = 0x3f3f3f3f;
typedef long long ll;

int n;
ll W, w[MAXN];
pair<ll, ll> p[1 << 20];

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; ++i) cin >> w[i];
    int n2 = n >> 1;
    for (int i = 0; i < 1 << n2; ++i)
    {
        ll sw = 0, sv = 0;
        for (int j = 0; j < n2; ++j)
        {
            if (i >> j & 1)
            {
                sw += w[j];
                sv += w[j];
            }
        }
        p[i] = make_pair(sw, sv);
    }
    sort(p, p + (1 << n2));
    int m = 1;
    for(int i = 1; i < 1 << n2; ++i) {
        if(p[m - 1].second < p[i].second) {
            p[m++] = p[i];
        }
    }
    ll res = 0;
    for (int i = 0; i < 1 << (n - n2); ++i)
    {
        ll sw = 0, sv = 0;
        for (int j = 0; j < n - n2; ++j)
        {
            if (i >> j & 1)
            {
                sw += w[n2 + j];
                sv += w[n2 + j];
            }
        }
        if (sw <= W)
        {
            ll tv = (lower_bound(p, p + m, make_pair(W - sw, (ll)INF)) - 1) ->second;
            res = max(res, sv + tv);
        }
    }
    cout << res << '\n';
    return 0;
}