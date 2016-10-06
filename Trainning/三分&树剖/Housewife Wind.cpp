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
#define root 0, pos - 1, 1
#define ls rt << 1
#define rs rt << 1 | 1
#define lson l, mid, ls
#define rson mid + 1, r, rs
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

struct Edge {
    int to, nxt;
}edge[MAXN << 1];
int head[MAXN], tol;
int e[MAXN][3];

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

int pos;
int son[MAXN], top[MAXN], fa[MAXN], dep[MAXN], num[MAXN], p[MAXN], fp[MAXN];

inline void init() {
    tol = pos = 0;
    memset(head, -1, sizeof head);
    memset(son, -1, sizeof son);
}

// ÇóÖØ¶ù×Ó
void dfs(int u, int pre, int d) {
    dep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == pre) continue;
        dfs(v, u, d + 1);
        num[u] += num[v];
        if (son[u] == -1 || num[v] > num[son[u]]) son[u] = v;
    }
}

void getpos(int u, int sp) {
    top[u] = sp;
    p[u] = pos++;
    fp[pos - 1] = u;
    if (son[u] == -1) return;
    getpos(son[u], sp);
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == son[u] || v == fa[u]) continue;
        getpos(v, v);
    }
}

int sum[MAXN << 2];

void build(int l, int r, int rt) {
    sum[rt] = 0;
    if (l == r) return;
    int mid = l + r >> 1;
    build(lson);
    build(rson);
}

void update(int p, int val, int l, int r, int rt) {
    if (l == r) {
        sum[rt] = val;
        return;
    }
    int mid = l + r >> 1;
    if (p <= mid) update(p, val, lson);
    else update(p, val, rson);
    sum[rt] = sum[ls] + sum[rs];
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return sum[rt];
    int mid = l + r >> 1, ret = 0;
    if (L <= mid) ret += query(L, R, lson);
    if (mid < R) ret += query(L, R, rson);
    return ret;
}

int getsum(int u, int v) {
    int fu = top[u], fv = top[v], ret = 0;
    while (fu != fv) {
        if (dep[fu] < dep[fv]) {
            swap(fu, fv);
            swap(u, v);
        }
        ret += query(p[fu], p[u], root);
        u = fa[fu]; fu = top[u];
    }
    if (u == v) return ret;
    if (dep[u] > dep[v]) swap(u, v);
    return ret + query(p[son[u]], p[v], root);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, q, s;
    while (~scanf("%d%d%d", &n, &q, &s)) {
        init();
        for (int i = 1; i < n; ++i) {
            scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]);
            addedge(e[i][0], e[i][1]);
            addedge(e[i][1], e[i][0]);
        }
        dfs(1, 0, 0);
        getpos(1, 1);
        build(root);
        for (int i = 1; i < n; ++i) {
            if (dep[e[i][0]] > dep[e[i][1]]) swap(e[i][0], e[i][1]);
            update(p[e[i][1]], e[i][2], root);
        }
        int op, x, val;
        while (q --) {
            scanf("%d%d", &op, &x);
            if (op) {
                scanf("%d", &val);
                update(p[e[x][1]], val, root);
            }
            else {
                printf("%d\n", getsum(s, x));
                s = x;
            }
        }
    }
    return 0;
}
