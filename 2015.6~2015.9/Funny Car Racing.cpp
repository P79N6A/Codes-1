#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 311;
int n, m, s, t;
bool vis[MAXN];
ll d[MAXN];
struct E{
    int to, a, b, t;
};
vector<E> g[MAXN];
typedef pair<ll, int> p;

ll dijkstra()
{
    memset(d, 0x3f, sizeof d);
    memset(vis, 0, sizeof vis);
    priority_queue<p, vector<p>, greater<p> > pq;
    d[s] = 0;
    pq.push(p(0, s));
    while(!pq.empty())
    {
        int u = pq.top().second; pq.pop();
        vis[u] = 1;
        for (int i = 0; i < g[u].size(); ++i)
        {
            E &e = g[u][i];
            if (e.a < e.t) continue;
            int left = d[u] % (e.a + e.b), cost;
            if (left < e.a && e.a - left >= e.t) cost = e.t;
            else cost = e.a + e.b - left + e.t;//时间不够就得等
            if (!vis[e.to] && d[e.to] > d[u] + cost)
            {
                d[e.to] = d[u] + cost;
                pq.push({d[e.to], e.to});
            }
        }
    }
    return d[t];
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase = 0;
    while (~scanf("%d%d%d%d", &n, &m, &s, &t))
    {
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 0; i < m; ++i)
        {
            int u,v,a,b,t;
            scanf("%d%d%d%d%d", &u, &v, &a, &b, &t);
            g[u].push_back({v,a,b,t});
        }
        printf("Case %d: %d\n", ++kase, dijkstra());
    }
    return 0;
}
