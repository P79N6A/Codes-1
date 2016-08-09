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
const int MAXN = 1e5 + 111;

ll a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    ll n, k;
    while (cin >> n >> k) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        ll num = 0, mx = 0, r = n - 2;
        for (int i = n - 1; i >= 0; --i) {
            ll tnum = i - r, tmx = a[i];
            if (i < n - 1) {
                k += (i - r) * (a[i + 1] - a[i]);
            }
            while (r >= 0 && tmx - a[r] <= k) {
                k -= tmx - a[r];
                --r;
                ++tnum;
            }
            if (tnum >= num) {
                num = tnum;
                mx = tmx;
            }
        }
        cout << num << ' ' << mx << '\n';
    }
    return 0;
}
