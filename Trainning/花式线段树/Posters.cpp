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
const int MAXN = 5e4 + 111;

struct Seg {
    int l, r, h, d;
    bool operator < (const Seg&t)const {
        return h < t.h;
    }
}a[MAXN << 3];

void addSeg(int &id, int x1, int y1, int x2, int y2) {
    //printf("%d %d -> %d %d\n", x1, y1, x2, y2);
    if (x1 == x2 || y1 == y2) return;
    a[++id] = Seg{x1, x2, y1, 1};
    a[++id] = Seg{x1, x2, y2, -1};
}

int all[MAXN << 2], hs[MAXN];
int sum[MAXN << 2], cnt[MAXN << 2];

void push_up(int l, int r, int rt) {
    if (cnt[rt]) sum[rt] = all[r + 1] - all[l];
    else if (l == r) sum[rt] = 0;
    else sum[rt] = sum[ls] + sum[rs];
}

void update(int L, int R, int l, int r, int rt, int val) {
    if (L <= l && r <= R) {
        cnt[rt] += val;
        push_up(l, r, rt);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) update(L, R, lson, val);
    if (mid < R) update(L, R, rson, val);
    push_up(l, r, rt);
    return;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, x[4], y[4];
    while (~scanf("%d", &n) && n) {
        int num = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 4; ++j) scanf("%d%d", &x[j], &y[j]);
            addSeg(num, x[0], y[0], x[2], y[3]);
            addSeg(num, x[0], y[3], x[3], y[1]);
            addSeg(num, x[3], y[2], x[1], y[1]);
            addSeg(num, x[2], y[0], x[1], y[2]);
            int base = (i - 1) << 2;
            for (int j = 0; j < 4; ++j) all[base + j + 1] = x[j];
        }
        n <<= 2;
        sort(a + 1, a + 1 + num);
        sort(all + 1, all + 1 + n);
        int len = unique(all + 1, all + 1 + n) - all - 1;
        for (int i = 1; i <= len; ++i) hs[all[i]] = i;
        ll ans = 0;
        memset(cnt, 0, sizeof cnt);
        memset(sum, 0, sizeof sum);
        n = len;
        for (int i = 1; i < num; ++i) {
            int l = hs[a[i].l], r = hs[a[i].r];
            update(l, r - 1, root, a[i].d);
            ans += (ll)sum[1] * (a[i + 1].h - a[i].h);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
