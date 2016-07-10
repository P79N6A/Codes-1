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

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

ll ok(ll x) {
    ll ret = 0;
    for (ll i = 2; ;++i) {
        ll temp = i * i * i;
        if (temp > x || ret > x) {
            break;
        }
        ret += x / temp;
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll m;
    while (cin >> m) {
        ll l = 1, r = 1e16;
        ll ans = -1;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            ll cal = ok(mid);
            if (cal >= m) {
                if (cal == m) ans = mid;
                r = mid - 1;
            }
            else if (cal < m) {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
