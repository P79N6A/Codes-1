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
const int MAXN = 4e4 + 111;
const int MAXM = 8e4 + 222;

struct Edge {
    int to, w, next;
}edge[MAXM];
int head[MAXN], tol;

struct Query {
    int to, id, next;
}query[MAXM];
int qhead[MAXN], qtol, ans[MAXN], dis[MAXN];

bool vis[MAXN];

int par[MAXN];

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

void init() {
    tol = qtol = 0;
    memset(head, -1, sizeof head);
    memset(qhead, -1, sizeof qhead);
}

void addedge(int u, int v, int w) {
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].next = head[u];
    head[u] = tol++;
}

void qaddedge(int u, int v, int id) {
    query[qtol].to = v;
    query[qtol].id = id;
    query[qtol].next = qhead[u];
    qhead[u] = qtol++;
}

void dfs(int u, int sum) {
    dis[u] = sum;
    vis[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (!vis[v]) {
            dfs(v, sum + edge[i].w);
        }
    }
}

void tarjan(int u) {
    par[u] = u;
    vis[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (vis[v]) continue;
        tarjan(v);
        par[v] = u;
    }
    for (int i = qhead[u]; ~i; i = query[i].next) {
        int v = query[i].to;
        if (vis[v]) {
            ans[query[i].id] = dis[u] + dis[v] - 2 * dis[find(par[v])];
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        int u, v, w, k;
        init();
        char s[2];
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d%s", &u, &v, &w, s);
            addedge(u, v, w);
            addedge(v, u, w);
        }
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &u, &v);
            qaddedge(u, v, i);
            qaddedge(v, u, i);
        }

        memset(vis, 0, sizeof vis);
        dfs(1, 0);
        memset(vis, 0, sizeof vis);
        tarjan(1);

        for (int i = 0; i < k; ++i) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
