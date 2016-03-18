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
const int MAXN = 511;

struct edge {int to, cap, rev;};

vector<edge> G[MAXN];
int level[MAXN], iter[MAXN];

void add_edge(int u, int v, int cap) {
    G[u].push_back((edge){v, cap, G[v].size()});
    G[v].push_back((edge){u, 0, G[u].size() - 1});
}

void bfs(int s) {
    memset(level, -1, sizeof level);
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while (que.size()) {
        int v = que.front(); que.pop();
        for (int i = 0; i < G[v].size(); ++i) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); ++i) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (1) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof iter);
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, f, d, a, b, x;
    scanf("%d%d%d", &n, &f, &d);
    int s = 0, t = f + 2 * n + d + 1;
    for (int i = 1; i <= f; ++i) add_edge(s, i, 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a, &b);
        for (int j = 0; j < a; ++j) {
            scanf("%d", &x);
            add_edge(x, f + i, 1);
        }
        for (int j = 0; j < b; ++j) {
            scanf("%d", &x);
            add_edge(f + n + i, f + n + n + x, 1);
        }
    }
    for (int i = 1; i <= n; ++i) add_edge(f + i, f + n + i, 1);
    for (int i = 1; i <= d; ++i) add_edge(f + n + n + i, t, 1);

    printf("%d\n", max_flow(s, t));
    return 0;
}
