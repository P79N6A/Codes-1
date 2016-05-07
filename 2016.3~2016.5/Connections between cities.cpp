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
const int MAXN = 1e4 + 111;
const int MAXM = 1e6 + 111;

struct Edge {
    int to, next, w;
}edge[MAXN * 2];
int head[MAXN], tol;

struct Query {
    int to, next, id;
}query[MAXM * 2];
int qhead[MAXN], qtol, ans[MAXM], par[MAXN], dep[MAXN];
bool vis[MAXN];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

void addedge(int u, int v, int w) {
    edge[tol].to = v; edge[tol].next = head[u]; edge[tol].w = w;
    head[u] = tol++;
    edge[tol].to = u; edge[tol].next = head[v]; edge[tol].w = w;
    head[v] = tol++;
}

void qaddedge(int u, int v, int id) {
    query[qtol].to = v; query[qtol].next = qhead[u]; query[qtol].id = id;
    qhead[u] = qtol++;
    query[qtol].to = u; query[qtol].next = qhead[v]; query[qtol].id = id;
    qhead[v] = qtol++;
}

void init(int n) {
    tol = qtol = 0;
    for (int i = 1; i <= n; ++i) par[i] = i, vis[i] = 0;
    memset(head, -1, sizeof head);
    memset(qhead, -1, sizeof qhead);
}

void tarjan(int u, int sum) {
    dep[u] = sum;
    vis[u] = 1;
    par[u] = u;
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
            ans[query[i].id] = dep[u] + dep[v] - 2 * dep[find(v)];
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, c;
    while (~scanf("%d%d%d", &n, &m, &c)) {
        init(n);
        int u, v, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
            u = find(u), v = find(v);
            if (u != v) par[u] = v;
        }
        for (int i = 0; i < c; ++i) {
            scanf("%d%d", &u, &v);
            if (find(u) != find(v)) ans[i] = -1;
            else qaddedge(u, v, i);
        }

        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                tarjan(i, 0);
            }
        }

        for (int i = 0; i < c; ++i) {
            if (ans[i] == -1) printf("Not connected\n");
            else printf("%d\n", ans[i]);
        }
    }
    return 0;
}
