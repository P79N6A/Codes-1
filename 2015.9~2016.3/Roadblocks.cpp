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
const int N = 5e3 + 111;
const int M = 2e5 + 111;

struct E {
    int nxt, to, w;
}edge[M];
int dis1[N], dis2[N], head[M], cnt; // dis1:最短 dis2:次短

void add_edge(int u, int v, int w) {
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dijkstra(int s) {
    dis1[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(dis1[s], s));
    while (pq.size()) {
        pii temp = pq.top(); pq.pop();
        int u = temp.second, d = temp.first;
        if (dis2[u] < d) continue;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            int temp = d + edge[i].w; // 由于维护的是最短次短两者，所以我们使用d来更新，d随着弹出点的定义不同而不同
            if (temp < dis1[v]) { // 最短路更新，次短路必定更新
                dis2[v] = dis1[v];
                dis1[v] = temp;
                pq.push(pii(dis2[v], v));
                pq.push(pii(dis1[v], v));
            }
            else if (dis1[v] < temp && temp < dis2[v]) { // 否则，在当前值在两者之间时更新
                dis2[v] = temp;
                pq.push(pii(dis2[v], v));
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    cnt = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(int) * (n + 5));
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    for (int i = 1; i <= n; ++i) dis1[i] = dis2[i] = INF;
    dijkstra(1);

    printf("%d\n", dis2[n]);
    return 0;
}
