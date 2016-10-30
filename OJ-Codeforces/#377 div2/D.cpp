#include <bits/stdc++.h>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int d[MAXN], a[MAXN], n, m;
int cnt[MAXN], len;

bool ok(int day) {
    memset(cnt, 0, sizeof cnt);
    len = 0;
    int p = -1;
    for (int i = day; i >= 1; --i) {
        if (d[i] && !cnt[d[i]]) {
            ++cnt[d[i]];
            ++len;
        }
        else ++cnt[d[i]];
        if (len == m) {
            p = i;
            break;
        }
    }
    if (p == -1) return 0;
    int tol = p - 1;
    for (int i = p; i <= day; ++i) {
        if (d[i] && cnt[d[i]] == 1) {
            if (tol >= a[d[i]]) {
                tol -= a[d[i]];
                --len;
            }
            else break;
        }
        else ++tol;
        --cnt[d[i]];
    }
    return len == 0;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &d[i]);
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &a[i]);
        }
        int ans = -1, l = 1, r = n;
        while (l <= r) {
            int mid = l + r >> 1;
            if (ok(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
