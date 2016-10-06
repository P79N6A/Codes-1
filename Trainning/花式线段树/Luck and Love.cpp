/*
  二维线段树可以想象成这个样子
  设x轴某颗线段树id为ii，对应x轴区间[4,6]
  它对应的y轴线段树相当于把这个区间内的所有
  y轴合并在一起变成一个长条(设y轴总长度为3，[1,3])
   3 3 10      10
   4 9 2   --> 9
   1 6 8       8
  [4 5 6]      ii
  所以更新的时候，当更新的点在这个区域中时，我们就
  把它更新了。
 */
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
#define root 1, n, 1
#define ls rt << 1
#define rs rt << 1 | 1
#define lson l, mid, ls
#define rson mid + 1, r, rs
#define pr(x) cout << #x << " = " << (x) << " I ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1111;
const int MAXM = 222;
const double eps = 1e-6;

struct Nodey {
    int l, r;
    double val;
};

struct Nodex {
    int l, r;
    Nodey sty[MAXN << 3];
    void push_up(int rt) {
        sty[rt].val = max(sty[ls].val, sty[rs].val);
    }
    void build(int l, int r, int rt) {
        sty[rt].l = l, sty[rt].r = r, sty[rt].val = -1;
        if (l == r) return;
        int mid = l + r >> 1;
        build(lson);
        build(rson);
    }
    void update(int p, double val, int rt) {
        int l = sty[rt].l, r = sty[rt].r;
        if (l == r) {
            sty[rt].val = max(sty[rt].val, val);
            return;
        }
        int mid = l + r >> 1;
        if (p <= mid) update(p, val, ls);
        else update(p, val, rs);
        push_up(rt);
    }
    double query(int L, int R, int rt) {
        int l = sty[rt].l, r = sty[rt].r;
        if (L <= l && r <= R) return sty[rt].val;
        int mid = l + r >> 1;
        double ret = -1;
        if (L <= mid) ret = max(ret, query(L, R, ls));
        if (mid < R) ret = max(ret, query(L, R, rs));
        return ret;
    }
}stx[MAXM << 3];

void build(int l, int r, int rt, int ll, int rr) {
    stx[rt].l = l, stx[rt].r = r;
    stx[rt].build(ll, rr, 1);
    if (l == r) return;
    int mid = l + r >> 1;
    build(lson, ll, rr);
    build(rson, ll, rr);
}

void update(int h, int a, double val, int rt) {
    int l = stx[rt].l, r = stx[rt].r;
    stx[rt].update(a, val, 1);
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    if (h <= mid) update(h, a, val, ls);
    else update(h, a, val, rs);
}

double query(int L, int R, int LL, int RR, int rt) {
    int l = stx[rt].l, r = stx[rt].r;
    if (L <= l && r <= R) {
        return stx[rt].query(LL, RR, 1);
    }
    int mid = l + r >> 1;
    double ret = -1;
    if (L <= mid) ret = max(ret, query(L, R, LL, RR, ls));
    if (mid < R) ret = max(ret, query(L, R, LL, RR, rs));
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n) && n) {
        build(100, 200, 1, 0, 1000);
        char op[2];
        int h, x1, x2;
        double a, l, y1, y2;
        while (n --) {
            scanf("%s", op);
            if (op[0] == 'I') {
                scanf("%d%lf%lf", &h, &a, &l);
                update(h, a * 10 + eps, l, 1);
            }
            else {
                scanf("%d%d%lf%lf", &x1, &x2, &y1, &y2);
                if (x1 > x2) swap(x1, x2);
                if (y1 > y2) swap(y1, y2);
                double ans = query(x1, x2, y1 * 10 + eps, y2 * 10 + eps, 1);
                if (ans < 0) puts("-1");
                else printf("%.1f\n", ans);
            }
        }
    }
    return 0;
}
