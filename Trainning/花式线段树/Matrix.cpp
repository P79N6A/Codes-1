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
const double eps = 1e-6;

int n;

struct Nodex {
    bool val[MAXN << 3];
    void build(int l, int r, int rt) {
        val[rt] = 0;
        if (l == r) return;
        int mid = l + r >> 1;
        build(lson);
        build(rson);
    }
    void update(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) {
            val[rt] ^= 1;
            return;
        }
        int mid = l + r >> 1;
        if (L <= mid) update(L, R, lson);
        if (mid < R) update(L, R, rson);
    }
    int query(int p, int l, int r, int rt) {
        int ret = val[rt];
        if (l == r) return ret;
        int mid = l + r >> 1;
        if (p <= mid) return ret ^ query(p, lson);
        else return ret ^ query(p, rson);
    }
}stx[MAXN << 3];

void build(int l, int r, int rt, int ll, int rr) {
    stx[rt].build(ll, rr, 1);
    if (l == r) return;
    int mid = l + r >> 1;
    build(lson, ll, rr);
    build(rson, ll, rr);
}

void update(int x1, int x2, int y1, int y2, int l, int r, int rt) {
    if (x1 <= l && r <= x2) {
        stx[rt].update(y1, y2, root);
        return;
    }
    int mid = l + r >> 1;
    if (x1 <= mid) update(x1, x2, y1, y2, lson);
    if (mid < x2) update(x1, x2, y1, y2, rson);
}

int query(int x1, int y1, int l, int r, int rt) {
    int ret = stx[rt].query(y1, root);
    if (l == r) {
        return ret;
    }
    int mid = l + r >> 1;
    if (x1 <= mid) return ret ^ query(x1, y1, lson);
    else return ret ^ query(x1, y1, rson);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, q; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &q);
        build(root, 1, n);
        char op[2];
        int x1, y1, x2, y2;
        while (q --) {
            scanf("%s%d%d", op, &x1, &y1);
            if (op[0] == 'C') {
                scanf("%d%d", &x2, &y2);
                update(x1, x2, y1, y2, root);
            }
            else {
                printf("%d\n", query(x1, y1, root));
            }
        }
        if (t) puts("");
    }
    return 0;
}
