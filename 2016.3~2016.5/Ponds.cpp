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
const int MAXN = 1e4 + 111;
const int MAXM = 1e5 + 111;

int p, m;
int par[MAXN], num[MAXN];
ll val[MAXN];
bool cut[MAXN];
bool vis[MAXN];
int u[MAXN], v[MAXN];

struct Edge {
    int to, next;
}edge[MAXM * 2];
int head[MAXN], tol, e[MAXN];

void addedge(int u, int v) {
    edge[tol].next = head[u];
    edge[tol].to = v;
    head[u] = tol++;
}

void init() {
    tol = 0;
    for (int i = 1; i <= p; ++i) {
        par[i] = i;
        cut[i] = e[i] = vis[i] = 0;
        num[i] = 1;
        head[i] = -1;
    }
}

void dfs(int u, int pp) {
    cut[u] = 1;
    e[u] = -1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == pp) continue;
        --e[v];
        if (e[v] != -1 && e[v] < 2) dfs(v, u);
    }
}

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
    par[x] = y;
    num[y] += num[x];
    val[y] += val[x];
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &p, &m);
        init();
        for (int i = 1; i <= p; ++i) scanf("%lld", &val[i]);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u[i], &v[i]);
            addedge(u[i], v[i]);
            addedge(v[i], u[i]);
            ++e[u[i]], ++e[v[i]];
        }
        for (int i = 1; i <= p; ++i) {
            if (e[i] != -1 && e[i] < 2) dfs(i, -1);
        }
        for (int i = 0; i < m; ++i) {
            if (cut[u[i]] || cut[v[i]]) continue;
            int x = find(u[i]), y = find(v[i]);
            if (x == y) continue;
            unite(x, y);
        }
        ll sum = 0;
        for (int i = 1; i <= p; ++i) {
            if (cut[i]) continue;
            int cur = find(i);
            if (vis[cur] || num[cur] % 2 == 0) continue;
            vis[cur] = 1;
            sum += val[cur];
        }
        printf("%lld\n", sum);
    }
    return 0;
}
