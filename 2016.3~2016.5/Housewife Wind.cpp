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
using namespace std;

const int MAXN = 1e5 + 111;

struct Edge {
    int to, id, w, next;
}edge[MAXN * 2];
int head[MAXN], tol;

void addedge(int u, int v, int id, int w) {
    edge[tol].to = v; edge[tol].w = w; edge[tol].id = id;
    edge[tol].next = head[u]; head[u] = tol++;
}

int s, bitn;
int w[MAXN];
vector<Edge> G[MAXN];

int id[MAXN], es[MAXN * 2], dep[MAXN * 2], vs[MAXN * 2];
int bit[MAXN * 2], dp[MAXN * 2][20];

void add(int i, int x) {
    while (i <= bitn) {
        bit[i] += x;
        i += lowbit(i);
    }
}

int sum(int i) {
    int ret = 0;
    while (i > 0) {
        ret += bit[i];
        i -= lowbit(i);
    }
    return ret;
}

void dfs(int u, int p, int sum, int &k) {
    id[u] = k;
    vs[k] = u;
    dep[k++] = sum;
    for (int i = head[u]; ~i; i = edge[i].next) {
        Edge &e = edge[i];
        if (e.to != p) {
            add(k, e.w);
            es[e.id * 2] = k;
            dfs(e.to, u, sum + e.w, k);
            vs[k] = u;
            dep[k++] = sum;
            add(k, -e.w);
            es[e.id * 2 + 1] = k;
        }
    }
}

int my_min(int a, int b) {
    return dep[a] <= dep[b] ? a : b;
}

void init_rmq(int n) {
    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int j = 1; j < 20; ++j) {
        for (int i = 0; i + (1 << j) - 1 <= n; ++i) {
            dp[i][j] = my_min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}

void init(int n) {
    bitn = n * 2 - 1;
    memset(bit, 0, sizeof bit);
    int k = 0;
    dfs(0, -1, 0, k);
    init_rmq(2 * n - 1);
}

int query(int l, int r) {
    int k = log2(r - l + 1);
    return my_min(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int lca(int a, int b) {
    if (id[a] > id[b]) swap(a, b);
    return vs[query(id[a], id[b])];
}

int main()
{
    int n, q, u, v;
    while (~scanf("%d%d%d", &n, &q, &s)) {
        for (int i = 0; i < n; ++i) G[i].clear(), head[i] = -1;
        tol = 0;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d%d", &u, &v, &w[i]);
            --u, --v;
            addedge(u, v, i, w[i]);
            addedge(v, u, i, w[i]);
        }

        init(n);

        int op, a, b;
        --s;
        for (int i = 0; i < q; ++i) {
            scanf("%d%d", &op, &a);
            --a;
            if (op == 0) {
                int p = lca(s, a);
                printf("%d\n", sum(id[s]) + sum(id[a]) - 2 * sum(id[p]));
                s = a;
            }
            else {
                scanf("%d", &b);
                add(es[2 * a], b - w[a]);
                add(es[2 * a + 1], w[a] - b);
                w[a] = b;
            }
        }
    }
    return 0;
}
