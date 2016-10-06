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

struct P {
    int x, y;
    bool operator < (const P& t)const {
        if (x == t.x) return y < t.y;
        return x < t.x;
    }
}p[MAXN];

bool cmp(P a, P b) {
    return a.y < b.y;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    ll ans = 0;

    sort(p, p + n);
    ll cnt = 0, same = 0;
    for (int i = 1; i < n; ++i) {
        if (p[i].x == p[i - 1].x) {
            ++cnt;
            if (p[i].y == p[i - 1].y) ++same;
            else if (same) {
                ans -= same * (same + 1) / 2;
                same = 0;
            }
        }
        else if (cnt) {
            ans += cnt * (cnt + 1) / 2;
            if (same) {
                ans -= same * (same + 1) / 2;
                same = 0;
            }
            cnt = 0;
        }
    }
    if (cnt) {
        ans += cnt * (cnt + 1) / 2;
        if (same) ans -= same * (same + 1) / 2;
    }

    cnt = 0;
    sort(p, p + n, cmp);
    for (int i = 1; i < n; ++i) {
        if (p[i].y == p[i - 1].y) {
            ++cnt;
        }
        else if (cnt) {
            ans += cnt * (cnt + 1) / 2;
            cnt = 0;
        }
    }
    if (cnt) {
        ans += cnt * (cnt + 1) / 2;
    }

    printf("%I64d\n", ans);
    return 0;
}
