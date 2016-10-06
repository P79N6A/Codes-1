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
#include<assert.h>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int h[MAXN], w;
ll n, sum[MAXN];
int L[MAXN], R[MAXN];

bool ok(ll high) {
    memset(L, 0, sizeof L);
    memset(R, 0x3f, sizeof R);
    for (int i = 1; i <= w; ++i) {
        ll pos = i + high - h[i];
        if (pos <= w)
            L[pos] = max(L[pos], i);
    }
    for (int i = w; i > 0; --i) {
        ll pos = i - (high - h[i]);
        if (pos >= 1)
            R[pos] = min(R[pos], i);
    }
    for (int i = w - 1; i > 0; --i) R[i] = min(R[i + 1], R[i]);
    for (int i = 1; i <= w; ++i) L[i] = max(L[i - 1], L[i]);
    for (int i = 1; i <= w; ++i) {
        if (!L[i] || R[i] == 0x3f3f3f3f) continue;
        ll tol = 0;
        ll l = high - (i - L[i]), r = high - (R[i] - i);
        tol += (high + l) * (i - L[i] + 1) / 2;
        tol += (high + r) * (R[i] - i + 1) / 2;
        tol += h[L[i]] - l;
        tol += h[R[i]] - r;
        tol -= high;
        // 总个数 - 已存个数 = 新入个数
        if (tol - (sum[R[i]] - sum[L[i] - 1]) <= n) return 1;
    }
    return 0;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
//    freopen("landscape.in", "r", stdin);
//    freopen("landscape.out", "w", stdout);
    ll l = 0, r = 2e9;
    scanf("%d%I64d", &w, &n);
    for (int i = 1; i <= w; ++i) {
        scanf("%d", &h[i]);
        l = max(l, (ll)h[i]);
        sum[i] = sum[i - 1] + h[i];
    }
    int ans = -1;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (ok(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}
