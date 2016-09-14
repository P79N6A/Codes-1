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
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll l, r, l2, r2, k;
    cin >> l >> r >> l2 >> r2 >> k;
    if (l > l2) {
        swap(l, l2);
        swap(r, r2);
    }
    if (r < l2) cout << 0 << '\n';
    else {
        ll L = max(l, l2), R = min(r, r2);
        ll ans = R - L + 1;
        if (L <= k && k <= R) --ans;
        cout << ans << '\n';
    }
    return 0;
}
