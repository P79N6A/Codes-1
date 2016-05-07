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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int MAXN = 5e4 + 111;
const int MAXM = 1e5 + 111;

struct Edge {
    int from, to, next, w;
    bool operator < (const Edge& t)const {
        return w < t.w;
    }
}edge2[MAXM], edge[MAXM];
int head[MAXN], tol, par[MAXN][20], maxw[MAXN][20], dep[MAXN];
int pa[MAXN];

void init(int n) {
    memset(head, -1, sizeof head);
    for (int i = 1; i <= n; ++i) pa[i] = i;
    tol = 0;
}

int find(int x) {
    return x == pa[x] ? x : pa[x] = find(pa[x]);
}

void addedge(int u, int v, int w) {
    edge[tol].to = v;
    edge[tol].next = head[u];
    edge[tol].w = w;
    head[u] = tol++;
}

void dfs(int u, int p, int d, int w) {
    par[u][0] = p;
    maxw[u][0] = w;
    dep[u] = d;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v != p) {
            dfs(v, u, d + 1, edge[i].w);
        }
    }
}

void solve(int n) {
    dfs(1, -1, 0, 0);
    for (int i = 0; i + 1 < 19; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (par[j][i] < 0) par[j][i + 1] = -1;
            else {
                par[j][i + 1] = par[par[j][i]][i];
                maxw[j][i + 1] = max(maxw[j][i], maxw[par[j][i]][i]);
            }
        }
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 0; i < 19; ++i) {
        if (dep[v] - dep[u] >> i & 1) {
            v = par[v][i];
        }
    }
    if (u == v) return u;
    for (int i = 18; i >= 0; --i) {
        if (par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
    }
    return par[u][0];
}

int getans(int u, int v) {
    int ret = 0;
    for(int i = 0; i < 19; ++i)
        if(dep[u] - dep[v] >> i & 1)
            ret = max(ret, maxw[u][i]), u = par[u][i];
    return ret;
}

int main()
{
    int n, m, q;
    bool flag = 0;
    while (~scanf("%d%d", &n, &m)) {
        if (flag) putchar('\n');
        flag = 1;
        init(n);

        int u, v, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            edge2[i].from = u;
            edge2[i].to = v;
            edge2[i].w = w;
        }
        sort(edge2, edge2 + m);

        for (int i = 0; i < m; ++i) {
            int u = edge2[i].from, v = edge2[i].to;
            int uu = find(u), vv = find(v);
            if (uu != vv) {
                pa[uu] = vv;
                addedge(u, v, edge2[i].w);
                addedge(v, u, edge2[i].w);
            }
        }

        solve(n);

        scanf("%d", &q);
        for (int i = 0; i < q; ++i) {
            scanf("%d%d", &u, &v);
            int p = lca(u, v);
            printf("%d\n", max(getans(u, p), getans(v, p)));
        }
    }
    return 0;
}
