#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;

struct Edge{
    int u, v, w;
}edge[20100];
int newid[MAXN], pre[MAXN], vis[MAXN], ecnt, in[MAXN], minRt;

void add_edge(int u, int v, int w)
{
    edge[ecnt].u = u;
    edge[ecnt].v = v;
    edge[ecnt++].w = w;
}

int zhuLiu(int rt, int V)
{
    int ret = 0;
    while (1)
    {
        for (int i = 0; i <= V; ++i) in[i] = INF;
        for (int i = 0; i < ecnt; ++i)
        {
            int u = edge[i].u, v = edge[i].v;
            if (u != v && in[v] > edge[i].w)
            {
                in[v] = edge[i].w, pre[v] = u;
                if (u == rt) minRt = i; // 因为在整个过程中，结点编号会变，但是边编号不会变。
            }
        }
        // 本题有了虚边之后最小树形图一定存在，所以就不判断不存在的情况了XD

        int cnt = 0;
        memset(newid, -1, sizeof newid);
        memset(vis, -1, sizeof vis);
        in[rt] = 0;
        for (int i = 0; i <= V; ++i)
        {
            ret += in[i];
            int v = i;
            while (vis[v] != i && newid[v] == -1 && v != rt)
            {
                vis[v] = i;
                v = pre[v];
            }
            if (v != rt && newid[v] == -1)
            {
                for (int u = pre[v]; u != v; u = pre[u]) newid[u] = cnt;
                newid[v] = cnt++;
            }
        }

        if (cnt == 0) break;
        for (int i = 0; i <= V; ++i)
            if (newid[i] == -1) newid[i] = cnt++;
        for (int i = 0; i < ecnt; ++i)
        {
            int u = edge[i].u, v = edge[i].v;
            edge[i].u = newid[u];
            edge[i].v = newid[v];
            if (newid[u] != newid[v]) edge[i].w -= in[v];
        }

        V = cnt - 1;
        rt = newid[rt];
    }
    return ret;
}

int main()
{
    int n, m, u, v, w;
    while (~scanf("%d%d", &n, &m))
    {
        ecnt = 0;
        int mxVal = 0;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
            mxVal += w;
        }
        ++mxVal;
        // 在原图建立之后再对虚源点连边，保证遍历从小开始，同时保证虚边都在m条边之后建立
        for (int i = 0; i < n; ++i) add_edge(n, i, mxVal);
        int ans = zhuLiu(n, n);
        if (ans >= 2 * mxVal) printf("impossible\n\n");
        else
        {
            printf("%d %d\n\n", ans - mxVal, minRt - m);
        }
    }
    return 0;
}
