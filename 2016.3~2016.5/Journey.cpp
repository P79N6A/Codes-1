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

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

struct Edge {
    int next, to, w;
}edge[MAXN * 2];

struct Query {
    int next, to, ans;
}query[MAXN * 10];

int head[MAXN], qhead[MAXN], tol, qtol;
int dep[MAXN], par[MAXN];
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

void qaddedge(int u, int v) {
    query[qtol].to = v;
    query[qtol].next = qhead[u];
    qhead[u] = qtol++;
    query[qtol].to = u;
    query[qtol].next = qhead[v];
    qhead[v] = qtol++;
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
            query[i^1].ans = query[i].ans = dep[u] + dep[v] - 2 * dep[par[find(v)]];
        }
    }
}

int main()
{
    int t; scanf("%d", &t);
    int kase = 0;
    while (t --) {
        init();
        int n, m;
        scanf("%d%d", &n, &m);
        int u, v, w;
        int u1, v1, w1;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
        }
        scanf("%d%d%d", &u1, &v1, &w1);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            qaddedge(u, v);
            qaddedge(u, u1);
            qaddedge(v, v1);
            qaddedge(u, v1);
            qaddedge(v, u1);
        }

        tarjan(1, 0);

        printf("Case #%d:\n", ++kase);
        for (int i = 0; i < qtol; i += 10) {
            int disuv = query[i].ans;
            int disuu1 = query[i + 2].ans;
            int disvv1 = query[i + 4].ans;
            int disuv1 = query[i + 6].ans;
            int disvu1 = query[i + 8].ans;
            int mi = min(disuu1 + disvv1 + w1, disuv1 + w1 + disvu1);
            printf("%d\n", disuv - min(disuv, mi));
        }
    }
    return 0;
}
