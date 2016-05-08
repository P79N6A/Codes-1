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
const int MAXN = 1e3 + 111;
const int MAXM = 2e4 + 111;

struct Edge {
    int to, nxt, w;
}edge[MAXM];
int tol, head[MAXN];

void init() {
    tol = 0;
    memset(head, -1, sizeof head);
}

void addedge(int u, int v, int w) {
    edge[tol].to = v;
    edge[tol].w = w;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

struct P {
    int u, dis, flag;
    P(int a, int b, int c):u(a), dis(b), flag(c){}
    bool operator < (const P& t) const {
        return dis > t.dis;
    }
};
int dis[MAXN][2], path[MAXN][2], vis[MAXN][2];

void dijkstra(int s, int t) {
    memset(dis, 0x3f, sizeof dis);
    memset(path, 0, sizeof path);
    memset(vis, 0, sizeof vis);
    dis[s][0] = 0;
    path[s][0] = 1;
    priority_queue<P> pq;
    pq.push(P(s, 0, 0));
    while (pq.size()) {
        P cur = pq.top(); pq.pop();
        int u = cur.u, cdis = cur.dis, flag = cur.flag;
        if (vis[u][flag]) continue;
        vis[u][flag] = 1;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (!vis[v][0] && dis[v][0] > cdis + edge[i].w) {
                if (dis[v][0] != INF) {
                    pq.push(P(v, dis[v][0], 1));
                    dis[v][1] = dis[v][0];
                    path[v][1] = path[v][0];
                }
                dis[v][0] = cdis + edge[i].w;
                path[v][0] = path[u][flag];
                pq.push(P(v, dis[v][0], 0));
            }
            else if (!vis[v][0] && dis[v][0] == cdis + edge[i].w) {
                path[v][0] += path[u][flag];
            }
            else if (!vis[v][1] && dis[v][1] > cdis + edge[i].w) {
                dis[v][1] = cdis + edge[i].w;
                path[v][1] = path[u][flag];
                pq.push(P(v, dis[v][1], 1));
            }
            else if (!vis[v][1] && dis[v][1] == cdis + edge[i].w) {
                path[v][1] += path[u][flag];
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, t, u, v, w; scanf("%d", &t);
    while (t --) {
        init();
        scanf("%d%d", &n, &m);
        while (m --) {
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
        }
        int S, T;
        scanf("%d%d", &S, &T);
        dijkstra(S, T);
        if (dis[T][1] - 1 == dis[T][0]) printf("%d\n", path[T][0] + path[T][1]);
        else printf("%d\n", path[T][0]);
    }
    return 0;
}
