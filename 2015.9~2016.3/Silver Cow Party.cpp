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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int M = 1e5 + 111;
const int N = 1e3 + 111;

int n, cnt[2], head[2][N], dis[2][N];
struct E {
    int to, nxt, w;
}edge[2][M];

void add_edge(int u, int v, int w, int st) {
    edge[st][cnt[st]].to = v;
    edge[st][cnt[st]].w = w;
    edge[st][cnt[st]].nxt = head[st][u];
    head[st][u] = cnt[st]++;
}

void dijkstra(int s, int sta) {
    for (int i = 1; i <= n; ++i) dis[sta][i] = INF;
    dis[sta][s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(dis[sta][s], s));
    while (pq.size()) {
        pii cur = pq.top(); pq.pop();
        int u = cur.second, d = cur.first;
        if (dis[sta][u] < d) continue;
        for (int i = head[sta][u]; ~i; i = edge[sta][i].nxt){
            int v = edge[sta][i].to, w = edge[sta][i].w;
            if (dis[sta][v] > dis[sta][u] + w) {
                dis[sta][v] = dis[sta][u] + w;
                pq.push(pii(dis[sta][v], v));
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m, x, u, v, w;
    cnt[0] = cnt[1] = 0;
    memset(head, -1, sizeof head);
    scanf("%d%d%d", &n, &m, &x);
    while (m --) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w, 0);
        add_edge(v, u, w, 1);
    }

    dijkstra(x, 0);
    dijkstra(x, 1);

    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dis[0][i] + dis[1][i]);
    printf("%d\n", ans);
    return 0;
}
