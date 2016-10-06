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

const int INF = 0x3f3f3f3f;
const int MAXM = 1e5 + 111;
const int MAXN = 1e4 + 111;

struct Edge {
    int to, next, w;
}edge[MAXM * 2];
int head[MAXN], dis[MAXN], tol = 0;
bool in[MAXN];
int n, h, m, ans;

vector<int> G[MAXN];
vector<int> hot;

void init() {
    tol = 0;
    hot.clear();
    memset(head, -1, sizeof head);
    memset(in, 0, sizeof in);
    for (int i = 1; i <= n; ++i) G[i].clear();
}

void addedge(int u, int v, int w) {
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].w = w;
    edge[tol].next = head[v];
    head[v] = tol++;
}

void spfa(int s) {
    queue<int> q;
    q.push(s);
    in[s] = 1;
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w) {
                dis[v] = dis[u] + edge[i].w;
                if (!in[v]) {
                    q.push(v);
                    in[v] = 1;
                }
            }
        }
    }

    if (s == 1 && dis[n] <= 600) G[s].push_back(n), G[n].push_back(s);
    if (s != 1 && s != n) {
        if (dis[1] <= 600) G[s].push_back(1);
        if (dis[n] <= 600) G[s].push_back(n);
    }
    for (int i = 0; i < hot.size(); ++i) {
        if (hot[i] == s) continue;
        if (dis[hot[i]] <= 600) {
            G[s].push_back(hot[i]);
        }
    }
}

bool okspfa(int s) {
    queue<int> q;
    q.push(s);
    in[s] = 1;
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                if (!in[v]) {
                    q.push(v);
                    in[v] = 1;
                }
            }
        }
    }
    ans = dis[n];
    return (ans != INF);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        init();
        scanf("%d", &h);
        int x;
        for (int i = 0; i < h; ++i) {
            scanf("%d", &x);
            hot.push_back(x);
        }
        scanf("%d", &m);
        int u, v, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
        }

        spfa(1);
        for (int i = 0; i < hot.size(); ++i) {
            spfa(hot[i]);
        }
        spfa(n);

        if (okspfa(1)) {
            printf("%d\n", ans - 1);
        }
        else printf("-1\n");
    }
    return 0;
}
