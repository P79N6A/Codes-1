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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

struct Edge {
    int to, nxt;
}edge[MAXN << 1];
int tol, head[MAXN];

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

struct Tree {
    int ls, rs;
    int num, sum;
    void init() {
        ls = rs = sum = num = 0;
    }
}tree[MAXN * 20];
int n, indx, root[MAXN], c[MAXN];
int ans[MAXN], amount[MAXN];

inline void init() {
    memset(head, -1, sizeof head);
    memset(amount, 0, sizeof amount);
    indx = tol = 0;
}

void push_up(int rt) {
    int ls = tree[rt].ls, rs = tree[rt].rs;
    tree[rt].sum = tree[ls].sum + tree[rs].sum;
}

int build(int p, int l, int r) {
    int rt = ++indx;
    tree[rt].init();
    if (l == r) {
        tree[rt].num = 1;
        tree[rt].sum = (tree[rt].num != amount[p]);
        return rt;
    }
    int mid = l + r >> 1;
    if (p <= mid) tree[rt].ls = build(p, l, mid);
    else tree[rt].rs = build(p, mid + 1, r);
    push_up(rt);
    return rt;
}

void unite(int &u, int v, int l, int r) {
    if (!u || !v) {
        if (!u) u = v;
        return;
    }
    if (l == r) {
        tree[u].num += tree[v].num;
        tree[u].sum = (tree[u].num != amount[l]);
        return;
    }
    int mid = l + r >> 1;
    unite(tree[u].ls, tree[v].ls, l, mid);
    unite(tree[u].rs, tree[v].rs, mid + 1, r);
    push_up(u);
}

void dfs(int u, int f, int id) {
    root[u] = build(c[u], 1, n);
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == f) continue;
        dfs(v, u, i);
        unite(root[u], root[v], 1, n);
    }
    if (u != 1) {
        ans[id / 2] = tree[root[u]].sum;
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        init();
        for (int i = 1; i <= n; ++i) scanf("%d", &c[i]), ++amount[c[i]];
        int u, v;
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        dfs(1, 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
