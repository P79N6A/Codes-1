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
const int MAXN = 1e5 + 111;
const int MAXM = 2e5 + 111;

struct Edge {
    int to, next;
}edge[MAXM];
int head[MAXN], tol;

struct Query {
    int to, next, id;
}query[MAXM];
int qead[MAXN], qol, par[MAXN], vis[MAXN], dp[MAXN];
bool ok[MAXN];

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].next = head[u];
    head[u] = tol++;
}

void addquery(int u, int v, int id) {
    query[qol].to = v;
    query[qol].next = qead[u];
    query[qol].id = id;
    qead[u] = qol++;
}

void init() {
    memset(head, -1, sizeof head);
    memset(qead, -1, sizeof qead);
    memset(vis, 0, sizeof vis);
    memset(dp, 0, sizeof dp);
    memset(ok, 0, sizeof ok);
    tol = qol = 0;
}

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

void tarjan(int u) {
    par[u] = u;
    vis[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (!vis[v]) {
            tarjan(v);
            par[v] = u;
        }
    }
    for (int i = qead[u]; ~i; i = query[i].next) {
        int v = query[i].to;
        if (vis[v] && !ok[query[i].id]) {
            ok[query[i].id] = 1;
            dp[find(v)] -= 2;
            ++dp[u], ++dp[v];
        }
    }
}

void DP(int u) {
    vis[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (!vis[v]) {
            DP(v);
            dp[u] += dp[v];
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, u, v;
    while (~scanf("%d%d", &n, &m)) {
        init();
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            addquery(u, v, i);
            addquery(v, u, i);
        }

        tarjan(1);

        memset(vis, 0, sizeof vis);
        DP(1);

        int ret = 0;
        for (int i = 2; i <= n; ++i) {
            if (dp[i] == 0) ret += m;
            else if (dp[i] == 1) ++ret;
        }
        printf("%d\n", ret);
    }
    return 0;
}
