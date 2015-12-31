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
const int MAXN = 2e5 + 111;

ll a[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll n, k;
    while (~scanf("%I64d%I64d", &n, &k))
    {
        for (int i = 0; i < n; ++i) scanf("%I64d", a + i);

        map<ll, ll> cnt, ccnt;
        ll ans = 0;
        if (k != 1)
        {
            for (int i = n - 1; i > -1; --i)
            {
                if (a[i] == 0)
                {
                    ++cnt[a[i]];
                    if (cnt[a[i]] >= 3)
                    {
                        ccnt[a[i]] += cnt[a[i] * k] - 2;
                        ans += ccnt[a[i] * k];
                    }
                    continue;
                }
                ++cnt[a[i]];
                ccnt[a[i]] += cnt[a[i] * k];
                ans += ccnt[a[i] * k];
            }
        }
        else
        {
            for (int i = n - 1; i > -1; --i)
            {
                ++cnt[a[i]];
                if (cnt[a[i]] >= 3)
                {
                    ccnt[a[i]] += cnt[a[i] * k] - 2;
                    ans += ccnt[a[i] * k];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
