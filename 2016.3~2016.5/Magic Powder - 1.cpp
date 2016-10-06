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
const int MAXN = 1e5 + 111;

ll a[MAXN], b[MAXN];
int n, k;

bool ok(ll x) {
    ll lef = k;
    for (int i = 0; i < n; ++i) {
        ll need = a[i] * x;
        if (b[i] < need) {
            if (b[i] + lef < need) return 0;
            lef -= (need - b[i]);
        }
    }
    return 1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &k)) {
        for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);
        for (int i = 0; i < n; ++i) {
            scanf("%I64d", &b[i]);
        }
        ll l = 0, r = 2e9 + 111, ans = 0;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (ok(mid)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
