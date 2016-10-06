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
#define pii pair<ll, int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const ll INF = 1e13;
const int MAXN = 2e5 + 111;
const int N = 1e4 + 111;

struct E {
    int to, nxt;
    ll w;
}edge[MAXN];

int cnt, head[MAXN], pre[MAXN];
ll dis[MAXN];

void add_edge(int u, int v, int w) {
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dijkstra(int s) {
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(dis[s], s));
    while (pq.size()) {
        pii cur = pq.top(); pq.pop();
        int u = cur.second;
        ll dist = cur.first;
        if (dis[u] < dist) continue;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w && edge[i].w > pre[u]) {
                pre[v] = edge[i].w;
                dis[v] = dis[u] + edge[i].w;
                pq.push(pii(dis[v], v));
            }
            else if (dis[v] == dis[u] + edge[i].w && pre[v] > edge[i].w) {
                pre[v] = edge[i].w;
                pq.push(pii(dis[v], v));
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, u, v, w, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {head[i] = -1; dis[i] = INF; pre[i] = 0;}
        cnt = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }

        dijkstra(1);

        if (dis[n] == INF) printf("No answer\n");
        else printf("%lld\n", dis[n]);
    }
    return 0;
}
