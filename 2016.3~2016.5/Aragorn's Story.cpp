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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 5e4 + 111;
const int MAXM = 1e5 + 111;

struct Edge {
    int to, next;
}edge[MAXM];
int head[MAXN];
// 它们分别是：深度，重儿子，儿子数，链顶端，父亲节点，在数组中位置，位置代表的节点
int dep[MAXN], son[MAXN], num[MAXN], top[MAXN], fa[MAXN], p[MAXN], fp[MAXN];
int enemy[MAXN];
int pos, tol;

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        son[i] = head[i] = -1;
    }
    pos = tol = 0;
}

void addedge(int u, int v) {
    edge[tol].to = v, edge[tol].next = head[u], head[u] = tol++;
}

void dfs1(int u, int pre, int d) {
    dep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v != pre) {
            dfs1(v, u, d + 1);
            num[u] += num[v];
            if (son[u] == -1 || num[son[u]] < num[v]) {
                son[u] = v;
            }
        }
    }
}

void dfs2(int u, int f) {
    p[u] = ++pos;
    top[u] = f;
    fp[p[u]] = u;
    if (son[u] == -1) return;
    dfs2(son[u], f);
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v != son[u] && v != fa[u])
            dfs2(v, v);
    }
}

struct Node {
    int l, r, lazy;
}st[MAXN << 2];

void build(int l, int r, int rt) {
    st[rt].l = l;
    st[rt].r = r;
    st[rt].lazy = 0;
    if (l == r) {
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
}

void pushdown(int rt) {
    if (st[rt].lazy != 0) {
        st[rt << 1].lazy += st[rt].lazy;
        st[rt << 1 | 1].lazy += st[rt].lazy;
        st[rt].lazy = 0;
    }
}

int query(int rt, int val) {
    if (st[rt].l == st[rt].r) return st[rt].lazy;
    pushdown(rt);
    int m = (st[rt].l + st[rt].r) >> 1;
    if (val <= m) return query(rt << 1, val);
    else return query(rt << 1 | 1, val);
}

void update(int L, int R, int w, int rt) {
    int l = st[rt].l, r = st[rt].r;
    if (L <= l && r <= R) {
        st[rt].lazy += w;
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, w, rt << 1);
    if (m < R) update(L, R, w, rt << 1 | 1);
}

void change(int u, int v, int w) {
    while (top[u] != top[v]) { // 慢慢向重链靠近
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        update(p[top[u]], p[u], w, 1);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    update(p[u], p[v], w, 1);
}

int main()
{
    int n, m, q, u, v, w;
    while (~scanf("%d%d%d", &n, &m, &q)) {
        init(n);
        for (int i = 1; i <= n; ++i) scanf("%d", &enemy[i]);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }

        dfs1(1, 0, 0);
        dfs2(1, 1);
        build(1, pos, 1);

        char op[2];
        while (q--) {
            scanf("%s", op);
            if (op[0] == 'Q') {
                scanf("%d", &u);
                printf("%d\n", enemy[u] + query(1, p[u]));
            }
            else {
                scanf("%d%d%d", &u, &v, &w);
                if (op[0] == 'D') w = -w;
                change(u, v, w);
            }
        }
    }
    return 0;
}
