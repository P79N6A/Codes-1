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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 4e4 + 111;
const int MAXM = 500;

struct Edge {
    int next, to, w;
}edge[MAXN * 2];

struct Query {
    int next, to, id;
}query[MAXM * 2];

int head[MAXN], qhead[MAXN], tol, qtol;
int dep[MAXN], par[MAXN], ans[MAXN];
bool vis[MAXN];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

void init() {
    tol = qtol = 0;
    memset(head, -1, sizeof head);
    memset(qhead, -1, sizeof qhead);
    memset(vis, 0, sizeof vis);
}

void addedge(int u, int v, int w) {
    edge[tol].to = v;
    edge[tol].next = head[u];
    edge[tol].w = w;
    head[u] = tol++;
}

void qaddedge(int u, int v, int id) {
    query[qtol].to = v;
    query[qtol].id = id;
    query[qtol].next = qhead[u];
    qhead[u] = qtol++;
}

void tarjan(int u, int sum) {
    dep[u] = sum;
    par[u] = u;
    vis[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (!vis[v]) {
            tarjan(v, sum + edge[i].w);
            par[v] = u;
        }
    }

    for (int i = qhead[u]; ~i; i = query[i].next) {
        int v = query[i].to;
        if (vis[v]) {
            ans[query[i].id] = dep[u] + dep[v] - 2 * dep[par[find(v)]];
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        init();
        int n, m;
        scanf("%d%d", &n, &m);
        int u, v, w;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            qaddedge(u, v, i);
            qaddedge(v, u, i);
        }

        tarjan(1, 0);

        for (int i = 0; i < m; ++i) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
