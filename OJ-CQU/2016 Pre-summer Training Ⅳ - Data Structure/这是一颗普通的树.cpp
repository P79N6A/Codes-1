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
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e4 + 111;

struct Edge {
    int to, nxt;
}edge[MAXN * 2];
int head[MAXN], tol;
int top[MAXN], fa[MAXN], dep[MAXN], num[MAXN];
int p[MAXN], fp[MAXN];
int son[MAXN], pos;
int u[MAXN], v[MAXN], w[MAXN];

void init() {
    tol = 0;
    memset(head, -1, sizeof head);
    pos = 0;
    memset(son, -1, sizeof son);
}

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

void dfs1(int u, int pre, int d) {
    dep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v != pre) {
            dfs1(v, u, d + 1);
            num[u] += num[v];
            if (son[u] == -1 || num[v] > num[son[u]]) {
                son[u] = v;
            }
        }
    }
}

void getpos(int u, int sp) {
    top[u] = sp;
    p[u] = pos++;
    fp[p[u]] = u;
    if (son[u] == -1) return;
    getpos(son[u], sp);
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v != son[u] && v != fa[u]) getpos(v, v);
    }
}

struct T {
    int l, r, lazy, mx, mi;
}st[MAXN << 3];

void build(int l, int r, int rt) {
    st[rt].l = l;
    st[rt].r = r;
    st[rt].lazy = 0;
    st[rt].mx = -INF;
    st[rt].mi = INF;
    if (l == r) return;
    int mid = l + r >> 1;
    build(lson);
    build(rson);
}

void push_up(int rt) {
    st[rt].mi = min(st[ls].mi, st[rs].mi);
    st[rt].mx = max(st[ls].mx, st[rs].mx);
}

void push_down(int rt) {
    if (st[rt].lazy) {
        st[ls].lazy = 1 - st[ls].lazy;
        swap(st[ls].mx, st[ls].mi);
        st[ls].mx = -st[ls].mx;
        st[ls].mi = -st[ls].mi;

        st[rs].lazy = 1 - st[rs].lazy;
        swap(st[rs].mx, st[rs].mi);
        st[rs].mx = -st[rs].mx;
        st[rs].mi = -st[rs].mi;
        st[rt].lazy = 0;
    }
}

void update(int p, int val, int rt) {
    int l = st[rt].l, r = st[rt].r;
    if (l == r) {
        st[rt].lazy = 0;
        st[rt].mi = st[rt].mx = val;
        return;
    }
    push_down(rt);
    int mid = l + r >> 1;
    if (p <= mid) update(p, val, ls);
    else update(p, val, rs);
    push_up(rt);
}

void updateall(int L, int R, int rt) {
    int l = st[rt].l, r = st[rt].r;
    if (L <= l && r <= R) {
        st[rt].lazy = 1 - st[rt].lazy;
        swap(st[rt].mx, st[rt].mi);
        st[rt].mx = -st[rt].mx;
        st[rt].mi = -st[rt].mi;
        return;
    }
    push_down(rt);
    int mid = l + r >> 1;
    if (L <= mid) updateall(L, R, ls);
    if (mid < R) updateall(L, R, rs);
    push_up(rt);
}

int query(int L, int R, int rt) {
    int l = st[rt].l, r = st[rt].r;
    //printf("%d %d\n", l, r);
    if (L <= l && r <= R) {
        //pr(st[rt].mx)
        return st[rt].mx;
    }
    push_down(rt);
    int mid = l + r >> 1;
    int ret = -INF;
    if (L <= mid) ret = max(ret, query(L, R, ls));
    if (mid < R) ret = max(ret, query(L, R, rs));
    return ret;
}

void upuv(int u, int v) {
    int fu = top[u], fv = top[v];
    while (fu != fv) {
        if (dep[fu] < dep[fv]) {
            swap(fu, fv);
            swap(u, v);
        }
        updateall(p[fu], p[u], 1);
        u = fa[fu];
        fu = top[u];
    }
    if (u == v) return;
    if (dep[u] > dep[v]) swap(u, v);
    updateall(p[son[u]], p[v], 1);
}

int finduv(int u, int v) {
    int fu = top[u], fv = top[v];
    int temp = -INF;
    while (fu != fv) {
        if (dep[fu] < dep[fv]) {
            swap(fu, fv);
            swap(u, v);
        }
        temp = max(temp, query(p[fu], p[u], 1));
        u = fa[fu];
        fu = top[u];
    }
    if (u == v) return temp;
    if (dep[u] > dep[v]) swap(u, v);
    //pr(u)
    //pr(son[u])pr(p[son[u]])
    //pr(v)pr(p[v])
    return max(temp, query(p[son[u]], p[v], 1));
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\apple\\Desktop\\output.txt", "w", stdout);
    #endif
    int t, n, m;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 1; i < n; ++i) {
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
            addedge(u[i], v[i]);
            addedge(v[i], u[i]);
        }
        dfs1(1, 0, 0);
        getpos(1, 1);
        build(0, pos - 1, 1);
        for (int i = 1; i < n; ++i) {
            if (dep[u[i]] > dep[v[i]]) swap(u[i], v[i]);
            update(p[v[i]], w[i], 1);
        }
        int op, a, b;
        while (m --) {
            scanf("%d%d%d", &op, &a, &b);
            if (op == 1) {
                update(p[v[a]], b, 1);
            }
            else if (op == 2) {
                upuv(a, b);
            }
            else {
                printf("%d\n", finduv(a, b));
            }
        }
    }
    return 0;
}
