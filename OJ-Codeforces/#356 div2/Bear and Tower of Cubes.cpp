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
#define pll pair<ll, ll>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

ll pp(ll x) {
    return x * x * x;
}

pll ans;

void dfs(ll num, ll x, ll mx) {
    if (mx == 0) {
        ans = max(ans, make_pair(num, x));
        return;
    }
    ll l = 1, r = 1e5, a = 0;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (pp(mid) <= mx) {
            a = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    ll lef1 = mx - pp(a), lef2 = pp(a) - pp(a - 1) - 1;
    //pr(pp(a))pr(lef1)
    //pr(pp(a - 1))pr(lef2)
    //pr("=========")
    dfs(num + 1, x + pp(a), lef1);
    dfs(num + 1, x + pp(a - 1), lef2);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll m;
    while (cin >> m) {
        ans.first = ans.second = 0;
        dfs(0, 0, m);
        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}
