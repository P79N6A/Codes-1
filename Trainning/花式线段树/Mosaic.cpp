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
const int MAXN = 808;
const double eps = 1e-6;

int ami, amx, n, mat[MAXN][MAXN];
int mi[MAXN << 3][MAXN << 3], mx[MAXN << 3][MAXN << 3];

void push_up(int xrt, int rt) {
    mx[xrt][rt] = max(mx[xrt][ls], mx[xrt][rs]);
    mi[xrt][rt] = min(mi[xrt][ls], mi[xrt][rs]);
}

void buildy(int xrt, int x, int l, int r, int rt) {
    if (l == r) {
        if (~x) {
            mi[xrt][rt] = mx[xrt][rt] = mat[x][l];
        }
        else {
            mi[xrt][rt] = min(mi[xrt << 1][rt], mi[xrt << 1|1][rt]);
            mx[xrt][rt] = max(mx[xrt << 1][rt], mx[xrt << 1|1][rt]);
        }
        return;
    }
    int mid = l + r >> 1;
    buildy(xrt, x, lson);
    buildy(xrt, x, rson);
    push_up(xrt, rt); // ÀàËÆpush up
}

void buildx(int l, int r, int rt) {
    if (l == r) {
        buildy(rt, l, root);
        return;
    }
    int mid = l + r >> 1;
    buildx(lson);
    buildx(rson);
    buildy(rt, -1, root);
}

void updatey(int xrt, int op, int y, int val, int l, int r, int rt) {
    if (l == r) {
        if (~op) {
            mi[xrt][rt] = mx[xrt][rt] = val;
        }
        else {
            mi[xrt][rt] = min(mi[xrt << 1][rt], mi[xrt << 1|1][rt]);
            mx[xrt][rt] = max(mx[xrt << 1][rt], mx[xrt << 1|1][rt]);
        }
        return;
    }
    int mid = l + r >> 1;
    if (y <= mid) updatey(xrt, op, y, val, lson);
    else updatey(xrt, op, y, val, rson);
    push_up(xrt, rt);
}

void updatex(int x, int y, int val, int l, int r, int rt) {
    if (l == r) {
        updatey(rt, 1, y, val, root);
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid) updatex(x, y, val, lson);
    else updatex(x, y, val, rson);
    updatey(rt, -1, y, val, root);
}

void queryy(int xrt, int y1, int y2, int l, int r, int rt) {
    if (y1 <= l && r <= y2) {
        ami = min(ami, mi[xrt][rt]);
        amx = max(amx, mx[xrt][rt]);
        return;
    }
    int mid = l + r >> 1;
    if (y1 <= mid) queryy(xrt, y1, y2, lson);
    if (mid < y2) queryy(xrt, y1, y2, rson);
}

void queryx(int x1, int x2, int y1, int y2, int l, int r, int rt) {
    if (x1 <= l && r <= x2) {
        queryy(rt, y1, y2, root);
        return;
    }
    int mid = l + r >> 1;
    if (x1 <= mid) queryx(x1, x2, y1, y2, lson);
    if (mid < x2) queryx(x1, x2, y1, y2, rson);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase = 0, t, x, q, y, l; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &mat[i][j]);
            }
        }
        buildx(root);
        scanf("%d", &q);
        printf("Case #%d:\n", ++kase);
        while (q --) {
            scanf("%d%d%d", &x, &y, &l);
            l = (l - 1) / 2;
            ami = INF, amx = 0;
            queryx(max(1, x - l), min(n, x + l), max(1, y - l), min(n, y + l), root);
            int nc = (ami + amx) / 2;
            printf("%d\n", nc);
            updatex(x, y, nc, root);
        }
    }
    return 0;
}
