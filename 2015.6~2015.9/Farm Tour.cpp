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
const int INF = 0x7f7f7f7f, MAXN = 1e4 + 111;
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
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        int a, b, c;
        MCMF ans;
        ans.AddEdge(0, 1, 2, 0);
        ans.AddEdge(n, n + 1, 2, 0);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &a, &b, &c);
            ans.AddEdge(a,b,1,c);
            ans.AddEdge(b,a,1,c);
        }
        ll cost = 0;
        ans.MincostMaxflow(0, n + 1, cost);
        cout << cost << '\n';
    }
    return 0;
}
