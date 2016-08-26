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
const int mod = 360;
const double PI = acos(-1);

double lenx[MAXN << 3], leny[MAXN << 3];
int lazy[MAXN << 3], ang[MAXN << 3];

void push_up(int rt) {
    lenx[rt] = lenx[ls] + lenx[rs];
    leny[rt] = leny[ls] + leny[rs];
}

void update(int rt, int a) {
    ang[rt] = (ang[rt] + a) % mod;
    lazy[rt] = (lazy[rt] + a) % mod;
    double x = lenx[rt], y = leny[rt];
    double deg = a / 180.0 * PI;
    lenx[rt] = cos(deg) * x - sin(deg) * y;
    leny[rt] = sin(deg) * x + cos(deg) * y;
}

void push_down(int rt) {
    if (lazy[rt]) {
        update(ls, lazy[rt]);
        update(rs, lazy[rt]);
        lazy[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    lazy[rt] = ang[rt] = 0;
    if (l == r) {
        lenx[rt] = 0;
        scanf("%lf", &leny[rt]);
        return;
    }
    int mid = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

void update(int l, int r, int rt, int L, int R, int a) {
    if (L <= l && r <= R) {
        update(rt, a);
        return;
    }
    push_down(rt);
    int mid = l + r >> 1;
    if (L <= mid) update(lson, L, R, a);
    if (mid < R) update(rson, L, R, a);
    push_up(rt);
}

int query(int l, int r, int rt, int pos) {
    if (l == r) {
        return ang[rt];
    }
    push_down(rt);
    int mid = l + r >> 1;
    if (pos <= mid) return query(lson, pos);
    else return query(rson, pos);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, c;
    bool first = 1;
    while (~scanf("%d%d", &n, &c)) {
        if (first) first = 0;
        else puts("");
        build(root);
        int s, a;
        while (c --) {
            scanf("%d%d", &s, &a);
            int a1 = query(root, s);
            int a2 = query(root, s + 1);
            int na = (a - (180 + (a2 - a1 + mod) % mod) + mod) % mod;
            update(root, s + 1, n, na);
            printf("%.2f %.2f\n", lenx[1], leny[1]);
        }
    }
    return 0;
}
