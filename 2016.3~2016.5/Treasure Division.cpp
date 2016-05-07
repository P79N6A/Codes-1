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
const int MAXN = 1e6 + 111;

ll a[50];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
            sum += a[i];
        }

        int half = n / 2;
        set<ll> s[20];
        int up = 1 << half;
        for (int i = 0; i < up; ++i) {
            int indx = __builtin_popcount(i);
            ll temp = 0;
            for (int j = 0; j < half; ++j) {
                if (i & (1 << j))
                    temp += a[j];
            }
            s[indx].insert(temp);
        }

        int lef = n - half;
        set<ll> s2[20];
        up = 1 << lef;
        for (int i = 0; i < up; ++i) {
            int indx = __builtin_popcount(i);
            ll temp = 0;
            for (int j = 0; j < lef; ++j) {
                if (i & (1 << j))
                    temp += a[half + j];
            }
            s2[indx].insert(temp);
        }

        ll ans = sum;
        ll target = sum / 2;
        set<ll>::iterator it, it2;
        for (int i = 0; i <= half; ++i) {
            for (it = s[i].begin(); it != s[i].end(); ++it) {
                ll serch = target - *it;
                ll tans = *it;
                it2 = s2[half - i].lower_bound(serch);
                if (it2 == s2[half - i].end()) --it2;
                tans += *it2;
                ll cmp = sum - tans - tans;
                if (cmp < 0) cmp = -cmp;
                ans = min(ans, cmp);
            }
        }
        for (int i = 0; i <= lef; ++i) {
            for (it = s2[i].begin(); it != s2[i].end(); ++it) {
                ll serch = target - *it;
                ll tans = *it;
                if (lef - i > half) continue;
                it2 = s[lef - i].lower_bound(serch);
                if (it2 == s[lef - i].end()) --it2;
                tans += *it2;
                ll cmp = sum - tans - tans;
                if (cmp < 0) cmp = -cmp;
                ans = min(ans, cmp);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
