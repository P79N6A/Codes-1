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
const int MAXN = 111;

int cnt, mx, head[MAXN], dis[MAXN];
bool has[MAXN];
struct E {
    int to, nxt, w;
}edge[MAXN];

void dijkstra(int s) {
    for (int i = 0; i <= mx; ++i) {
        dis[i] = INF;
    }
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(dis[s], s));
    while (pq.size()) {
        pii cur = pq.top(); pq.pop();
        int u = cur.second, d = cur.first;
        if (dis[u] < d) continue;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w) {
                dis[v] = dis[u] + edge[i].w;
                pq.push(pii(dis[v], v));
            }
        }
    }
}

void add(int u, int v, int w){
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n) && n) {
        cnt = 0;
        mx = 0;
        int u, v, w;
        memset(head, -1, sizeof head);
        memset(has, 0, sizeof has);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            mx = max(max(u, v), mx);
            has[v] = has[u] = 1;
            add(u, v, w);
            add(v, u, w);
        }

        int ans = INF, anssum = INF;
        for (int i = 0; i <= mx; ++i) {
            if (!has[i]) continue;
            dijkstra(i);
            int sum = 0;
            for (int j = 0; j <= mx; ++j) {
                if (!has[j]) continue;
                sum += dis[j];
            }
            if (sum < anssum) {
                anssum = sum;
                ans = i;
            }
        }
        printf("%d %d\n", ans, anssum);
    }
    return 0;
}
