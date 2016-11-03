#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define ll long long
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

struct Edge {
    int u, v, w, c, id;
    bool operator < (const Edge&t)const {
        if (w == t.w) return c < t.c;
        return w < t.w;
    }
}edge[MAXN];

int p[MAXN], n, m, ss, f[20][MAXN], dep[MAXN];
int mx[20][MAXN];
vector<pii> tree[MAXN];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

void unite(int u, int v) {
    u = find(u), v = find(v);
    p[u] = v;
}

ll kruskal() {
    sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= n; ++i) p[i] = i;
    ll ret = 0;
    for (int i = 1; i <= m; ++i) {
        int u = edge[i].u, v = edge[i].v;
        if (find(u) != find(v)) {
            unite(u, v);
            ret += edge[i].w;
            tree[u].push_back(make_pair(v, edge[i].w));
            tree[v].push_back(make_pair(u, edge[i].w));
        }
    }
    return ret;
}

void dfs(int u, int fa) {
    for (int i = 0; i < tree[u].size(); ++i) {
        pii cur = tree[u][i];
        int v = cur.first, w = cur.second;
        if (v == fa) continue;
        f[0][v] = u;
        mx[0][v] = w;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (dep[u] <= dep[f[i][v]]) v = f[i][v];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (f[i][u] != f[i][v]) {
            u = f[i][u];
            v = f[i][v];
        }
    }
    return f[0][u];
}

int query(int u, int v) {
    int ast = lca(u, v);
    int ret = -1;
    for (int i = 19; i >= 0; --i) {
        if (dep[f[i][u]] >= dep[ast]) {
            ret = max(ret, mx[i][u]);
            u = f[i][u];
        }
    }
    for (int i = 19; i >= 0; --i) {
        if (dep[f[i][v]] >= dep[ast]) {
            ret = max(ret, mx[i][v]);
            v = f[i][v];
        }
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) scanf("%d", &edge[i].w);
    for (int i = 1; i <= m; ++i) scanf("%d", &edge[i].c);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &edge[i].u, &edge[i].v);
        edge[i].id = i;
    }
    scanf("%d", &ss);
    ll tol = kruskal();
    dfs(1, 0);
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j <= n; ++j) {
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][f[i - 1][j]]);
            f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }
    int who = -1, lef = 0;
    ll ans;
    for (int i = 1; i <= m; ++i) {
        int mxw = query(edge[i].u, edge[i].v);
        ll temp = tol - mxw + edge[i].w - ss / edge[i].c;
        if (who == -1 || temp < ans) {
            ans = temp;
            who = i;
            lef = edge[i].w - ss / edge[i].c;
        }
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; ++i) p[i] = i;
    p[edge[who].u] = edge[who].v;
    printf("%d %d\n", edge[who].id, lef);
    for (int i = 1; i <= m; ++i) {
        int u = edge[i].u, v = edge[i].v;
        if (find(u) != find(v)) {
            unite(u, v);
            printf("%d %d\n", edge[i].id, edge[i].w);
        }
    }
    return 0;
}