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
const int INF = 0x3f3f3f3f, MAXN = 2e3 + 111;
struct Edge{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f):from(u), to(v), cap(c), flow(f){}
};

struct EdmondsKarp{
    int n, m;
    vector<Edge> edges;
    vector<int> G[20];
    int a[20];
    int p[20];

    void init(int n)
    {
        for (int i = 0; i < n; ++i) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap)
    {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    int Maxflow(int s, int t)
    {
        int flow = 0;
        while(1)
        {
            memset(a, 0, sizeof a);
            queue<int> Q;
            Q.push(s);
            a[s] = INF;
            while(!Q.empty())
            {
                int x = Q.front(); Q.pop();
                for (int i = 0; i < G[x].size(); ++i)
                {
                    Edge &e = edges[G[x][i]];
                    if (!a[e.to] && e.cap > e.flow)
                    {
                        p[e.to] = G[x][i];
                        a[e.to] = min(a[x], e.cap - e.flow);
                        Q.push(e.to);
                    }
                }
                if (a[t]) break;
            }
            if(!a[t]) break;
            for (int u = t; u != s; u = edges[p[u]].from)
            {
                edges[p[u]].flow += a[t];
                edges[p[u]^1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
};

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, t;
    for (int kase = scanf("%d", &t); kase <= t; ++kase)
    {
        scanf("%d%d", &n, &m);
        int a, b, c;
        EdmondsKarp ans;
        for(int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &a, &b, &c);
            ans.AddEdge(a, b, c);
        }
        printf("Case %d: %d\n", kase, ans.Maxflow(1, n));
    }
    return 0;
}

