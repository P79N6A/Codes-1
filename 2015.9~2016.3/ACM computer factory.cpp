#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int INF = 0x7f7f7f7f, MAXN = 1e3;

struct Edge{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f):from(u), to(v), cap(c), flow(f){}
};

struct EdmondsKarp{
    int n, m;
    vector<Edge> edges;  //边数的两遍
    vector<int> G[MAXN]; //G[i][j]表示节点i的第j条边
    int a[MAXN]; //当起点到i的可该变量
    int p[MAXN]; //最短路树上p的入弧编号

    void init(int n)
    {
        for (int i = 0; i < n; ++i) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap)
    {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m += 2;
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

struct Ma
{
    int in[15], out[15], w;
}ma[60];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, p;
    while (~scanf("%d%d", &p, &n))
    {
        EdmondsKarp ans;
        ans.m = 0;
        int st = 0, ed = 2 * n + 1;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &ma[i].w);
            bool flag = 1;
            for (int j = 0; j < p; ++j)
            {
                scanf("%d", &ma[i].in[j]);
                if (ma[i].in[j] == 1) flag = 0;
            }
            if (flag) ans.AddEdge(st, i, INF); // 超级源点与p全为0的点
            flag = 1;
            for (int j = 0; j < p; ++j)
            {
                scanf("%d", &ma[i].out[j]);
                if (ma[i].out[j] == 0) flag = 0;
            }
            if (flag) ans.AddEdge(n + i, ed, INF); // 超级汇点与p全为1的点
        }

        for (int i = 1; i <= n; ++i)
        {
            ans.AddEdge(i, n + i, ma[i].w);
            for (int j = 1; j <= n; ++j)
            {
                if (i == j) continue;
                bool flag = 1;
                for (int k = 0; k < p; ++k)
                {
                    if (ma[j].in[k] != 2 && ma[i].out[k] != ma[j].in[k])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag) ans.AddEdge(n + i, j, INF); // 点与点间
            }
        }
        int cnt = 0;
        int flow = ans.Maxflow(st, ed);
        int path[1000][5];

        // 撇去原点，真正意义上的起点是m + 1开始的。
        for (int i = n + 1; i < ed; i++)
        for (int j = 0; j < ans.G[i].size(); j++)
        {
            int v = ans.G[i][j];
            Edge &e = ans.edges[v];

            if (e.flow > 0 && e.to <= n) {
                path[cnt][0] = i - n;
                path[cnt][1] = e.to;
                path[cnt][2] = e.flow;
                cnt++;
            }
        }

        printf("%d %d\n", flow, cnt);
        for (int i = 0; i < cnt; i++)
        printf("%d %d %d\n", path[i][0], path[i][1], path[i][2]);
    }
    return 0;
}
