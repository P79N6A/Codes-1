#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4 + 111;

vector<int> G[MAXN];
int rt, pa[MAXN], dep[MAXN];

void dfs(int v, int p, int d)
{
    pa[v] = p;
    dep[v] = d;
    for (int i = 0; i < G[v].size(); ++i)
    {
        if (G[v][i] != p) dfs(G[v][i], v, d + 1);
    }
}

void init()
{
    dfs(rt, -1, 0);
}

int lca(int u, int v)
{
    while (dep[u] > dep[v]) u = pa[u];
    while (dep[v] > dep[u]) v = pa[v];
    while (u != v)
    {
        u = pa[u];
        v = pa[v];
    }
    return u;
}

int main()
{
    int n, t; scanf("%d", &t);
    while (t --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) G[i].clear(), pa[i] = -1;
        int up = n - 1, u, v;
        for (int i = 0; i < up; ++i)
        {
            scanf("%d%d", &u, &v);
            pa[v] = u;
            G[u].push_back(v);
        }
        int who = 1;
        while (pa[who] != -1) who = pa[who];
        rt = who;
        init();
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}
