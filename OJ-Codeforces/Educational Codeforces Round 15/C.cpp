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
#define LL long long
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

LL a[MAXN], b[MAXN], n, m;

bool ok(LL r) {
    for (int i = 0; i < n; ++i) {
        int ll = lower_bound(b, b + m + 2, a[i] - r) - b;
        int rr = lower_bound(b, b + m + 2, a[i]) - b;
        if ((a[i] - b[ll] >= 0 && a[i] - b[ll] <= r) || b[rr] - a[i] <= r) continue;
        return 0;
    }
    return 1;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);
    for (int i = 1; i <= m; ++i) scanf("%I64d", &b[i]);
    b[0] = -1e15;
    b[m + 1] = 1e15;
    LL l = 0, r = 2e10 + 11, ans = 0;
    while (l <= r) {
        LL mid = (l + r) >> 1;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    printf("%I64d\n", ans);
    return 0;
}
