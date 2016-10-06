#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 3e3 + 111;
int mp[100][100];
struct Edge{
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w):from(u), to(v), cap(c), flow(f), cost(w){}
};

struct MCMF{
    int n, m;
    vector<Edge> edges;
    vector<int> G[MAXN];
    int inq[MAXN];
    int d[MAXN];
    int p[MAXN];
    int a[MAXN];

    void init()
    {
        this->n = n;
        for (int i = 0; i < n; ++i) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap, int cost)
    {
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BellmanFord(int s, int t, int &flow, ll &cost)
    {
        memset(d, 0x7f, sizeof d);
        memset(inq, 0, sizeof inq);
        d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;

        queue<int> Q;
        Q.push(s);
        while (!Q.empty())
        {
            int u = Q.front(); Q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); ++i)
            {
                Edge &e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
                {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u],e.cap - e.flow);
                    if (!inq[e.to]) {Q.push(e.to); inq[e.to] = 1;}
                }
            }
        }
        if (d[t] == INF) return 0;
        flow += a[t];
        cost += (ll)d[t] * (ll)a[t];
        for (int u = t; u != s; u = edges[p[u]].from)
        {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
        }
        return 1;
    }

    int MincostMaxflow(int s, int t, ll &cost)
    {
        int flow = 0; cost = 0;
        while(BellmanFord(s, t, flow, cost));
        return flow;
    }
};

int main()
{
    int kase, m, n; scanf("%d",&kase);
    while (kase --)
    {
        MCMF ans;
        scanf("%d%d", &n, &m);
        int t = n * m + n + 1;
        for (int i = 1; i <= n; ++i) ans.AddEdge(0, i, 1, 0);
        for (int i = n + 1; i <= n * m + n; ++i) ans.AddEdge(i, t, 1, 0);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                scanf("%d", &mp[i][j]);
            }
        for (int i = 1; i <= n; ++i) //every item
        {
            for (int j = 1; j <= m; ++j)
                for (int k = 1; k <= n; ++k)
                {
                    ans.AddEdge(i, n * j + k, 1, k * mp[i][j]);
                }
        }
        ll cost = 0;
        ans.MincostMaxflow(0,t,cost);
        printf("%.6f\n", (double)cost/n);
    }
    return 0;
}

