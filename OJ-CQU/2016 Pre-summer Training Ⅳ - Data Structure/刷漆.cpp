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
#define root 0, n - 1, 1
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

struct P {
    int l, r, lazy;
}t[MAXN << 3];
int col[MAXN];

void build(int l, int r, int rt) {
    t[rt].lazy = -1;
    t[rt].l = l;
    t[rt].r = r;
    if (l == r) {
        t[rt].lazy = col[l];
        return;
    }
    int mid = l + r >> 1;
    build(lson);
    build(rson);
}

void push_down(int rt) {
    if (t[rt].lazy != -1) {
        t[rt << 1].lazy = t[rt << 1 | 1].lazy = t[rt].lazy;
        t[rt].lazy = -1;
    }
}

void update(int L, int R, int c, int rt) {
    int l = t[rt].l, r = t[rt].r;
    if (L <= l && r <= R) {
        t[rt].lazy = c;
        return;
    }
    push_down(rt);
    int mid = l + r >> 1;
    if (L <= mid) update(L, R, c, ls);
    if (mid < R) update(L, R, c, rs);
}

int query(int L, int R, int c, int rt) {
    int l = t[rt].l, r = t[rt].r;
    if (t[rt].lazy != -1 && L <= l && r <= R) {
        if (t[rt].lazy == c) {
            return r - l + 1;
        }
        else return 0;
    }
    push_down(rt);
    int mid = l + r >> 1;
    int ret = 0;
    if (L <= mid) ret += query(L, R, c, ls);
    if (mid < R) ret += query(L, R, c, rs);
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int T, n, m; scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &col[i]);
        }
        build(root);
        int op, a, b, c;
        while (m --) {
            scanf("%d%d%d%d", &op, &a, &b, &c);
            if (op == 1) update(a, b, c, 1);
            else printf("%d\n", query(a, b, c, 1));
        }
    }
    return 0;
}
