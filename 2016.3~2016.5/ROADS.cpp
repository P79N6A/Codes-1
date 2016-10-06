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

const int INF = 0x3f3f3f3f;
const int MAXN = 1e4 + 111;

struct Edge {
    int to, next, l, t;
}edge[MAXN];

int head[111], tol = 0, n, k, ans, cost[111], dis[111];
bool in[111];

void add_edge(int u, int v, int l, int t) {
    edge[tol].to = v;
    edge[tol].l = l;
    edge[tol].t = t;
    edge[tol].next = head[u];
    head[u] = tol++;
}

bool spfa() {
    memset(in, 0, sizeof in);
    memset(cost, 0x3f, sizeof cost);
    cost[1] = 0;
    dis[1] = 0;
    in[1] = 1;
    queue<int> q;
    q.push(1);
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            if (cost[v] > cost[u] + edge[i].t) {
                cost[v] = cost[u] + edge[i].t;
                dis[v] = dis[u] + edge[i].l;
                if (!in[v]) {
                    in[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return (cost[n] <= k);
}

void dfs(int x, int len, int cos) {
    if (cos > k || len >= ans) return;
    if (x == n) {
        ans = len;
        return;
    }
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        dfs(v, len + edge[i].l, cos + edge[i].t);
    }
}

int main()
{
    int r, u, v, l, t;
    scanf("%d%d%d", &k, &n, &r);
    memset(head, -1, sizeof head);
    for (int i = 0; i < r; ++i) {
        scanf("%d%d%d%d", &u, &v, &l, &t);
        add_edge(u, v, l, t);
    }

    if (!spfa()) printf("-1\n");
    else {
        ans = dis[n];
        dfs(1, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
