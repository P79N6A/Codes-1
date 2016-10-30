#include <bits/stdc++.h>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll a[3];
    while (cin >> a[0] >> a[1] >> a[2]) {
        ll mx = max(a[0], max(a[1], a[2]));
        ll ans = 0;
        for (int i = 0; i < 3; ++i) {
            ans += mx - a[i];
        }
        for (int i = 0; i < 3; ++i) {
            ll temp = 0, ok = 1;
            for (int j = 0; j < 3; ++j) {
                if (j == i && a[j] == mx) {
                    ok = 0;
                    break;
                }
                temp += mx - a[j];
                if (j == i) --temp;
            }
            if (ok) ans = min(temp, ans);
        }
        for (int i = 0; i < 3; ++i) {
            ll temp = 0, ok = 1;
            for (int j = 0; j < 3; ++j) {
                if (j == i && a[j] != mx) {
                    ok = 0;
                    break;
                }
                else if (j != i && a[j] == mx) {
                    ok = 0;
                    break;
                }
                temp += mx - a[j] - 1;
                if (j == i) ++temp;
            }
            if (ok) ans = min(temp, ans);
        }
        cout << ans << '\n';
    }
    return 0;
}
