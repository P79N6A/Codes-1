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
#define root 1, n, 1
#define ls rt << 1
#define rs rt << 1 | 1
#define lson l, mid, ls
#define rson mid + 1, r, rs
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4 + 111;

struct Seg {
    int l, r, h, d;
    bool operator < (const Seg&t)const {
        return h < t.h;
    }
}a[2][MAXN];
int all[2][MAXN], len[2];

int sum[MAXN << 3], cnt[MAXN << 3];

void push_up(int l, int r, int rt, int op) {
    if (cnt[rt]) sum[rt] = all[op][r + 1] - all[op][l];
    else if (l == r) sum[rt] = 0;
    else sum[rt] = sum[ls] + sum[rs];
}

void update(int L, int R, int l, int r, int rt, int val, int op) {
    if (L <= l && r <= R) {
        cnt[rt] += val;
        push_up(l, r, rt, op);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) update(L, R, lson, val, op);
    if (mid < R) update(L, R, rson, val, op);
    push_up(l, r, rt, op);
    return;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, x1, y1, x2, y2;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            a[0][i] = Seg{x1, x2, y1, 1}, a[0][i + n] = Seg{x1, x2, y2, -1};
            a[1][i] = Seg{y1, y2, x1, 1}, a[1][i + n] = Seg{y1, y2, x2, -1};
            all[0][i] = x1, all[0][i + n] = x2;
            all[1][i] = y1, all[1][i + n] = y2;
        }
        n <<= 1;
        for (int i = 0; i < 2; ++i) {
            sort(a[i] + 1, a[i] + 1 + n);
            sort(all[i] + 1, all[i] + 1 + n);
            len[i] = unique(all[i] + 1, all[i] + 1 + n) - all[i] - 1;
        }
        int ans = 0;
        // X、Y各来一次
        for (int i = 0; i < 2; ++i) {
            int last = 0;
            memset(sum, 0, sizeof sum);
            memset(cnt, 0, sizeof cnt);
            for (int j = 1; j <= n; ++j) {
                int l = lower_bound(all[i] + 1, all[i] + 1 + len[i], a[i][j].l) - all[i];
                int r = lower_bound(all[i] + 1, all[i] + 1 + len[i], a[i][j].r) - all[i];
                update(l, r - 1, root, a[i][j].d, i);
                ans += abs(sum[1] - last);
                last = sum[1];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
