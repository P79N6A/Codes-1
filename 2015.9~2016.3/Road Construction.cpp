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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int N = 1e4 + 111;
const int M = 4e4 + 111;

struct E {
    int nxt, to, d, c;
}edge[M];
int dis[N], cost[N], head[N], cnt;

void add_edge(int u, int v, int d, int c) {
    edge[cnt].to = v;
    edge[cnt].c = c;
    edge[cnt].d = d;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dijkstra(int s) {
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(dis[s], s));
    while (pq.size()) {
        pii cur = pq.top(); pq.pop();
        int u = cur.second, dist = cur.first;
        if (dis[u] < dist) continue;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].d) {
                dis[v] = dis[u] + edge[i].d;
                pq.push(pii(dis[v], v));
                cost[v] = edge[i].c;
            }
            else if (dis[v] == dis[u] + edge[i].d) {
                if (cost[v] > edge[i].c) {
                    cost[v] = edge[i].c;
                }
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d%d", &n, &m) && (n | m)) {
        cnt = 0;
        int u, v, d, c;
        for(int i = 1; i <= n; ++i) {
            head[i] = -1;
            cost[i] = dis[i] = INF;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d%d", &u, &v, &d, &c);
            add_edge(u, v, d, c);
            add_edge(v, u, d, c);
        }

        dijkstra(1);
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (cost[i] != INF) sum += cost[i];
        }

        printf("%d\n", sum);
    }
    return 0;
}
